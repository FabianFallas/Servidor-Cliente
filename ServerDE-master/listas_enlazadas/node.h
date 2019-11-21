#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;


class Node
{
    public:
        Node();
        Node(int);
        ~Node();

        Node *next;
        int data;

        void delete_all();
        void print();
};

#endif // NODE_H
