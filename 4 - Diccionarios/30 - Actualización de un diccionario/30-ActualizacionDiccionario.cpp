// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include "treemap_eda.h"

struct tSol {
    std::vector<std::string> agrega;
    std::vector<std::string> elimina;
    std::vector<std::string> cambia;
};

// función que resuelve el problema
tSol resolver(map<std::string, int> antiguo, map<std::string, int> nuevo) {
    
    tSol sol;

    for (auto i: nuevo) {
        if (antiguo.count(i.clave) == 1 && antiguo[i.clave] != i.valor) // Si la clave i de nuevo esta en antiguo && tiene distinto valor
            sol.cambia.push_back(i.clave);
        else if(!antiguo.count(i.clave)) // No encuentra la clave i de nuevo en antiguo
            sol.agrega.push_back(i.clave);
    }
    for (auto i : antiguo) {
        if (nuevo.count(i.clave) == 0) // Si no encuentra la clave i de antiguo en el nuevo
            sol.elimina.push_back(i.clave);
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    map<std::string, int> antiguo, nuevo;
    std::string linea, datos, clave;
    int valor;

    getline(std::cin, linea);
    std::stringstream x(linea);
    while (x >> clave >> valor)
        antiguo[clave] = valor;

    getline(std::cin, linea);
    std::stringstream y(linea);
    while (y >> clave >> valor)
        nuevo[clave] = valor;

    
    tSol sol = resolver(antiguo, nuevo);
    // escribir sol
    if (sol.agrega.empty() && sol.cambia.empty() && sol.elimina.empty())
        std::cout << "Sin cambios \n";
    else {
        if (!sol.agrega.empty()) {
            std::cout << "+ ";
            for (int i = 0; i < sol.agrega.size(); i++)
                std::cout << sol.agrega[i] << " ";
            std::cout << "\n";
        }
        if (!sol.elimina.empty()) {
            std::cout << "- ";
            for (int i = 0; i < sol.elimina.size(); i++)
                std::cout << sol.elimina[i] << " ";
            std::cout << "\n";
        }
        if (!sol.cambia.empty()) {
            std::cout << "* ";
            for (int i = 0; i < sol.cambia.size(); i++)
                std::cout << sol.cambia[i] << " ";
            std::cout << "\n";
        }
    }
    std::cout << "--- \n";
    
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
    std::cin.ignore();
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
	
    return 0;
}
