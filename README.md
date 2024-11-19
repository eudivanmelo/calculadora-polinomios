# Calculadora de Polinomios
Projeto desenvolvido para a disciplina de estrutura de dados lineares do curso de ADS do IFRN.

# Objetivo
Criar duas classes denominadas 'Node' e 'List'. Na classe 'Node' deverá ter dois atributos (float, int) e mais um ponteiro para o próximo 'Node'. A classe 'List' deverá armazenar esses 'Node'.

*(A lista será ordenada pelo segundo atributo do nó, no caso o grau)*

# Cabeçalhos

## Node
- Privados
    - **coefficient**: Atributo do tipo float que irá armazenar o coeficiente de um item do polinômio.
    - **degree**: Atributo do tipo inteiro que irá armazenar o grau de um item do polinômio.
    - **next**: Ponteiro para o próximo item da lista.

- Publicos
    - **Construtor**: Inicializa um novo nó com os valores fornecidos para o coeficiente e o grau.
    - **getCoefficient**: Retorna o coeficiente armazenado no nó.
    - **setCoefficient**: Atualiza o coeficiente armazenado no nó.
    - **getDegree**: Retorna o grau do termo armazenado no nó.
    - **setDegree**: Atualiza o grau do termo armazenado no nó.
    - **getNext**: Retorna o ponteiro para o próximo nó na lista.
    - **setNext**: Atualiza o ponteiro para o próximo nó na lista.

## List

- **Privados**
    - **head**: Ponteiro para o primeiro nó da lista encadeada.
    
- **Públicos**
    - **Construtor**: Inicializa a lista encadeada.
    - **Destrutor**: Remove todos os nós e libera a memória alocada.
    - **Append**: Adiciona um novo nó à lista de forma ordenada por grau.
    - **Remove**: Remove um nó da lista.
    - **Search**: Busca um nó na lista pelo índice.
    - **Exists**: Verifica se um nó existe na lista.
    
    - **degree**: Retorna o grau do polinômio (maior grau na lista).
    - **size**: Retorna o número de termos (nós) atualmente na lista.
    - **evaluate**: Avalia o polinômio para um valor real fornecido de `x`.
    - **toString**: Retorna uma representação textual do polinômio como uma string.
    - **Simplify**: Método interno que simplifica a lista somando termos de mesmo grau e removendo termos com coeficiente zero.
    - **Sobrecarga de operadores**:
        - `operator+`: Adição de dois polinômios.
        - `operator-`: Subtração de dois polinômios.
        - `operator*`: Multiplicação de dois polinômios.
        - `operator<<`: Exibição do polinômio como string.

## Tarefa
A entrada de dados deverá ser feita à partir de um arquivo texto simples(txt) contendo, em cada
linha, um ou mais polinômios, ou uma operação a ser realizada sobre polinômio(s). Por exemplo:

```txt
+
3 5 2 8 -1 3 4 2 0
2 4 5 3 -2 2 1 1 5 0
-
4 5 3 4 -2 3 1 0
3 3 5 2 1 1 -3 0
*
3 6 2 5 -3 3 4 0
4 4 1 3 -2 2 1 0
G
4 6 3 4 1 2 1 0
A
6
2 4 1 3 2 2 3 1 0
T
3 4 2 3 -5 1 4 0
P
2 4 -2 3 3 2 1 0
```
