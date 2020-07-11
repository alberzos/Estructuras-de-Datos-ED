/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *               Segundo examen parcial
 * ---------------------------------------------------
 */
 
/*
 * Nombre y apellidos: ALVARO BERZOSA TORDESILLAS
 */ 

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;



void resolver(const bintree<int>& tree, int altura, int& nivelMayor, int& elem) {
    if (!tree.empty()) {
        if (tree.root() % altura == 0 && (nivelMayor == 0 || nivelMayor < altura)) {
            elem = tree.root();
                nivelMayor = altura;
        }
        resolver(tree.left(), altura + 1, nivelMayor, elem);
        resolver(tree.right(), altura + 1, nivelMayor, elem);

    }
}
// Implementa aquí la función pedida. Puedes definir las funciones
// auxiliares que necesites
//
// COSTE: O(n), donde n es el número de nodos del árbol de entrada.
// Es coste lineal pues se pasa una vez por cada nodo
// 
int nodo_bien_colocado(const bintree<int>& tree) {
  
    // Implementar
    int elem = -1;
    int altura = 1;
    int nivelMayor = 0;
    resolver(tree, altura, nivelMayor, elem);
    return elem;

}





// Función para leer los casos de entrada y llamar a la función pedida
// sobre cada uno de ellos.
void tratar_caso() {
  bintree<int> tree = leerArbol(-1);
  cout << nodo_bien_colocado(tree) << endl;
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

// SALT: 47438573532146812835