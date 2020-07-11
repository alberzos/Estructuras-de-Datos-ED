/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 */

/*
 * Nombre y apellidos: Alvaro Berzosa Tordesillas
 */

#include <iostream>
#include <fstream>
#include "queue_eda.h"

template<typename T>
class queue_move_segment: public queue<T> {
private:
  using Nodo = typename queue<T>::Nodo;

private:
  // Declara aquí métodos auxiliares, si
  // los necesitas

public:
  
  // Implementa aquí el método pedido
  void move_segment_left(int pos_ini, int pos_fin) {

      Nodo* actual = this->prim;
      Nodo* primer = this->prim;
      Nodo* actualAnt = nullptr;

      if (pos_ini != pos_fin && (pos_ini < this->nelems && pos_ini > 0) && (pos_fin < this->nelems && pos_fin >0)) {
          //Recorrer la cola hasta que llega a pos_ini
          for (int i = 0; i < pos_ini; i++) {
              if (i == pos_ini - 1)
                  actualAnt = actual;
              actual = actual->sig;
          }
          Nodo* auxIni = actual; // aux ya tiene la posicion inicial
          Nodo* actualSig = nullptr;
          // Recorre desde pos_ini a pos_fin-1 para tener el ultimo que se mueve
          for (int j = pos_ini; j < pos_fin - 1; j++) {
              actual = actual->sig;
          }
          actualSig = actual->sig; // Coge el siguiente al ultimo que se va a mover para luego poder enlazarlo con el anterior al primero
          Nodo* auxFin = actual; //auxFin tiene la pos final


          actualAnt->sig = actualSig;
          this->prim = auxIni;
          auxFin->sig = primer;
      }

  }


  // Método para imprimir una cola por pantalla
  void display(std::ostream &out) const {
    Nodo *act = this->prim;
    if (act != nullptr) {
      out << act->elem;
      act = act->sig;
      while (act != nullptr) {
        out << " " << act->elem;
        act = act->sig;
      }
    }
  }  
};

// Sobrecarga del operador << parao colas.
// Si quieres imprimir una cola 'q' puedes hacer: cout << q << "\n";
template<typename T>
std::ostream & operator<<(std::ostream &out, const queue_move_segment<T> &q) {
  q.display(out);
  return out;
}

using namespace std;

// Función para leer los casos de entrada y llamar al método
// move_segment_left sobre cada uno de ellos.
void tratar_caso() {
  // Implementar
    int n, i, j;
    cin >> n >> i >> j;

    queue_move_segment<int> cola;
    int aux;
    for (int x = 0; x < n; x++) {
        cin >> aux;
        cola.push(aux);
    }

    cola.move_segment_left(i, j);
    cola.display(cout);
    cout << "\n";

}

int main() {
#ifndef DOMJUDGE
  std::ifstream in("sample.in");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
  
  int num_casos;
  std::cin >> num_casos;

  for (int i = 0; i < num_casos; i++) {
    tratar_caso();
  }

#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  // Descomentar si se trabaja en Windows
  // system("PAUSE");
#endif
  return 0;
}

// SALT: 0584770152