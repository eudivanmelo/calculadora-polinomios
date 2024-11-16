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

- Privados
    - **head**: Ponteiro para o primeiro nó da lista encadeada.
    - **max_size**: Define o número máximo de elementos que podem ser adicionados à lista.
    
- Publicos
    - **Contrutor**: Inicializa a lista encadeada.
    - **Destrutor**: Remove todos os nós e libera a memória alocada.
    - **Append**: Adiciona um novo nó a da lista de forma ordenada por grau.
    - **Remove**: Remove um nó da lista.
    - **Search**: Busca um nó na lista pelo índice.
    - **Exists**: Verifica se um nó existe na lista.
    - **Length**: Retorna o numero de elementos atualmente na lista.

## Tarefa
A entrada de dados deverá ser feita à partir de um arquivo texto simples(txt) contendo, em cada
linha, um polinômio ou uma operação a ser realizada sobre polinômio. Por exemplo:

```txt
+
10 2 5 8 -3 1 7 0
2 1 5 2 -12 0
g
-5 3 7 2
p
8 2 2 3 8 1 -1 0
a
5
-3 5 2 0
```
