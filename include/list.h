#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <string>

class List {
    private:
        Node* head;
        
        void Simplify();
    
    public:
        List();
        ~List();

        void Append(float coefficient, int degree);
        void Remove(Node node);
        Node Search(int degree);
        bool Exists(Node node);

        // Operations
        int degree() const;
        int size() const;
        float evaluate(float x) const;
        std::string toString() const;
        friend std::ostream& operator<<(std::ostream& os, const List& p);
        friend List operator+(const List& p1, const List& p2);
        friend List operator-(const List& p1, const List& p2);
        friend List operator*(const List& p1, const List& p2);
        Node& operator[](const int index);
};

#endif // LIST_H