// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "bintree_eda.h"

// función que resuelve el problema
int resolver(const bintree<char> &arbol, int &m) {
    
	if(arbol.empty()){
		m = 0;
		return 0;
	}
	else{
		int alturaIzq, alturaDer, diamIzq, diamDer;
		alturaIzq = resolver(arbol.left(), diamIzq);
		alturaDer = resolver(arbol.right(), diamDer);
		m = std::max(diamIzq, diamDer) + 1;
		int d = std::max(alturaIzq, alturaDer);
		return std::max(diamIzq + diamDer + 1, d);
	}
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	char vacio = '.';
	bintree<char> arbol = leerArbol(vacio);
	int m = 0;
	std::cout << resolver(arbol, m) << "\n";
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
