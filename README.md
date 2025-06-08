# trabalho_ED.1
Trabalho sobre hierarquia de classes matrizes
# Trabalhos de Estrutura de Dados - Operações com Matrizes

Este repositório contém a implementação de uma Calculadora de Matrizes utilizando o Paradigma de Programação Orientada a Objetos (POO), conforme especificado no Trabalho 1 de Estrutura de Dados. O projeto demonstra operações básicas com matrizes e uma hierarquia de classes para diferentes tipos de matrizes.

## Estrutura do Projeto

O repositório está organizado nas seguintes pastas:

* `Python/`: Contém a implementação original da calculadora de matrizes em Python, desenvolvida em um Jupyter Notebook.
* `C++/`: Contém a tradução da classe base `EDL` para C++, demonstrando a aplicação dos conceitos de POO em uma linguagem compilada.

## Implementação em Python

### `Python/trabalho1-ED.ipynb`

Este arquivo é um Jupyter Notebook que implementa a calculadora de matrizes. Ele define as seguintes classes:

* **`EDL` (Main Class):** Classe base para matrizes genéricas, suportando:
    * Exibição formatada (`__str__`).
    * Soma (`__add__`).
    * Subtração (`__sub__`).
    * Multiplicação por escalar (`__mul__` e `__rmul__`).
    * Multiplicação de matrizes (`__mul__`).
    * Conversão para matriz quadrada (`to_square`).
* **`square` (Sub Class):** Derivada de `EDL`, para matrizes quadradas.
    * Verificação de matriz quadrada no construtor.
    * Cálculo do traço (`trace`).
    * Cálculo da transposta (`transposed`).
    * Cálculo do determinante (`determinant`).
* **`upper_triangular` (Sub Class):** Derivada de `EDL`, para matrizes triangulares superiores.
    * Verificação de matriz triangular superior no construtor.
    * Implementação otimizada para soma e subtração (mantendo a propriedade triangular).
    * Cálculo do determinante (produto dos elementos da diagonal).
* **`lower_triangular` (Sub Class):** Derivada de `EDL`, para matrizes triangulares inferiores.
    * Verificação de matriz triangular inferior no construtor.
    * Implementação otimizada para soma e subtração (mantendo a propriedade triangular).
    * Cálculo do determinante (produto dos elementos da diagonal).
* **`diagonal` (Sub Class):** Derivada de `EDL`, para matrizes diagonais.
    * Verificação de matriz diagonal no construtor.
    * Cálculo otimizado da soma, subtração, multiplicação e determinante.
    * Cálculo da inversa (`inverse`).
    * Cálculo da transposta (`transposed`).

O notebook também inclui um sistema de menu interativo para criar, visualizar e operar com as matrizes.


# Implementação da Classe EDL em C++

Este repositório contém a implementação da classe base `EDL` (Estrutura de Dados Lineares) em C++. Esta classe foi desenvolvida para representar e operar com matrizes genéricas, sendo a base para uma futura hierarquia de classes de matrizes mais especializadas (como quadradas, triangulares, diagonais, etc.).

## Visão Geral do Projeto

A classe `EDL` simula o comportamento de uma matriz matemática, permitindo operações fundamentais como adição, subtração e multiplicação, além de conversão para um formato quadrado e impressão formatada. O código busca ser conciso e direto, comum em contextos de programação competitiva.

## Estrutura do Código

O código está contido em um único arquivo:

* `edl_class.cpp`: Contém a definição da classe `EDL` e uma função `main()` para demonstração e teste das suas funcionalidades.

## Detalhes da Classe `EDL`

A classe `EDL` é a classe base para manipulação de matrizes, com as seguintes características:

### Atributos Privados

* `mat` (`typedef vector<vector<double>> matrix_t`): Armazena os elementos da matriz como um vetor de vetores de doubles.
* `R` (int): Representa o número de linhas da matriz.
* `C` (int): Representa o número de colunas da matriz.

