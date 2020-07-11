// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "horas.h"
#include "pelicula.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    
	int n;
	std::cin >> n;
	std::vector<pelicula> v;
	pelicula aux;
	
	if(n == 0)
		return false;
	
	for(int i = 0; i < n; i++){
		std::cin >> aux;
		v.push_back(aux);
	}
	
	std::sort(v.begin(), v.begin()+ n);
	
	for(int i = 0; i < n; i++){
		try{
			std::cout << v[i] << "\n";
		} catch (std::invalid_argument &ia){
			std::cout << ia.what() << "\n";
		}
	}
	std::cout << "---\n";
    
    return true;
    
}

int main() {
	
	
    
    while (resuelveCaso())
        ;

   
	 
    return 0;
}
