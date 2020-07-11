// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "queue_eda.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int nAlumnos, salto;
	std::cin >> nAlumnos >> salto;
    if (nAlumnos == 0 && salto == 0)
        return false;
	
	queue<int> alumnos;
	for(int i = 0; i < nAlumnos; i++)
		alumnos.push(i+1);
	
	int alumAux, saltoAux = salto;
	while(alumnos.size() > 1){
		alumAux = alumnos.front(); // Coge el primero y lo elimina
		alumnos.pop();
		if(saltoAux > 0){ // Si NO es el necesario lo vuelve a meter
			alumnos.push(alumAux);
			saltoAux--;
		}
		else // Si SI es el que quiere, vuelve a empezar a saltar
			saltoAux = salto;
	}
	std::cout << alumnos.front() << "\n";
	
	
    return true;
    
}

int main() {
	
	/*
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    */
    
    while (resuelveCaso())
        ;

    /*
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    */
	 
    return 0;
}
