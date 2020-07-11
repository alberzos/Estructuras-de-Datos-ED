//
//  insertarElem.h
//  ED
//
//  Created by Álvaro Berzosa on 02/03/2020.
//  Copyright © 2020 Álvaro Berzosa. All rights reserved.
//

#ifndef insertarElem_h
#define insertarElem_h



#include <iostream>
#include "queue_eda.h"

template <class T>
class insertarElem: public queue<T> {
	using Nodo = typename queue<T>::Nodo;
	
public:
	void insertar(const int pos, insertarElem<T> &lista){
		Nodo *nAct = this->prim;
		for(int i = 0; i < pos - 1 && nAct->sig != nullptr; i++)
			nAct = nAct->sig;
		Nodo *tmp = nAct->sig;
		if(pos == 0){
			if(nAct->sig == nullptr)
				this->ult = nAct;
			lista.ult->sig = nAct;
			nAct = lista.prim;
			this->prim = nAct;
		}
		else{
			nAct->sig = lista.prim;
			lista.ult->sig = tmp;
			if(tmp == nullptr)
				this->ult = lista.ult;
		}
		
		this->nelems = this->nelems + lista.size();
		lista.prim = nullptr;
		lista.ult = nullptr;
	}
};

template <class T>
inline std::ostream& operator<<(std::ostream &o, insertarElem<T> &l){
	for(int i = 0; i < l.size(); i++){
		int aux = l.front();
		o << aux << " ";
		l.push(aux);
		l.pop();
	}
	return o;
}


#endif /* insertarElem_h */
