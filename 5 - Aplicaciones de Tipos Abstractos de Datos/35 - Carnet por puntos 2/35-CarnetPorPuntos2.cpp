// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>
#include "hashmap_eda.h"


class carnet {
public:

    void nuevo(std::string dni) {

        if (conductor.count(dni) > 0)
            throw std::domain_error("Conductor duplicado");
        m_puntos[15].push_front(dni);
        conductor[dni].puntos = 15;
        conductor[dni].tLista = m_puntos[15].begin();

    }

    void quitar(std::string dni, int puntos) {

        if (conductor.count(dni) == 0)
            throw std::domain_error("Conductor inexistente");

        if (conductor[dni].puntos > 0) {
            int nuevos = conductor[dni].puntos - puntos;
            m_puntos[conductor[dni].puntos].erase(conductor[dni].tLista);
            if (nuevos < 0) {
                m_puntos[0].push_front(dni);
                conductor[dni].puntos = 0;
                conductor[dni].tLista = m_puntos[0].begin();
            }
            else {
                m_puntos[nuevos].push_front(dni);
                conductor[dni].puntos = nuevos;
                conductor[dni].tLista = m_puntos[nuevos].begin();
            }
        }

    }

    void recuperar(std::string dni, int puntos) {

        if (conductor.count(dni) == 0)
            throw std::domain_error("Conductor inexistente");

        if (conductor[dni].puntos < 15) {
            int nuevos = conductor[dni].puntos + puntos;
            m_puntos[conductor[dni].puntos].erase(conductor[dni].tLista);
            if (nuevos > 15) {
                m_puntos[15].push_front(dni);
                conductor[dni].puntos = 15;
                conductor[dni].tLista = m_puntos[15].begin();
            }
            else {
                m_puntos[nuevos].push_front(dni);
                conductor[dni].puntos = nuevos;
                conductor[dni].tLista = m_puntos[nuevos].begin();
            }
        }

    }

    int consultar(std::string dni) {

        if (conductor.count(dni) == 0)
            throw std::domain_error("Conductor inexistente");
        return conductor.at(dni).puntos;

    }

    int cuantos_con_puntos(int puntos) {

        if (puntos < 0 || puntos > 15)
            throw std::domain_error("Puntos no validos");
        return m_puntos[puntos].size();

    }

    std::list<std::string>  lista_por_puntos(int puntos) {

        if (puntos < 0 || puntos > 15)
            throw std::domain_error("Puntos no validos");
        return m_puntos[puntos];
    }

private:
    struct infoConductor {
        int puntos;
        std::list<std::string>::iterator tLista;
    };
    unordered_map<std::string, infoConductor> conductor;
    unordered_map<int, std::list<std::string>> m_puntos;
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
            else if (linea == "recuperar") {
                std::string dni;
                int puntos;
                std::cin >> dni >> puntos;
                c.recuperar(dni, puntos);
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
            else if (linea == "lista_por_puntos") {
                int puntos;
                std::cin >> puntos;
                std::list<std::string> lista = c.lista_por_puntos(puntos);
                std::cout << "Tienen " << puntos << " puntos: ";
                for (auto const& it : lista)
                    std::cout << it << " ";
                std::cout << "\n";
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
