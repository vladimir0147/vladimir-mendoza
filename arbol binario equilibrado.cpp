#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct nodo {
    int dato;
    int altura;
    nodo *der;
    nodo *izq;
};

void menu();
nodo *crearnodo(int);
void insertarnodo(nodo *&, int);
void mostrarArbolInOrden(nodo *);
void liberarMemoria(nodo *);
int altura(nodo *);
int balanceFactor(nodo *);
nodo *rotacionDerecha(nodo *);
nodo *rotacionIzquierda(nodo *);
nodo *balancearNodo(nodo *);
nodo *insertarAVL(nodo *, int);

nodo *arbol = NULL;

int main() {
    menu();
    liberarMemoria(arbol);
    getch();
    return 0;
}

void menu() {
    int dato, opcion;
    do {
        cout << "\t MENU " << endl;
        cout << "1.Ingresar un nuevo nodo" << endl;
        cout << "2.Mostrar el arbol en orden" << endl;
        cout << "3.Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\nDigite un numero: ";
                cin >> dato;
                arbol = insertarAVL(arbol, dato);
                cout << "\n";
                system("pause");
                break;

            case 2:
                cout << "\nMostrando el arbol en orden:" << endl;
                mostrarArbolInOrden(arbol);
                cout << "\n";
                system("pause");
                break;
        }

        system("cls");
    } while (opcion != 3);
}

nodo *crearnodo(int n) {
    nodo *nuevo_nodo = new nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->altura = 1;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    return nuevo_nodo;
}

int altura(nodo *n) {
    if (n == NULL)
        return 0;
    return n->altura;
}

int balanceFactor(nodo *n) {
    if (n == NULL)
        return 0;
    return altura(n->izq) - altura(n->der);
}

nodo *rotacionDerecha(nodo *y) {
    nodo *x = y->izq;
    nodo *T2 = x->der;

    x->der = y;
    y->izq = T2;

    y->altura = max(altura(y->izq), altura(y->der)) + 1;
    x->altura = max(altura(x->izq), altura(x->der)) + 1;

    return x;
}

nodo *rotacionIzquierda(nodo *x) {
    nodo *y = x->der;
    nodo *T2 = y->izq;

    y->izq = x;
    x->der = T2;

    x->altura = max(altura(x->izq), altura(x->der)) + 1;
    y->altura = max(altura(y->izq), altura(y->der)) + 1;

    return y;
}

nodo *balancearNodo(nodo *n) {
    
    n->altura = max(altura(n->izq), altura(n->der)) + 1;

    int balance = balanceFactor(n);

    if (balance > 1 && balanceFactor(n->izq) >= 0)
        return rotacionDerecha(n);

    if (balance < -1 && balanceFactor(n->der) <= 0)
        return rotacionIzquierda(n);

    if (balance > 1 && balanceFactor(n->izq) < 0) {
        n->izq = rotacionIzquierda(n->izq);
        return rotacionDerecha(n);
    }

    if (balance < -1 && balanceFactor(n->der) > 0) {
        n->der = rotacionDerecha(n->der);
        return rotacionIzquierda(n);
    }

    return n;
}

nodo *insertarAVL(nodo *raiz, int dato) {
    if (raiz == NULL)
        return crearnodo(dato);

    if (dato < raiz->dato)
        raiz->izq = insertarAVL(raiz->izq, dato);
    else if (dato > raiz->dato)
        raiz->der = insertarAVL(raiz->der, dato);
    else 
        return raiz;

    raiz->altura = 1 + max(altura(raiz->izq), altura(raiz->der));
    return balancearNodo(raiz);
}

void mostrarArbolInOrden(nodo *raiz) {
    if (raiz != NULL) {
        mostrarArbolInOrden(raiz->izq);
        cout << raiz->dato << " ";
        mostrarArbolInOrden(raiz->der);
    }
}

void liberarMemoria(nodo *raiz) {
    if (raiz != NULL) {
        liberarMemoria(raiz->izq);
        liberarMemoria(raiz->der);
        delete raiz;
    }
}
