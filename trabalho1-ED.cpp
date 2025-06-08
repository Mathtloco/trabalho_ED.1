#include <bits/stdc++.h> 

using namespace std;     

// Define um tipo para facilitar a digitação da matriz
typedef vector<vector<double>> matrix_t;

class EDL {
private:
    matrix_t mat;
    int R, C;

public:
    // Construtor
    EDL(const matrix_t& _mat) : mat(_mat) {
        if (mat.empty()) {
            R = C = 0;
        } else {
            R = mat.size();
            C = mat[0].size();
            
            for (const auto& row : mat) {
                if (row.size() != static_cast<size_t>(C)) {
                    throw invalid_argument("Linhas de tamanho diferente.");
                }
            }
        }
    }


    virtual ~EDL() = default;

    // Sobrecarga do operador de inserção (<<) para facilitar a impressão
    friend ostream& operator<<(ostream& os, const EDL& obj) {
        for (const auto& row : obj.mat) {
            os << "|";
            for (double x : row) {
                os << setw(5) << fixed << setprecision(1) << x;
            }
            os << "|\n";
        }
        return os;
    }


    virtual EDL operator+(const EDL& other) const {
        if (R != other.R || C != other.C) {
            throw invalid_argument("Dimensoes incompativeis para soma.");
        }
        matrix_t res(R, vector<double>(C));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                res[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return EDL(res);
    }


    virtual EDL operator-(const EDL& other) const {
        if (R != other.R || C != other.C) {
            throw invalid_argument("Dimensoes incompativeis para subtracao.");
        }
        matrix_t res(R, vector<double>(C));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                res[i][j] = mat[i][j] - other.mat[i][j];
            }
        }
        return EDL(res);
    }


    virtual EDL operator*(const EDL& other) const {
        if (C != other.R) {
            throw invalid_argument("Dimensoes incompativeis para multiplicacao.");
        }
        matrix_t res(R, vector<double>(other.C, 0.0));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < other.C; ++j) {
                for (int k = 0; k < C; ++k) {
                    res[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return EDL(res);
    }

  
    EDL operator*(double s) const {
        matrix_t res(R, vector<double>(C));
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                res[i][j] = mat[i][j] * s;
            }
        }
        return EDL(res);
    }


    friend EDL operator*(double s, const EDL& m) {
        return m * s;
    }

    // Método to_square()
    virtual EDL to_square() const {
        int sz = max(R, C);
        matrix_t sq_mat(sz, vector<double>(sz, 0.0));

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                sq_mat[i][j] = mat[i][j];
            }
        }
        return EDL(sq_mat);
    }

    int getR() const { return R; }
    int getC() const { return C; }
    const matrix_t& getMat() const { return mat; }
};

// --- Função main para teste e exemplo de uso ---
int main() {
    // Exemplo de criação de matrizes
    matrix_t mat1_data = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0}
    };
    EDL mat1(mat1_data);
    cout << "Matriz 1:\n" << mat1 << endl;

    matrix_t mat2_data = {
        {7.0, 8.0, 9.0},
        {10.0, 11.0, 12.0}
    };
    EDL mat2(mat2_data);
    cout << "Matriz 2:\n" << mat2 << endl;

    // Testando Soma
    try {
        EDL sum_mat = mat1 + mat2;
        cout << "Soma da Matriz 1 e Matriz 2:\n" << sum_mat << endl;
    } catch (const invalid_argument& e) {
        cerr << "Erro na soma: " << e.what() << endl;
    }

    // Testando Subtração
    try {
        EDL sub_mat = mat1 - mat2;
        cout << "Subtração da Matriz 1 e Matriz 2:\n" << sub_mat << endl;
    } catch (const invalid_argument& e) {
        cerr << "Erro na subtração: " << e.what() << endl;
    }

    // Testando Multiplicação por Escalar
    EDL scaled_mat = mat1 * 2.5;
    cout << "Matriz 1 multiplicada por 2.5:\n" << scaled_mat << endl;

    EDL rscaled_mat = 3.0 * mat2;
    cout << "Matriz 2 multiplicada por 3.0 (escalar na frente):\n" << rscaled_mat << endl;

    // Testando Multiplicação de Matrizes
    matrix_t mat3_data = {
        {1.0, 2.0},
        {3.0, 4.0},
        {5.0, 6.0}
    };
    EDL mat3(mat3_data);
    cout << "Matriz 3:\n" << mat3 << endl;

    try {
        EDL mul_mat = mat1 * mat3;
        cout << "Multiplicação da Matriz 1 e Matriz 3:\n" << mul_mat << endl;
    } catch (const invalid_argument& e) {
        cerr << "Erro na multiplicação: " << e.what() << endl;
    }

    // Testando to_square
    matrix_t rect_mat_data = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0}
    };
    EDL rect_mat(rect_mat_data);
    cout << "Matriz Retangular Original:\n" << rect_mat << endl;
    EDL square_version = rect_mat.to_square();
    cout << "Versão Quadrada da Matriz Retangular:\n" << square_version << endl;
    cout << "Dim da versão quadrada: " << square_version.getR() << "x" << square_version.getC() << endl;

    // Testando construtor com matriz vazia ou irregular
    try {
        matrix_t empty_mat_data = {};
        EDL empty_mat(empty_mat_data);
        cout << "Matriz vazia criada:\n" << empty_mat << endl;
    } catch (const invalid_argument& e) {
        cerr << "Erro ao criar matriz vazia: " << e.what() << endl;
    }

    try {
        matrix_t irregular_mat_data = {
            {1.0, 2.0},
            {3.0}
        };
        EDL irregular_mat(irregular_mat_data);
        cout << "Matriz irregular criada:\n" << irregular_mat << endl;
    } catch (const invalid_argument& e) {
        cerr << "Erro ao criar matriz irregular: " << e.what() << endl;
    }

    return 0;
}