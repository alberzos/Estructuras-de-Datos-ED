// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "bintree_eda.h"


struct tSol {
    bool ok = false;
    int min = 0;
    int max = 0;
};

// función que resuelve el problema
tSol resolver(bintree<int> arbol) {
    
	if (arbol.empty())
		return { true, -1, 0};

	tSol izq = resolver(arbol.left());
	tSol der = resolver(arbol.right());

	if (der.min == -1)
        der.min = arbol.root() + 1;

	if (izq.ok && der.ok && arbol.root() > izq.max && arbol.root() < der.min) {
		if (izq.min == -1)
			izq.min = arbol.root();
		if (der.max == 0)
            der.max = arbol.root();
		return{ true, izq.min, der.max};
	}
	else 
		return{ false, 0, 0 };
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol = leerArbol(-1);

    tSol sol = resolver(arbol);
    if(sol.ok)
        std::cout << " SI \n";
    else
        std::cout << " NO \n";

    // escribir sol
    
    
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
