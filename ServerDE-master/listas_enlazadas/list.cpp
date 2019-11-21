/**
 * Basado en: https://github.com/ronnyml/C-Tutorial-Series/tree/master/Listas_enlazadas
 */

#include "list.h"

using namespace std;

// Constructor por defecto

List::List()
{
    m_num_nodes = 0;
    m_head = NULL;
}

// Insertar al inicio
void List::add_head(int data_)
{
    Node *new_node = new Node ( data_);
    Node *temp = m_head;

    if (!m_head) {
        m_head = new_node;
    } else {
        new_node->next = m_head;
        m_head = new_node;

        while (temp) {
            temp = temp->next;
        }
    }
    m_num_nodes++;
}

// Eliminar al inicio
void List::del_head(){
        Node* aux1 = m_head;
        m_head = m_head->next;
        aux1->next = NULL;
        m_num_nodes --;
}


// Obtener por posición del nodo
void List::obt_by_position(int pos) {
    Node *temp = m_head;

    for(int i; i<=m_num_nodes; i++){
        if (i==pos){
            temp->print();
        }else{
            temp=temp->next;
        }
    }

}

void List::print() {
    Node *temp = m_head;
        if (!m_head) {
            cout << "La Lista está vacía " << endl;
        } else {
            while (temp) {
                temp->print();
                if (!temp->next) cout << "NULL";
                temp = temp->next;
            }
        }
        //cout << endl << endl;
    }


List::~List() {}
