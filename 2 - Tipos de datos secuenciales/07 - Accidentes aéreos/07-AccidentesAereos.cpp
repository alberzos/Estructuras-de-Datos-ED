// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "stack_eda.h"

struct accidente {
	std::string fecha;
	int victimas;
};

std::vector<std::string> resolver(const std::vector<accidente> &v){
	
	std::vector<std::string> sol;
	stack<accidente> p;
	
	for(int i = 0; i < v.size(); i++){
		while(!p.empty() && (p.top().victimas <= v[i].victimas))
			p.pop();
		if(p.empty())
			sol.push_back("NO HAY");
		else
			sol.push_back(p.top().fecha);
		p.push(v[i]);
	}
	
	return sol;
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n;
	std::vector<accidente> v;
	accidente aux;
	std::vector<std::string> sol;

	std::cin >> n;
	
	if (! std::cin)
		return false;
	
	for(int i = 0; i < n; i++){
		std::cin >> aux.fecha >> aux.victimas;
		v.push_back(aux);
	}
	
	sol = resolver(v);
	for(int i = 0; i < sol.size(); i++)
		std::cout << sol[i] << "\n";
	std::cout << "--- \n";
    
	return true;
}

int main() {
	
    
    while(resuelveCaso());

    
	
    return 0;
}
