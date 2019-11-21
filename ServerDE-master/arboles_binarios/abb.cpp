/**Basado en: https://gist.github.com/martincruzot/b3efc660fb5fc1d330ed*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/**Estructura del arbol*/
typedef struct nodo{
    int nro;
    struct nodo *izq, *der;
}*ABB;

int numNodos = 0; // nummero de nodos del arbol ABB
int numK = 0, k;     //  nodos menores que un numero k ingresado


/**Estructura de la cola*/
struct nodoCola{
    ABB ptr;
    struct nodoCola *sgte;
};
struct cola{
    struct nodoCola *delante;
    struct nodoCola *atras;
};

void inicializaCola(struct cola &q)
{
    q.delante = NULL;
    q.atras = NULL;
}

void encola(struct cola &q, ABB n)
{
    struct nodoCola *p;
    p = new(struct nodoCola);
    p->ptr = n;
    p->sgte = NULL;
    if(q.delante==NULL)
        q.delante = p;
    else
        (q.atras)->sgte = p;
    q.atras = p;
}

ABB desencola(struct cola &q)
{
    struct nodoCola *p;
    p = q.delante;
    ABB n = p->ptr;
    q.delante = (q.delante)->sgte;
    delete(p);
    return n;
}

ABB crearNodo(int x)
{
    ABB nuevoNodo = new(struct nodo);
    nuevoNodo->nro = x;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    return nuevoNodo;
}
void insertar(ABB &arbol, int x)
{
    if(arbol==NULL)
    {
        arbol = crearNodo(x);
        cout<<"\n  Insertado..!"<<endl<<endl;
    }
    else if(x < arbol->nro){
        insertar(arbol->izq, x);}
    else {
        insertar(arbol->der, x);}
}

ABB unirABB(ABB izq, ABB der)
{
    if(izq==NULL) return der;
    if(der==NULL) return izq;

    ABB centro = unirABB(izq->der, der->izq);
    izq->der = centro;
    der->izq = izq;
    return der;
}

void elimina(ABB &arbol, int x)
{
    if(arbol==NULL) return;

    if(x<arbol->nro)
        elimina(arbol->izq, x);
    else if(x>arbol->nro)
        elimina(arbol->der, x);

    else
    {
        ABB p = arbol;
        arbol = unirABB(arbol->izq, arbol->der);
        delete p;
    }
}
void verArbol(ABB arbol, int n)
{
    if(arbol==NULL)
        return;
    verArbol(arbol->der, n+1);

    for(int i=0; i<n; i++)
        cout<<"   ";

    numNodos++;
    cout<< arbol->nro <<endl;

    verArbol(arbol->izq, n+1);
}

