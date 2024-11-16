#include "../include/list.h"

List::List(int size){
    this->head = nullptr;
    this->max_size = size
}

List::~List(){
    Node* current = this->head;
    while(current != nullptr){
        Node* next = current->getNext();
        delete current;
        current = next;
    }
}


void List::Append(Node node){
    if (this->length + 1 > max_size)
        return;
    
    if (!head || node.getDegree() > head->getDegree()){
        node.setNext(head);
        head = &node;
    }
    else{
        Node* current = head;

        while(current->getNext() != nullptr && node.getDegree() < current->getNext()->getDegree()){
            current = current->getNext();
        }

        node.setNext(current->getNext());
        current->setNext(&node)
    }
}

void List::Remove(Node node){
    Node* current = head;

    while(current != nullptr){
        if (current->getNext() == &node){
            current->setNext(node.getNext());
            break;
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

int List::Length(){
    int length = 0;
    Node* current = this->head;

    while(current != nullptr){
        length++;
        current = current->getNext();
    }

    return length;
}