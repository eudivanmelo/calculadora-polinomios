#ifndef NODE_H
#define NODE_H

class Node {
    private:
        float coefficient;
        int degree;

        Node* next;

    public:
        Node(float coefficient, int degree);

        float getCoefficient();
        void setCoefficient(float value);

        int getDegree();
        void setDegree(int value);

        Node* getNext();
        void setNext(Node* node);
};

#endif // NODE_H