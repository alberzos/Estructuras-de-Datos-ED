// ALVARO BERZOSA TORDESILLAS
// F08

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "list_eda.h"


class supermercado{
public:
	//Constructor
	supermercado(): num_cajas(0) {}

	supermercado(int num_cajas): num_cajas(num_cajas) {}
	
	// O(n) siendo n el tamaño del vector de clientes_cola
	void nuevo_cliente(std::string cod_cliente, int num_cola){
		if(num_cola > num_cajas)
			throw std::domain_error("Cola inexistente");
		else {
			bool ok = false;
			for(int i = 0; i < clientes_cola.size(); i++){
				if(cod_cliente == clientes_cola[i].cod) // El cliente ya esta creado
					ok = true;
			}
			if(ok) //Cliente ya registrado -> Error
				throw std::domain_error("Cliente duplicado");
			else{
				clientes_cola.push_back({cod_cliente, num_cola});
				superMer[num_cola].push_back(cod_cliente);
			}
		}
	}
	
	// O(n) siendo n el tamaño del vector de clientes_cola
	void cambiar_cola(std::string cod_cliente, int num_cola){
		if(num_cola >= num_cajas)
			throw std::domain_error("Cola inexistente");
		else{
			int cola_antigua = consultar_cliente(cod_cliente);
			// se borra de la cola en la que estaba
			if(cola_antigua != num_cola){
				bool ok = false;
				for(auto i = superMer[cola_antigua].begin(); i != superMer[cola_antigua].end() && !ok; ++i){
					if(*i == cod_cliente){
						superMer[cola_antigua].erase(i);
						ok = true;
					}
				}
				// se añade a la que ha ido
				superMer[num_cola].push_back(cod_cliente);
				for(int i = 0; i < clientes_cola.size(); i++){
					if(clientes_cola[i].cod == cod_cliente)
						clientes_cola[i].cola = num_cola;
				}
			}
		}
	}
	
	// O(n) siendo n el tamaño del vector de clientes_cola
	int consultar_cliente(std::string cod_cliente){
		int cola = 0;
		bool ok = false;
		for(int i = 0; i < clientes_cola.size(); i++){
			if(cod_cliente == clientes_cola[i].cod){
				ok = true;
				cola = clientes_cola[i].cola;
			}
		}
		if(!ok)
			throw std::domain_error("Cliente inexistente");
		return cola;
	}
	
	// O(1)
	int cuantos_en_cola(int num_cola){
		if(num_cola > num_cajas)
			throw std::domain_error("Cola inexistente");
		else
			return superMer[num_cola].size();
	}
	
	// O(1)
	list<std::string> clientes_en_cola(int num_cola){
		if(!superMer.count(num_cola))
			throw std::domain_error("Cola inexistente");
		 return superMer[num_cola];
	}
	
	
private:

	int num_cajas;
	
	struct info_cliente{
		std::string cod;
		int cola;
	};
	// Clave: numero de caja, Valor: lista de clientes en esa caja
	std::unordered_map<int, list<std::string>> superMer;
	// Vector para saber en que caja esta cada cliente
	std::vector<info_cliente> clientes_cola;
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
	int n;
	std::cin >> n;
	if (std::cin.eof())
        return false;
	
	supermercado sup(n);
	std::string comando;
	std::cin >> comando;
	while(comando != "FIN"){
		try{
			if(comando == "nuevo_cliente"){
				std::string cod_cliente;
				int num_cola;
				std::cin >> cod_cliente >> num_cola;
				sup.nuevo_cliente(cod_cliente, num_cola);
			}
			else if(comando == "cambiar_cola"){
				std::string cod_cliente;
				int num_cola;
				std::cin >> cod_cliente >> num_cola;
				sup.cambiar_cola(cod_cliente, num_cola);
			}
			else if(comando == "cuantos_en_cola"){
				int num_cola, n;
				std::cin >> num_cola;
				n = sup.cuantos_en_cola(num_cola);
				std::cout << "En la cola " << num_cola << " hay " << n << " clientes \n";
			}
			else if(comando == "clientes_en_cola"){
				int num_cola;
				std::cin >> num_cola;
				list<std::string> lista = sup.clientes_en_cola(num_cola);
				std::cout << "En la cola " << num_cola << " estan: ";
				while(!lista.empty()){
					std::cout << lista.back() << " ";
					lista.pop_back();
				}
				std::cout << "\n";
			}
			else if(comando == "consultar_cliente"){
				std::string cod_cliente;
				int n;
				std::cin >> cod_cliente;
				n = sup.consultar_cliente(cod_cliente);
				std::cout << "El cliente " << cod_cliente << " esta en la cola " << n << "\n";
			}
		}catch(std::domain_error e){
			std::cout << "ERROR: " << e.what() << "\n";
		}
		std::cin >> comando;
	}
	std::cout << "--- \n";
	
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
