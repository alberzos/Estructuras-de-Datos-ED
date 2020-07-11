//
//  duplicarLista.h
//  ED
//
//  Created by Álvaro Berzosa on 24/02/2020.
//  Copyright © 2020 Álvaro Berzosa. All rights reserved.
//

#ifndef duplicarLista_h
#define duplicarLista_h

#include <iostream>
#include "queue_eda.h"

template <class T>
class duplicarLista: public queue<T> {
	using Nodo = typename queue<T>::Nodo;
	
public:
	void duplicar(){
		Nodo *aux = this->prim;
		while(aux != nullptr){
			Nodo *nuevo = new Nodo(aux->elem, aux->sig);
			if(nuevo->sig == nullptr)
				this->ult = nuevo;
			aux->sig = nuevo;
			aux = aux->sig->sig;
		}
		this->nelems = this->nelems * 2;
	}
};

template <class T>
inline std::ostream& operator<<(std::ostream &o, duplicarLista<T> &l){
	for(int i = 0; i < l.size(); i++){
		int aux = l.front();
		o << aux << " ";
		l.push(aux);
		l.pop();
	}
	return o;
}

#endif /* duplicarLista_h */
