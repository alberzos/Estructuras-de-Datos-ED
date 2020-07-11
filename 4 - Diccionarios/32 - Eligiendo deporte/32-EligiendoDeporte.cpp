// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include "treemap_eda.h"

bool comparar(std::pair < std::string, int> p1, std::pair < std::string, int> p2) {

    if (p1.second > p2.second || (p1.second == p2.second) && p1.first < p2.first)
        return true;
    else
        return false;
      
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    
    std::string cadena, deporte, estudiante;
    getline(std::cin, cadena);

    if (! std::cin)
        return false;
    
    // Al usar set no se repiten valores
    map<std::string, std::set<std::string>> deportes; // Clave: deporte Valor: alumnos apuntados
    map<std::string, std::set<std::string>> alumnos; // Clave: alumno Valor: deportes a los que se ha apuntado

    while (cadena != "_FIN_") {
        if (isupper(cadena[0])) {
            deporte = cadena;
            deportes[deporte];
            getline(std::cin, cadena);

            while (!isupper(cadena[0]) && cadena != "_FIN_") {
                estudiante = cadena;
                deportes[deporte].insert(estudiante);
                alumnos[estudiante].insert(deporte);

                getline(std::cin, cadena);
            }
        }
    }

    std::vector<std::pair<std::string, int>> sol;

    // Mirar que un alumno solo este inscrito una vez
    for (auto &it : deportes) {
        int cont = 0;
        for (auto it2 = it.valor.begin(); it2 != it.valor.end(); it2++) {
            if (alumnos[*it2].size() == 1) {
                cont++;
            }
        }
        sol.push_back({ it.clave, cont });

    }

    // Ordenar de mayor a menor
    std::sort(sol.begin(), sol.end(), comparar);

    for (int i = 0; i < sol.size(); i++) {
        std::cout << sol[i].first << " " << sol[i].second << "\n";
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
