// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "hashmap_eda.h"


class carnet {
public:

    //Constructor
    carnet() : v_puntos(16) {};

    void nuevo(std::string dni) {

        if (conductor.count(dni) > 0)
            throw std::domain_error("Conductor duplicado");
        conductor.insert({ dni, 15 });
        v_puntos[15]++;

    }

    void quitar(std::string dni, int puntos) {

        if (conductor.count(dni) == 0)
            throw std::domain_error("Conductor inexistente");

        v_puntos[conductor.at(dni)]--;
        conductor[dni] = conductor[dni] - puntos;
        if (conductor[dni] < 0)
            conductor[dni] = 0;
        v_puntos[conductor[dni]]++;

    }

    int consultar(std::string dni) {

        if (conductor.count(dni) == 0)
            throw std::domain_error("Conductor inexistente");
        return conductor.at(dni);

    }

    int cuantos_con_puntos(int puntos) {
        if (puntos < 0 || puntos > 15)
            throw std::domain_error("Puntos no validos");
        return v_puntos[puntos];
    }

private:
    unordered_map<std::string, int> conductor; // Clave:DNI. Valor:puntos
    std::vector<int> v_puntos; // Vector con 15 posiciones, una para cada punto
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string linea;
    carnet c;
    std::cin >> linea;

    if (! std::cin)
        return false;
    
    while (linea != "FIN") {
        try {
            if (linea == "nuevo") {
                std::string dni;
                std::cin >> dni;
                c.nuevo(dni);
            }
            else if (linea == "quitar") {
                std::string dni;
                int puntos;
                std::cin >> dni >> puntos;
                c.quitar(dni, puntos);
            }
            else if (linea == "consultar") {
                std::string dni;
                std::cin >> dni;
                int p = c.consultar(dni);
                std::cout << "Puntos de " << dni << ": " << p << "\n";
            }
            else if (linea == "cuantos_con_puntos") {
                int puntos;
                std::cin >> puntos;
                int p = c.cuantos_con_puntos(puntos);
                std::cout << "Con " << puntos << " puntos hay " << p << "\n";
            }
        }catch (std::domain_error e) {
            std::cout << "ERROR: " << e.what() << "\n";
        }
        std::cin >> linea;
    }
    std::cout << "---\n";

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
