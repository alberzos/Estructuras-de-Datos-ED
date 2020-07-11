// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "treemap_eda.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int ejercicios;
	std::cin >> ejercicios;
	
    if (ejercicios == 0)
        return false;
    // Clave: nombre   Valor: nota
	map<std::string, int> notas;
	std::string nombre, nota, aux;
	getline(std::cin, aux);
	for(int i = 0; i < ejercicios; i++){
		
		getline(std::cin, nombre);
		getline(std::cin, nota);
		
		notas.insert({nombre, 0});
		if(nota == "CORRECTO")
			notas[nombre]++;
		else
			notas[nombre]--;
	}
    
    // escribir sol
	for(auto cv: notas){
		if(cv.valor != 0)
			std::cout << cv.clave << ", " << cv.valor << "\n";
	}
	std::cout << "--- \n";
	
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
