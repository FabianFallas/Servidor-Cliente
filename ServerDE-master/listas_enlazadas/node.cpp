#include "node.h"


// Constructor por defecto
Node::Node()
{
    data = NULL;
    next = NULL;
}

// Constructor por parámetro

Node::Node(int data_)
{
    data = data_;
    next = NULL;
}

// Eliminar todos los Nodos

void Node::delete_all()
{
    if (next)
        next->delete_all();
    delete this;
}

// Imprimir un Nodo

void Node::print()
{

    cout << data << "-> ";
}


Node::~Node() {}
