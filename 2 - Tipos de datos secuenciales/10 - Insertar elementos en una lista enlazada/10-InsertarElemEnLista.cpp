// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "insertarElem.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n, aux, m, p;
	std::cin >> n;
    if (! std::cin)
        return false;
	
	insertarElem<int> l, insertar;
	for(int i = 0; i < n; i++){
		std::cin >> aux;
		l.push(aux);
	}
	std::cin >> m >> p;
	
	for(int i = 0; i < m; i++){
		std::cin >> aux;
		insertar.push(aux);
	}
	l.insertar(p, insertar);
	
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
