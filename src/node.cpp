#include "../include/node.h"

Node::Node(float coefficient, int degree){
    this->setCoefficient(coefficient);
    this->setDegree(degree);
    this->next = nullptr;
}

float Node::getCoefficient(){
    return this->coefficient;
}

void Node::setCoefficient(float value){
    this->coefficient = value;
}

int Node::getDegree(){
    return this->degree;
}

void Node::setDegree(int value){
    this->degree = value;
}

Node* Node::getNext(){ 
    if (this->next != nullptr)
        return this->next;
    else
        return nullptr;
}

void Node::setNext(Node* node){
    this->next = node;
}

