// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "list_eda.h"
#include "queue_eda.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    
	int nelem, i = 0, v, aux;
	queue<int> lista;
	list<int> l;
	
	std::cin >> nelem;
	if(nelem == 0)
		return false;
	
	// Mete en una cola los datos de entrada
	for(int i = 0; i < nelem; i++){
		std::cin >> aux;
		lista.push(aux);
	}
	
	while(i < nelem){
		v = lista.front(); // Llama al primero y lo saca de la cola
		lista.pop();
		// Lo mete por el principio o final de la lista segun sea positivo o negativo
		if(v <= 0)
			l.push_front(v);
		else
			l.push_back(v);
		i++;
	}
	
	auto it = l.begin();
	while(it != l.end()){
		std::cout << *it << " ";
		it++;
	}
	std::cout << "\n";
    
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
