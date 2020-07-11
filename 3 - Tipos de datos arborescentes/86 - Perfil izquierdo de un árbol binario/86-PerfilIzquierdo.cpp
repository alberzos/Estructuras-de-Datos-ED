// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "bintree_eda.h"


// función que resuelve el problema
void resolver(bintree<int> arbol, std::vector<int> &v, int alt) {
    
    if (!arbol.empty()) {
        if (alt > v.size())
            v.push_back(arbol.root());
        resolver(arbol.left(), v, alt + 1);
        resolver(arbol.right(), v, alt + 1);
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol = leerArbol(-1);
    std::vector<int> v;

    // escribir sol
    resolver(arbol, v, 1);

    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";
    
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
