/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *                    Examen final
 * ---------------------------------------------------
 */
 
/*
 * Nombre y apellidos: ALVARO BERZOSA TORDESILLAS
 */ 


#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "hashmap_eda.h"
#include "treemap_eda.h"

using namespace std;

class academia_chino {
public:
  // Definiciones públicas ¡No olvides el coste!
    // Coste O(1) solo se accede a la posicion indicada
    void nuevo_estudiante(string nombre, int grupo) {
        if (alumnos.count(nombre) || m_graduados.count(nombre))
            throw domain_error("Estudiante existente");
        if (grupo > 6 || grupo < 1)
            throw domain_error("Grupo incorrecto");
        niveles[grupo].push_front(nombre);
        alumnos[nombre] = { grupo, false, niveles[grupo].begin() };
    }

    // Coste O(1) solo se accede a la posicion indicada
    int grupo_estudiante(string dni) {
        if (!alumnos.count(dni))
            throw domain_error("Estudiante no existente");
        if (m_graduados.count(dni))
            throw domain_error("Estudiante ya graduado");
        return alumnos[dni].curso;
    }

    // Coste O(1) solo se accede a la posicion indicada
    void promocionar(string dni) {
        if (!alumnos.count(dni))
            throw domain_error("Estudiante no existente");
        if (m_graduados.count(dni))
            throw domain_error("Estudiante ya graduado");
        int grupo = alumnos[dni].curso;
        if (grupo == 6) {
            m_graduados[dni] = { true };
            niveles[grupo].erase(alumnos[dni].it);
            alumnos[dni].graduado = true;
            alumnos[dni].curso = 0;
        }
        else {
            niveles[grupo].erase(alumnos[dni].it);
            niveles[grupo + 1].push_front(dni);
            alumnos[dni].curso = grupo + 1;
            alumnos[dni].it = niveles[grupo + 1].begin();
        }
    }

    // Coste O(n) recorre todos los graduados una vez
    list<string> graduados() {
        list<string> lista;
        auto it = m_graduados.begin();
        while (it != m_graduados.end()) {
            lista.push_back(it->clave);
            ++it;
        }
        return lista;
    }

    // Coste O(1) solo accede a la posicion requerida
    string novato(int grupo) {
        if (grupo < 1 || grupo > 6)
            throw domain_error("Grupo incorrecto");
        if (niveles[grupo].empty())
            throw domain_error("Grupo vacio");
        return niveles[grupo].front();
    }

private:    
  // Definiciones privadas
    struct alumno {
        int curso;
        bool graduado;
        list<string>::iterator it;

    };
    map<string, bool> m_graduados;
    unordered_map<string, alumno> alumnos;
    list<string> niveles[7];

};

bool tratar_caso() {
  academia_chino ac;
  string comando;
  cin >> comando;
  if (cin.eof()) return false;

  while (comando != "FIN") {
    try {
      if (comando == "nuevo_estudiante") {
        string dni;
        int grupo;
        cin >> dni >> grupo;
        ac.nuevo_estudiante(dni, grupo);
      } else if (comando == "grupo_estudiante") {
        string dni;
        cin >> dni;
        int grupo = ac.grupo_estudiante(dni);
        cout << dni << " esta en el grupo " << grupo << "\n";
      } else if (comando == "promocionar") {
        string dni;
        cin >> dni;
        ac.promocionar(dni);
      } else if (comando == "graduados") {
        list<string> graduados = ac.graduados();
        cout << "Lista de graduados:";
        for (const string &s: graduados) {
          cout << " " << s;
        }
        cout << "\n";
      } else if (comando == "novato") {
        int grupo;
        cin >> grupo;
        string novato = ac.novato(grupo);
        cout << "Novato de " << grupo << ": " << novato << "\n";
      }
    } catch (std::domain_error &e) {
      cout << "ERROR: " << e.what() << "\n";
    }

    cin >> comando;
  }
  cout << "---\n";
  
  return true;
} // tratar_caso

int main() {
#ifndef DOMJUDGE
  std::ifstream in("sample.in");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
  
  while (tratar_caso()) {  }

#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  // Descomentar si se trabaja en Windows
  // system("PAUSE");
#endif
  return 0;
}

// SALT: 628650790876069539270641116048