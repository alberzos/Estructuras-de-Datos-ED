// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

// función que resuelve el problema
int nodos(const bintree<char> &arbol) {
    
	if(arbol.empty())
		return 0;
	else
		return 1 + nodos(arbol.left()) + nodos(arbol.right());
		
}

int hojas(const bintree<char> &arbol) {
    
	if(arbol.empty())
		return 0;
	else if(arbol.left().empty() && arbol.right().empty())
		return 1;
	else
		return hojas(arbol.left()) + hojas(arbol.right());
    
}

int altura(const bintree<char> &arbol) {
    
	if(arbol.empty())
		return 0;
	else
		return 1 + std::max(altura(arbol.left()), altura(arbol.right()));
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	bintree<char> arbol = leerArbol('.');
	
	// escribir sol
	std::cout << nodos(arbol) << " " << hojas(arbol) << " " <<
	altura(arbol) << "\n";
    
    
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