### Construtor

* `EDL(const matrix_t& _mat)`: Inicializa uma nova instância de `EDL` com os dados da matriz fornecida.
    * Realiza validações para garantir que todas as linhas da matriz de entrada tenham o mesmo número de colunas. Caso contrário, lança uma `std::invalid_argument`.
    * Lida com o caso de uma matriz vazia, definindo `R` e `C` como zero.

### Destrutor

* `virtual ~EDL() = default;`: Um destrutor virtual padrão é crucial para garantir que a memória seja desalocada corretamente para subclasses que podem herdar de `EDL`, prevenindo vazamentos de memória em contextos polimórficos.

### Sobrecarga de Operadores

A classe `EDL` sobrecarrega operadores para permitir uma sintaxe mais intuitiva para operações com matrizes:

* **Operador de Inserção (`<<`)**:
    * `friend ostream& operator<<(ostream& os, const EDL& obj)`: Permite a impressão formatada de objetos `EDL` diretamente para um `std::ostream` (como `std::cout`). A saída é formatada para centralizar os elementos em 5 espaços e com uma casa decimal, simulando a formatação Python.
* **Operador de Adição (`+`)**:
    * `virtual EDL operator+(const EDL& other) const`: Realiza a soma elemento a elemento de duas matrizes.
    * Requer que as matrizes tenham as mesmas dimensões; caso contrário, lança uma `std::invalid_argument`.
    * Retorna um novo objeto `EDL` contendo o resultado da soma.
* **Operador de Subtração (`-`)**:
    * `virtual EDL operator-(const EDL& other) const`: Realiza a subtração elemento a elemento de duas matrizes.
    * Assim como a soma, exige dimensões compatíveis e lança `std::invalid_argument` se não forem.
    * Retorna um novo objeto `EDL` contendo o resultado da subtração.
* **Operador de Multiplicação (`*`)**:
    * `virtual EDL operator*(const EDL& other) const`: Implementa a multiplicação de matrizes padrão.
        * Requer que o número de colunas da primeira matriz (`this->C`) seja igual ao número de linhas da segunda matriz (`other.R`). Lança `std::invalid_argument` se as dimensões forem incompatíveis.
        * Retorna um novo objeto `EDL` com o produto das matrizes.
    * `EDL operator*(double s) const`: Implementa a multiplicação de todos os elementos da matriz por um valor escalar `s`.
        * Retorna um novo objeto `EDL` com os elementos escalados.
    * `friend EDL operator*(double s, const EDL& m)`: Permite a multiplicação por escalar quando o escalar é o primeiro operando (ex: `3.0 * minhaMatriz`).

### Métodos Auxiliares

* **`to_square()`**:
    * `virtual EDL to_square() const`: Converte a matriz para uma matriz quadrada, preenchendo com zeros os elementos adicionais se as dimensões originais não forem iguais.
    * O tamanho da nova matriz quadrada é o máximo entre o número de linhas e colunas originais.
    * Retorna um novo objeto `EDL` representando a versão quadrada da matriz.
* **Getters**:
    * `int getR() const`: Retorna o número de linhas da matriz.
    * `int getC() const`: Retorna o número de colunas da matriz.
    * `const matrix_t& getMat() const`: Retorna uma referência constante aos dados internos da matriz, permitindo acesso sem modificação.

## Observações

* Este código utiliza `#include <bits/stdc++.h>` e `using namespace std;` para concisão, práticas comuns em programação competitiva, mas geralmente desaconselhadas em projetos de software maiores devido à portabilidade e possíveis colisões de nomes.
* A classe `EDL` serve como a classe base. A extensão para subclasses específicas (como `square`, `upper_triangular`, etc.) envolveria a criação de novas classes que herdam de `EDL` e sobrescrevem (`override`) seus métodos virtuais com lógicas especializadas.

**Autores:**

Matheus Mangia,
Pedro Paulo,
João Allemand,
Gabriel Maia.


---
