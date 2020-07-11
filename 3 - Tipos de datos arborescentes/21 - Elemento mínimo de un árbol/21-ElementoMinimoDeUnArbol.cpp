// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

template <typename T>
// función que resuelve el problema
T resolver(bintree<T> arbol) {
	
	 T minimo = arbol.root();
	 if(!arbol.left().empty())
		 minimo = std::min(minimo, resolver(arbol.left()));
	 if(!arbol.right().empty())
		 minimo = std::min(minimo, resolver(arbol.right()));
	 return minimo;
	 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	std::string tipo;
	std::cin >> tipo;
	
    if (! std::cin)
        return false;
    
	if(tipo == "N"){
		bintree<int> arbolN = leerArbol(-1);
		std::cout << resolver(arbolN) << "\n";
	}
	else if(tipo == "P"){
		std::string v = "#";
		bintree<std::string> arbolP = leerArbol(v);
		std::cout << resolver(arbolP) << "\n";
	}
    
    // escribir sol
    
    
    return true;
    
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
    
    while (resuelveCaso())
        ;

    /*
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    */
	 
    return 0;
}
