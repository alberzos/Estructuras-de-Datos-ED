// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "invertirLista.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n;
	std::cin >> n;
    if (! std::cin)
        return false;
	
	invertirLista<int> l;
	while(n != 0){
		l.push(n);
		std::cin >> n;
	}
	
	l.invertir();
	std::cout << l << "\n";
    
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
