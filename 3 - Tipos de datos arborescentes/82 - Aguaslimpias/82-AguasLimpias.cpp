// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "bintree_eda.h"

struct tSol {
    int tramos;
    int caudal;
};

// función que resuelve el problema
tSol resolver(bintree<int> arbol) {
    
    if (arbol.empty())
        return { 0,0 };
    if (arbol.left().empty() && arbol.right().empty())
        return { 0,1 };

    tSol izq = resolver(arbol.left());
    tSol der = resolver(arbol.right());

    int caudalAct = izq.caudal + der.caudal - arbol.root();

    if (caudalAct < 0)
        caudalAct = 0;
    if (caudalAct >= 3) 
        return { izq.tramos + der.tramos + 1, caudalAct };
    else
        return { izq.tramos + der.tramos, caudalAct };

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol = leerArbol(-1);
    
    tSol sol = resolver(arbol);

    if (sol.caudal < 3)
        std::cout << sol.tramos << "\n";
    else
        std::cout << sol.tramos - 1 << "\n";

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
