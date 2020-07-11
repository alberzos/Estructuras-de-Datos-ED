// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "queue_eda.h"


template <class T>
class mezclarLista : public queue<T> {
    using Nodo = typename queue<T>::Nodo;

public:

    void mezclar(mezclarLista<int> &l) {

        Nodo* actualL1 = this->prim;
        Nodo* actualL2 = l.prim;
        Nodo* aux;

        if (actualL1 == nullptr) { // Si la lista donde se va añadir esta vacia el primer elemento sera el de la otra
            this->prim = actualL2;
            this->nelems = l.nelems;
        }
        else if (actualL1 != nullptr && actualL2 != nullptr) { // Si las dos tienen algo
            
            // Se compara para saber cual de ellos sera el primer elemento
            if (actualL1->elem <= actualL2->elem) {
                aux = actualL1;
                actualL1 = actualL1->sig;
            }
            else {
                this->prim = actualL2;
                aux = actualL2;
                actualL2 = actualL2->sig;
            }

            while(actualL1 != nullptr && actualL2 != nullptr) {
                if (actualL1->elem <= actualL2->elem) {
                    aux->sig = actualL1;
                    actualL1 = actualL1->sig;
                    aux = aux->sig;
                }
                else {
                    aux->sig = actualL2;
                    actualL2 = actualL2->sig;
                    aux = aux->sig;
                }
            }
            if (actualL1 == nullptr) {
                aux->sig = actualL2;
                actualL2 = actualL2->sig;
            }
            else if (actualL2 == nullptr) {
                aux->sig = actualL1;
                actualL1 = actualL1->sig;
            }
            this->nelems = this->nelems + l.nelems;
        }
        l.prim = nullptr;
        l.ult = nullptr;
        l.nelems = 0;
    }

    const void display(std::ostream& o) {
        if (!this->empty()) {
            Nodo* nodo = this->prim;
            for (int i = 0; i < this->nelems; i++) {
                std::cout << nodo->elem << " ";
                nodo = nodo->sig;
            }
            std::cout << "\n";
        }
    }

};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n; 
    mezclarLista<int> l1, l2;

    std::cin >> n;
    while (n != 0) {
        l1.push(n);
        std::cin >> n;
    }

    std::cin >> n;
    while (n != 0) {
        l2.push(n);
        std::cin >> n;
    }

    l1.mezclar(l2);
    
    // escribir sol
    l1.display(std::cout);
    
}

int main() {

    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
	
    return 0;
}
