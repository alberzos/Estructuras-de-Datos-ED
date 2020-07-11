// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "bintree_eda.h"


struct tSol {
    bool ok;
    int altura;
    int alturaMax;
};

// función que resuelve el problema
tSol resolver(bintree<char> arbol) {
    
    if (arbol.empty())
        return { false, 0, 0 };
    if (arbol.left().empty() && arbol.right().empty())
        return { true, 1, 1 };

    tSol izq = resolver(arbol.left());
    tSol der = resolver(arbol.right());

    int max = std::max(izq.alturaMax, der.alturaMax);
    int alt = std::min(izq.altura, der.altura) + 1;
    return { true, alt, std::max(max, alt)};

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> arbol = leerArbol('.');

    tSol sol = resolver(arbol);
    // escribir sol
    std::cout << sol.alturaMax << "\n";
    
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
