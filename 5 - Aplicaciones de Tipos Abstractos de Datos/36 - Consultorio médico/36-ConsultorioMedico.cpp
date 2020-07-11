// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>
#include "fecha.h"
#include "hashmap_eda.h"
#include "treemap_eda.h"


class consultorio {
public:
    void nuevoMedico(std::string m) {
        m_medicos.insert({ m, {} });
    }

    void pideConsulta(std::string p, std::string m, fecha f) {
        if (m_medicos.count(m) == 0)
            throw std::domain_error("Medico no existente");
        if (m_medicos[m].count(f) > 0)
            throw std::domain_error("Fecha ocupada");
        m_medicos[m].insert({f, p});
    }

    std::string siguientePaciente(std::string m) {
        if (m_medicos.count(m) == 0)
            throw std::domain_error("Medico no existente");
        if (m_medicos[m].size() == 0)
            throw std::domain_error("No hay pacientes");
        return m_medicos[m].begin()->valor;
    }

    void atiendeConsulta(std::string m) {
        if (m_medicos.count(m) == 0)
            throw std::domain_error("Medico no existente");
        if (m_medicos[m].size() == 0)
            throw std::domain_error("No hay pacientes");
        m_medicos[m].erase(m_medicos[m].begin()->clave);
    }

    std::list<std::pair<std::string, fecha>> listaPacientes(std::string m, int d) {
        std::list < std::pair<std::string, fecha>> l;
        if (m_medicos.count(m) == 0)
            throw std::domain_error("Medico no existente");
        for (auto const& it : m_medicos[m]) {
            if (it.clave.getDia() == d)
                l.push_back({it.valor, it.clave});
        }
        return l;
    }


private:
    // Clave: medico. Valor: mapa con clave: fecha valor: paciente
    unordered_map<std::string, map<fecha, std::string>> m_medicos;
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    if (! std::cin)
        return false;

    std::string linea;
    consultorio c;

    for (int i = 0; i < n; i++) {
        std::cin >> linea;
        try {
            if (linea == "nuevoMedico") {
                std::string m;
                std::cin >> m;
                c.nuevoMedico(m);
            }
            else if (linea == "pideConsulta") {
                std::string med, p;
                char x;
                int d, h, m;
                std::cin >> p >> med >> d >> h  >> x >> m;
                fecha f = fecha(d, h, m);
                c.pideConsulta(p, med, f);
            }
            else if (linea == "siguientePaciente") {
                std::string m, p;
                std::cin >> m;
                p = c.siguientePaciente(m);
                std::cout << "Siguiente paciente doctor " << m << "\n";
                std::cout << p << "\n";
            }
            else if (linea == "atiendeConsulta") {
                std::string m;
                std::cin >> m;
                c.atiendeConsulta(m);
            }
            else if (linea == "listaPacientes") {
                std::string m;
                int d;
                std::cin >> m >> d;
                std::list<std::pair<std::string, fecha>> l = c.listaPacientes(m, d);
                std::cout << "Doctor " << m << " dia " << d << "\n";
                for (auto const& it : l) {
                    std::cout << it.first << " ";
                    it.second.mostrar();
                    std::cout << "\n";
                }

            }
        }catch (std::domain_error e) {
            std::cout << e.what() << "\n";
        }
        std::cin.ignore();
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
