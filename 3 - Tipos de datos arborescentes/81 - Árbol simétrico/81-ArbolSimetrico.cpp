// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "bintree_eda.h"


// función que resuelve el problema
bool resolver(bintree<char> izq, bintree<char> der) {
    
    if (izq.empty() && der.empty()) // Si los dos estan vacios -> son iguales
        return true;
    if((izq.empty() && !der.empty()) || (!izq.empty() && der.empty())) // Uno es vacio y el otro no -> no vale
        return false;

    return (resolver(izq.left(), der.right()) && resolver(izq.right(), der.left()));

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> arbol = leerArbol('.');
    
    if (resolver(arbol.left(), arbol.right()))
        std::cout << "SI \n";
    else
        std::cout << "NO \n";
    
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
