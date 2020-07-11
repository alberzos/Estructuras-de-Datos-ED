// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "bintree_eda.h"


struct tSol {
    bool completo;
    bool semi;
    int altura;
};


// función que resuelve el problema
tSol resolver(bintree<char> arbol) {
    
    if (arbol.empty())
        return { true, true, 0 };
    if (arbol.left().empty() && arbol.right().empty())
        return { true, true, 1 };

    tSol izq = resolver(arbol.left());
    tSol der = resolver(arbol.right());

    if (izq.completo && der.completo) {
        if (izq.altura == der.altura)
            return { true, true, izq.altura + 1 };
        if (izq.altura - 1 == der.altura)
            return { false, true, izq.altura + 1 };
    }
    if (izq.semi && der.completo && izq.altura == der.altura + 1)
        return { false, true, izq.altura + 1 };
    if (izq.completo && der.semi && izq.altura == der.altura)
        return { false, true, izq.altura + 1 };

    return { 0, false, false };
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> arbol = leerArbol('.');
    
    tSol sol = resolver(arbol);
    // escribir sol
    if (sol.completo)
        std::cout << "COMPLETO \n";
    else if (sol.semi)
        std::cout << "SEMICOMPLETO \n";
    else
        std::cout << "NADA \n";

    
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
