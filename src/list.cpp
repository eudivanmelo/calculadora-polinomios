#include "../include/list.h"
#include <iostream>
#include <cmath>

using namespace std;

List::List(){
    this->head = nullptr;
}

List::~List(){
    Node* current = this->head;
    while(current != nullptr){
        Node* next = current->getNext();
        delete current;
        current = next;
    }
}

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
        else
            prev = current;
            current = current->getNext();
    }
}


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

Node List::Search(int index){
    Node* current = head;

    for(int i = 0; i < index; i++){
        current = current->getNext();
    }

    return *current;
}

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


int List::degree() const{
    if (!head) return 0;

    return head->getDegree();
}

int List::size() const{
    int length = 0;
    Node* current = this->head;

    while(current != nullptr){
        length++;
        current = current->getNext();
    }

    return length;
}

float List::evaluate(float x) const{
    float result = 0;

    Node* current = head;

    while(current){
        result += current->getCoefficient() * pow(x, current->getDegree());
        current = current->getNext();
    }

    return result;
}

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

std::ostream& operator<<(std::ostream& os, const List& p){
    os << p.toString();
    return os;
}

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