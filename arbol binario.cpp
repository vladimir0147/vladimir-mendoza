#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct nodo {
    int dato;
    nodo *der;
    nodo *izq;
};

void menu();
nodo *crearnodo(int);
void insertarnodo(nodo *&, int);
void mostrarArbolInOrden(nodo *);
void liberarMemoria(nodo *);

nodo *arbol = NULL;

int main() {
    menu();
    getch();
    return 0;
}

void menu() {
    int dato, opcion;
    do {
        cout << "\t. MENU " << endl;
        cout << "1. Ingresar un nuevo nodo" << endl;
        cout << "2. Mostrar el arbol en orden" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\nDigite un numero: ";
                cin >> dato;
                insertarnodo(arbol, dato);
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
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;

    return nuevo_nodo;
}

void insertarnodo(nodo *&arbol, int n) {
    if (arbol == NULL) {
        nodo *nuevo_nodo = crearnodo(n);
        arbol = nuevo_nodo;
    } else {
        int valorraiz = arbol->dato;
        if (n < valorraiz) {
            insertarnodo(arbol->izq, n);
        } else {
            insertarnodo(arbol->der, n);
        }
    }
}

void mostrarArbolInOrden(nodo *arbol) {
    if (arbol != NULL) {
        mostrarArbolInOrden(arbol->izq);
        cout << arbol->dato << " ";
        mostrarArbolInOrden(arbol->der);
    }
}

void liberarMemoria(nodo *arbol) {
    if (arbol != NULL) {
        liberarMemoria(arbol->izq);
        liberarMemoria(arbol->der);
        delete arbol;
    }
}
