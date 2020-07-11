// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "hashmap_eda.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    unordered_map<int, int> mapa; // Clave: capitulo, Valor: dia
    int cap, pos = 0, cont = 0, contMax = 0;

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> cap;
        if (mapa.count(cap) > 0 && pos <= mapa[cap])
            pos = mapa[cap]+1;
        mapa[cap] = i;
        cont = i - pos + 1;
        if (contMax < cont)
            contMax = cont;

    }
    
    // escribir sol
    std::cout << contMax << "\n";
    
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
