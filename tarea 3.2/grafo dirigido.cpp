#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class GrafoDirigido {
private:
    unordered_map<int, list<int>>nodos;
public:
    void agregarNodo(int nodo) {
        nodos[nodo]; 
    }
    void agregarArista(int origen, int destino) {
        nodos[origen].push_back(destino); 
    }
    void mostrarGrafo() {
        for (const auto& par : nodos) {
            cout << par.first << " -> ";
            for (const auto& adyacente : par.second) {
                cout << adyacente << " ";
            }
            cout << endl;
        }
    }
};
int main() {
    GrafoDirigido grafo;
    int opcion, origen, destino;

    do {
        cout<<"\t MENU "<<endl;
        cout<<"1. Agregar nodo"<<endl;
        cout<<"2. Agregar arista"<<endl;
        cout<<"3. Mostrar el grafo"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"Selecciona una opcion: ";
        cin>>opcion;

        switch (opcion) {
            case 1:
                cout<<"\nDigite el valor del nodo: ";
                cin>>origen;
                grafo.agregarNodo(origen);
                cout<<"\n";
                system("pause");
                break;

            case 2:
                cout<<"\nDigite el origen de la arista: ";
                cin>>origen;
                cout<<"Digite el destino de la arista: ";
                cin>>destino;
                grafo.agregarArista(origen, destino);
                cout<<"\n";
                system("pause");
                break;

            case 3:
                cout<<"\nMostrando el grafo:"<<endl;
                grafo.mostrarGrafo();
                cout<<"\n";
                system("pause");
                break;
        }

        system("cls");
    } while (opcion!=4);
    return 0;
}
