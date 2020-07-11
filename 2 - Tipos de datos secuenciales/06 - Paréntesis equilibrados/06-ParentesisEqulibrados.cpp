// ALVARO BERZOSA TORDESILLAS
// E09

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "stack_eda.h"

// función que resuelve el problema
bool equilibrado(stack<char> &pila) {
    
	char ultimo = pila.top();
	pila.pop();
	
	if(pila.empty())
		return false;
	else if(ultimo == ']' && pila.top() == '[')
		pila.pop();
	else if(ultimo == ')' && pila.top() == '(')
		pila.pop();
	else if(ultimo == '}' && pila.top() == '{')
		pila.pop();
	else
		return false;
	
	return true;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	std::string cadena;
	getline(std::cin, cadena);
	
	if (! std::cin)
	return false;
	
	stack<char> pila;
	bool ok = true;
	for(int i = 0; i < cadena.size() && ok; i++){
		if(cadena[i] == '(' || cadena[i] == '{' || cadena[i] == '[')
			pila.push(cadena[i]);
		if(cadena[i] == ')' || cadena[i] == '}' || cadena[i] == ']'){
			pila.push(cadena[i]);
			ok = equilibrado(pila);
		}
		
	}
    
    if(ok && pila.empty())
		std::cout << "SI \n";
	else
		std::cout << "NO \n";

    
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
