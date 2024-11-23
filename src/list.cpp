#include "../include/list.h"
#include <iostream>
#include <cmath>

using namespace std;

/**
 * @file list.cpp
 * @brief Implementação da classe List.
 */

/**
 * @brief Construtor padrão da classe List.
 *
 * Inicializa a lista com o ponteiro de cabeça (head) como nulo.
 */
List::List(){
    this->head = nullptr;
}

/**
 * @brief Destrutor da classe List.
 *
 * Este destrutor libera a memória alocada para todos os nós da lista.
 */
List::~List(){
    Node* current = this->head;
    while(current != nullptr){
        Node* next = current->getNext();
        delete current;
        current = next;
    }
}

/**
 * @brief Simplifica a lista de nós combinando termos com o mesmo grau e removendo nós com coeficiente zero.
 *
 * Esta função percorre a lista de nós, combinando termos que possuem o mesmo grau e somando seus coeficientes.
 * Se o coeficiente resultante for zero, o nó é removido da lista.
 */
void List::Simplify(){
    if (!head) return;

    Node* current = head;
    Node* prev = nullptr;

    while(current){
        Node* runner = current;
        while(runner->getNext()){
            if (runner->getNext()->getDegree() == current->getDegree()){
                current->setCoefficient(current->getCoefficient() + runner->getNext()->getCoefficient());
                Node* temp = runner->getNext();
                runner->setNext(runner->getNext()->getNext());
                delete temp;
            }
            else
                runner = runner->getNext();
        }

        if (current->getCoefficient() == 0){
            Node* temp = current;

            if (current == head) {
                head = current->getNext();
            } else {
                prev->setNext(current->getNext());
            }

            current = current->getNext();
            delete temp;
        }
        else{
            prev = current;
            current = current->getNext();
        }
    }
}


/**
 * @brief Adiciona um novo nó à lista de forma ordenada.
 * 
 * @param coefficient Coeficiente do polinômio.
 * @param degree Grau do polinômio.
 * 
 * Se o coeficiente for zero, a função retorna sem adicionar o nó.
 * Caso contrário, cria um novo nó e o insere na posição correta
 * na lista, mantendo a ordem decrescente dos graus.
 */
void List::Append(float coefficient, int degree){
    if (coefficient == 0)
        return;

    Node* node = new Node(coefficient, degree);
    
    if (!head || node->getDegree() > head->getDegree()){
        node->setNext(head);
        head = node;
    }
    else{
        Node* current = head;

        while(current->getNext() != nullptr && node->getDegree() < current->getNext()->getDegree()){
            current = current->getNext();
        }

        node->setNext(current->getNext());
        current->setNext(node);
    }
}

/**
 * @brief Remove um nó específico da lista.
 * 
 * @param node O nó a ser removido da lista.
 * 
 * Se a lista estiver vazia, a função retorna imediatamente.
 * Se o nó a ser removido for o nó cabeça, a cabeça é atualizada para o próximo nó.
 * Caso contrário, a função percorre a lista até encontrar o nó e o remove, ajustando os ponteiros.
 */
void List::Remove(Node node){
    if (!head) {
        return; 
    }

    if (&node == head) {
        Node* temp = head;
        head = head->getNext();
        delete temp;
        return; 
    }

    Node* current = head;
    while (current != nullptr) {
        if (current->getNext() == &node) {
            Node* temp = current->getNext();
            current->setNext(current->getNext()->getNext());
            delete temp;
            return;
        }
        current = current->getNext();
    }
}

/**
 * @brief Procura e retorna o nó na posição especificada.
 * 
 * @param index Índice do nó a ser procurado.
 * @return Node Nó encontrado na posição especificada.
 */
Node List::Search(int degree){
    Node* current = head;

    while(current != nullptr){
        if (current->getDegree() == degree){
            return *current;
        }

        current = current->getNext();
    }

    return Node(0, 0);
}

/**
 * @brief Verifica se um nó específico existe na lista.
 * 
 * @param node Referência para o nó a ser verificado.
 * @return true Se o nó existe na lista.
 * @return false Se o nó não existe na lista.
 */
bool List::Exists(Node node){
    Node* current = head;

    while(current != nullptr){
        if (current == &node){
            return true;
        }

        current = current->getNext();
    }

    return false;
}

/**
 * @brief Retorna o grau do polinômio.
 * 
 * @return int Grau do polinômio. Retorna 0 se a lista estiver vazia.
 */
int List::degree() const{
    if (!head) return 0;

    return head->getDegree();
}

/**
 * @brief Retorna o tamanho da lista.
 * 
 * Este método percorre a lista encadeada a partir do nó cabeça (head) e conta
 * o número de nós presentes na lista.
 * 
 * @return int O número de elementos na lista.
 */
int List::size() const{
    int length = 0;
    Node* current = this->head;

    while(current != nullptr){
        length++;
        current = current->getNext();
    }

    return length;
}

