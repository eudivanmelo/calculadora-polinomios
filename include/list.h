#ifndef LIST_H
#define LIST_H

#include "node.h"

class List {
    private:
        Node* head;
        int max_size;
    
    public:
        List(int size);
        ~List();

        void Append(Node node);
        void Remove(Node node);
        Node Search(int index);
        bool Exists(Node node);

        int Length();
};

#endif // LIST_H