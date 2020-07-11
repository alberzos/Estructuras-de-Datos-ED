//
//  invertirLista.h
//  ED
//
//  Created by Álvaro Berzosa on 26/02/2020.
//  Copyright © 2020 Álvaro Berzosa. All rights reserved.
//

#ifndef invertirLista_h
#define invertirLista_h



#include <iostream>
#include "queue_eda.h"

template <class T>
class invertirLista: public queue<T> {
	using Nodo = typename queue<T>::Nodo;
	
public:
	void invertir(){
		Nodo *actual = this->prim;
		Nodo *anterior = nullptr;
		Nodo *siguiente = nullptr;
		
		while(actual != nullptr){
			siguiente = actual->sig;
			actual->sig = anterior;
			anterior = actual;
			actual = siguiente;
		}
		Nodo *aux = this->prim;
		this->prim = this->ult;
		this->ult = aux;
	}
};

template <class T>
inline std::ostream& operator<<(std::ostream &o, invertirLista<T> &l){
	for(int i = 0; i < l.size(); i++){
		int aux = l.front();
		o << aux << " ";
		l.push(aux);
		l.pop();
	}
	return o;
}


#endif /* invertirLista_h */