/**
 * @brief Avalia o polinômio representado pela lista para um dado valor de x.
 * 
 * @param x Valor de x para o qual o polinômio será avaliado.
 * @return float Resultado da avaliação do polinômio.
 */
float List::evaluate(float x) const{
    float result = 0;

    Node* current = head;

    while(current){
        result += current->getCoefficient() * pow(x, current->getDegree());
        current = current->getNext();
    }

    return result;
}

/**
 * @brief Converte a lista de polinômios em uma string.
 *
 * @return Uma string representando o polinômio. Se a lista estiver vazia, retorna "List is empty".
 */
std::string List::toString() const{
    if (!head)
        return "List is empty";

    Node* current = head;
    string result;
    bool first = true;

    while(current){
        if (current->getCoefficient() >= 0 && !first)
            result += "+";

        if (current->getCoefficient() != 1 || current->getDegree() == 0)
            if (current->getCoefficient() == std::floor(current->getCoefficient())) {
                result += std::to_string(static_cast<int>(current->getCoefficient()));
            } else {
                result += std::to_string(current->getCoefficient());
            }

        if (current->getDegree() != 0)
            if (current->getDegree() != 1)
                result += "x^" + std::to_string(current->getDegree());
            else
                result += "x";
        
        first = false;
        current = current->getNext();
    }

    return result;
}

/**
 * @brief Sobrecarga do operador de inserção (<<) para a classe List.
 * 
 * Este operador permite que um objeto da classe List seja impresso diretamente
 * em um fluxo de saída (std::ostream), como std::cout, utilizando o método 
 * toString() da classe List para obter a representação em string do objeto.
 * 
 * @param os Referência para o fluxo de saída.
 * @param p Referência constante para o objeto List a ser impresso.
 * @return std::ostream& Referência para o fluxo de saída, permitindo encadeamento.
 */
std::ostream& operator<<(std::ostream& os, const List& p){
    os << p.toString();
    return os;
}

/**
 * @brief Sobrecarga do operador + para somar duas listas de polinômios.
 * 
 * @param p1 Primeira lista de polinômios.
 * @param p2 Segunda lista de polinômios.
 * @return List Resultado da soma das duas listas de polinômios.
 * 
 * Este método percorre ambas as listas, adiciona os termos ao resultado
 * e simplifica o polinômio resultante.
 */
List operator+(const List& p1, const List& p2){
    List result;

    Node* n1 = p1.head;
    Node* n2 = p2.head;

    while (n1) {
        result.Append(n1->getCoefficient(), n1->getDegree());
        n1 = n1->getNext();
    }

    while (n2) {
        result.Append(n2->getCoefficient(), n2->getDegree());
        n2 = n2->getNext();
    }

    result.Simplify();
    return result;
}

/**
 * @brief Sobrecarga do operador de subtração para listas de polinômios.
 *
 * Esta função realiza a subtração de dois polinômios representados por listas encadeadas.
 * Cada nó da lista contém um coeficiente e um grau do polinômio.
 *
 * @param p1 Primeira lista de polinômio.
 * @param p2 Segunda lista de polinômio.
 * @return List Resultado da subtração dos polinômios.
 */
List operator-(const List& p1, const List& p2){
    List result;

    Node* n1 = p1.head;
    Node* n2 = p2.head;

    while (n1) {
        result.Append(n1->getCoefficient(), n1->getDegree());
        n1 = n1->getNext();
    }

    while (n2) {
        result.Append(-n2->getCoefficient(), n2->getDegree());
        n2 = n2->getNext();
    }

    result.Simplify();
    return result;
}

/**
 * @brief Sobrecarga do operador * para multiplicação de polinômios representados por listas encadeadas.
 * 
 * @param p1 Primeiro polinômio.
 * @param p2 Segundo polinômio.
 * @return List Resultado da multiplicação dos polinômios p1 e p2.
 * 
 * Este método percorre cada termo dos polinômios p1 e p2, multiplicando os coeficientes e somando os graus.
 * Os termos resultantes são adicionados à lista resultante, que é simplificada antes de ser retornada.
 */
List operator*(const List& p1, const List& p2){
    List result;

    Node* n1 = p1.head;
    while(n1){
        Node* n2 = p2.head;
        while(n2){
            result.Append(n1->getCoefficient() * n2->getCoefficient(), n1->getDegree() + n2->getDegree());
            n2 = n2->getNext();
        }
        n1 = n1->getNext();
    }

    result.Simplify();
    return result;
}

/**
 * @brief Sobrecarga do operador de índice para acessar um nó na lista.
 * 
 * @param index Índice do nó a ser acessado.
 * @return Node& Referência ao nó na posição especificada.
 */
Node& List::operator[](const int index) {
    Node* current = head;

    for (int i = 0; i < index; i++) {
        current = current->getNext();
    }

    return *current;
}