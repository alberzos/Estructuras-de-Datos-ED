// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "bintree_eda.h"


struct tSol {
    bool ok = false;
    int altura = 0;
};

// función que resuelve el problema
tSol resolver(bintree<int> arbol) {
    
    if (!arbol.empty()) {
        tSol izq = resolver(arbol.left());
        tSol der = resolver(arbol.right());
        if (arbol.left().empty() && !arbol.right().empty())
            return { false, 0 };
        if (!arbol.left().empty() && arbol.right().empty()) {
            if (arbol.root() - 18 < arbol.left().root())
                return { false, 0 };
            return{ true, izq.altura + 1 };
        }
        if (!arbol.left().empty() && !arbol.right().empty()) {
            if (arbol.root() - 18 < arbol.left().root())
                return { false, 0 };
            if (arbol.left().root() - 2 < arbol.right().root())
                return { false, 0 };
            return { true, std::max(izq.altura, der.altura) + 1 };
        }
        else
            return { true, 1 };
    }
    else
        return { true, 0 };

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol = leerArbol(-1);

    
    tSol sol = resolver(arbol);
    // escribir sol
    if (sol.ok)
        std::cout << "SI " << sol.altura << "\n";
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
