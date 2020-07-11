// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(int jefes, int nRama, int altura) {
    
	int nPrec = 0;
	for(int i = 0; i < nRama; i++){
		int rama;
		std::cin >> rama;
		if(rama != 0)
			nPrec = nPrec + resolver(jefes, rama, altura + 1);
		else if(altura >= jefes)
			nPrec++;
	}
	return nPrec;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int jefes, raiz;
	
	std::cin >> jefes >> raiz;
	
    if (! std::cin)
        return false;
    
	if(raiz == 0)
		std::cout << "0" << "\n";
	else
		std::cout << resolver(jefes, raiz, 1) << "\n";
    
    // escribir sol
    
    
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
