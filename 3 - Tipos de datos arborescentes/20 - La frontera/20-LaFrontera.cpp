// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

// función que resuelve el problema
void resolver(const bintree<int> &arbol) {
    
	if(!arbol.empty()){
		if(arbol.left().empty() && arbol.right().empty())
			std::cout << arbol.root() << " ";
		else{
			resolver(arbol.left());
			resolver(arbol.right());
		}
	}
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	bintree<int> arbol = leerArbol(-1);
	
    
    resolver(arbol);
	std::cout << "\n";
    // escribir sol
    
    
}

int main() {
	/*
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    */
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    /*
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    */
	
    return 0;
}
