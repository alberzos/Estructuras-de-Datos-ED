// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include "treemap_eda.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    std::cin.ignore();
    map<std::string, std::vector<int>> mapa; // Clave: palabra  Valor: vector con las lineas donde esta
    if (n == 0)
        return false;
    
    for (int i = 0; i < n; i++) {
        std::string linea, palabra;
        getline(std::cin, linea);
        std::stringstream aux(linea);

        while (aux >> palabra) {
            if (palabra.length() > 2) {
                for (int j = 0; j < palabra.size(); j++) // Pasa la palabra a minusculas
                    palabra[j] = tolower(palabra[j]);
                if (mapa.count(palabra) == 0) { // Si la clave palabra no esta en mapa la inserta, y como valor i + 1 que es la linea
                    mapa.insert(palabra);
                    mapa[palabra].push_back(i + 1);
                }
                if (mapa[palabra].back() != i + 1)
                    mapa[palabra].push_back(i + 1);
            }
        }
    }
    for (auto it : mapa) {
        std::cout << it.clave << " ";
        for (int i = 0; i < it.valor.size(); i++)
            std::cout << it.valor[i] << " ";
        std::cout << "\n";
    }
    std::cout << "--- \n";
    
    return true;
    
}

int main() {
	
	
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
	 
    return 0;
}
