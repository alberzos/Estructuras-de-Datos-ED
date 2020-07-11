/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 */

/*
 * Solución al ejercicio:
 * Mover un segmento al principio de una lista enlazada simple
 */

#include <iostream>
#include <fstream>
#include <cassert>
#include "queue_eda.h"

template<typename T>
class queue_move_segment: public queue<T> {
private:
  using Nodo = typename queue<T>::Nodo;

private:
  // Declara aquí métodos auxiliares, si
  // los necesitas

  Nodo * nth_node(int index) {
    Nodo *result = this->prim;

    for (int i = 0; i < index; i++) {
      result = result->sig;
    }

    return result;
  }

public:
  
  // Implementa aquí el método pedido
  void move_segment_left(int pos_ini, int pos_fin) {
    assert (0 <= pos_ini && pos_ini <= pos_fin && pos_fin <= this->nelems);

    // Si el segmento comienza al principio o es vacío, no hacemos nada.
    if (pos_ini == 0 || pos_ini == pos_fin) return;
    
    // ant_ini: Nodo anterior al que comienza el segmento
    // ultimo: Ultimo nodo del segmento a mover
    Nodo *ant_ini = nth_node(pos_ini - 1);
    Nodo *ultimo = nth_node(pos_fin - 1);

    Nodo *ini = ant_ini->sig;
    ant_ini->sig = ultimo->sig;
    ultimo->sig = this->prim;
    this->prim = ini;

    // Si el ultimo elemento del segmento es el último de la lista, hemos
    // de actualizar this->ult
    if (this->ult == ultimo) {
      this->ult = ant_ini;
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
  int n, pos_ini, pos_fin;
  cin >> n >> pos_ini >> pos_fin;

  queue_move_segment<int> q;
  for (int i = 0; i < n; i++) {
    int elem;
    cin >> elem;
    q.push(elem);
  }

  q.move_segment_left(pos_ini, pos_fin);

  cout << q << "\n";
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

// SALT: ##