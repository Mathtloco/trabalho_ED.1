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


## Implementação em C++

### `C++/edl_class.cpp` (ou similar)

Este arquivo contém a tradução da classe base `EDL` do Python para C++. O objetivo é demonstrar a estrutura da classe, a manipulação de dados (`std::vector<std::vector<double>>`), a sobrecarga de operadores e o tratamento de exceções em C++.

**Classe `EDL` (Main Class):**

* **Membros de Dados:**
    * `mat` (`std::vector<std::vector<double>>`): Armazena os elementos da matriz.
    * `R` (int): Número de linhas.
    * `C` (int): Número de colunas.
* **Construtor:** Inicializa a matriz e suas dimensões, validando a consistência dos dados.
* **Destrutor Virtual (`virtual ~EDL() = default;`):** Essencial para hierarquias de classes em C++ para garantir a desalocação correta de objetos de subclasses.
* **Sobrecarga do Operador `<<` (Impressão):** Permite imprimir objetos `EDL` diretamente usando `std::cout`.
* **Sobrecarga dos Operadores `+`, `-`, `*` (Soma, Subtração, Multiplicação):** Implementam as operações de matrizes, com validação de dimensões e retorno de um novo objeto `EDL` com o resultado. A multiplicação por escalar é tratada para ambas as ordens (escalar * matriz e matriz * escalar).
* **`to_square()`:** Converte a matriz para um formato quadrado, preenchendo com zeros se necessário.
* **Getters (`getR()`, `getC()`, `getMat()`):** Métodos para acessar as dimensões e os dados da matriz.



## Conceitos Abordados

Este projeto serve como um exemplo prático de:

* **Programação Orientada a Objetos (POO):** Demonstração de classes, objetos, atributos, métodos, construtores e destrutores.
* **Herança:** A relação entre a classe `EDL` e suas subclasses (no Python), e a preparação da classe `EDL` em C++ para futura herança.
* **Polimorfismo:** (Principalmente no Python, e preparado para C++ com `virtual` functions) A capacidade de tratar objetos de diferentes classes de forma uniforme através de uma interface comum.
* **Sobrecarga de Operadores:** Adaptação de operadores padrão (`+`, `-`, `*`, `<<`) para realizar operações com objetos de matrizes.
* **Estruturas de Dados:** Uso de listas aninhadas (Python) e `std::vector` aninhados (C++) para representar matrizes.
* **Tratamento de Exceções:** Uso de `try-except` (Python) e `try-catch` com `std::invalid_argument` (C++) para lidar com erros de dimensões incompatíveis.
* **Complexidade Algorítmica:** Análise implícita das operações de matrizes em termos de tempo e espaço.

---

**Autores:**

Matheus Mangia,
Pedro Paulo,
João Allemand,
Gabriel Maia.


---
