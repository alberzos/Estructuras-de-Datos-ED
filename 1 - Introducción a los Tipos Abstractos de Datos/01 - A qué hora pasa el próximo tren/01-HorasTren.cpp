// Alvaro Berzosa Tordesillas
// Usuario del juez: F08

#include <iostream>
#include <fstream>
#include <vector>
#include "horas.h"


bool resuelveCaso(){
	int n, h;
	std::cin >> n >> h;
	
	if(n == 0 && h == 0)
		return false;
	
	std::vector<horas> v;
	horas aux, sol;
	bool haySol = false;
	for(int i = 0; i < n; i++){
		std::cin >> aux;
		v.push_back(aux);
	}
	for(int i = 0; i < h; i++){
		try{
			std::cin >> aux;
			haySol = false;
			for(int f = 0; f<v.size() && !haySol; f++){
				if(v[f].proximoTren(aux, sol)){
					haySol = true;
					std::cout << sol << "\n";
				}
			}
			if(!haySol)
				std::cout << "NO\n";
		} catch(std::invalid_argument &ia){
			std::cout << ia.what() << "\n";
		}
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
    
    
	while(resuelveCaso());

    /*
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    */
	
    return 0;
}

