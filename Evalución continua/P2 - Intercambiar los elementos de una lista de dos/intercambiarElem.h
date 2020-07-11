//
//  intercambiarElem.h
//  ED
//
//  Created by Álvaro Berzosa on 13/04/2020.
//  Copyright © 2020 Álvaro Berzosa. All rights reserved.
//

#ifndef intercambiarElem_h
#define intercambiarElem_h

#include <iostream>
#include "queue_eda.h"

template <class T>
class intercambiarElem: public queue<T> {
	using Nodo = typename queue<T>::Nodo;
	
public:
	void intercambiar(){
		Nodo *act = this->prim;
		Nodo *aux1 = act->sig;
		Nodo *aux2 = nullptr;
		if(aux1 != nullptr){
			aux2 = aux1->sig;
			this->prim->sig = aux2;
			aux1->sig = act;
			this->prim = aux1;
			if(aux2 == nullptr)
				this->ult = act;
			act = aux1->sig;
			aux1 = aux2;
		}
		while(aux1 != nullptr && aux1->sig != nullptr){
			aux2 = aux1->sig;
			Nodo *tmp = aux2->sig;
			aux2->sig = aux1;
			aux1->sig = tmp;
			act->sig = aux2;
			act = aux1;
			aux1 = tmp;
			if(tmp == nullptr)
				this->ult = act;
		}
	}
};

template <class T>
inline std::ostream& operator<<(std::ostream &o, intercambiarElem<T> &l){
	for(int i = 0; i < l.size(); i++){
		int aux = l.front();
		o << aux << " ";
		l.push(aux);
		l.pop();
	}
	return o;
}

#endif /* intercambiarElem_h */
