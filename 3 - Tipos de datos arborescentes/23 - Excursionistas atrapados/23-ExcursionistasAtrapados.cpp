// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "bintree_eda.h"

// función que resuelve el problema
void resolver(const bintree<int> &arbol, int &atrapados, int &equipoRescate) {
    
	if(arbol.empty()){
		atrapados = 0;
		equipoRescate = 0;
	}
	else if(arbol.left().empty() && arbol.right().empty()){
		atrapados = arbol.root();
		if(arbol.root() != 0)
			equipoRescate = 1;
		else
			equipoRescate = 0;
	}
	else{
		int atrapadosIzq, equipoRescateIzq, atrapadosDer, equipoRescateDer;
		resolver(arbol.left(), atrapadosIzq, equipoRescateIzq);
		resolver(arbol.right(), atrapadosDer, equipoRescateDer);
		equipoRescate = equipoRescateIzq + equipoRescateDer;
		if(arbol.root() != 0 && equipoRescate == 0)
			equipoRescate++;
		atrapados = std::max(atrapadosIzq, atrapadosDer) + arbol.root();
	}
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	bintree<int> arbol = leerArbol(-1);
	int atrapados, equipoRescate;
	resolver(arbol, atrapados, equipoRescate);
    // escribir sol
	std::cout << equipoRescate << " " << atrapados << "\n";
    
    
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
