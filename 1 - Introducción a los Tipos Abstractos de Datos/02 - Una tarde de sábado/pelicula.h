//
//  pelicula.h
//  ED
//
//  Created by Álvaro Berzosa on 23/02/2020.
//  Copyright © 2020 Álvaro Berzosa. All rights reserved.
//

#ifndef pelicula_h
#define pelicula_h

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stdexcept>
#include "horas.h"

class pelicula {
	horas horaIni, duracion;
	std::string titulo;
	
public:
	pelicula(){
		titulo = "";
		horaIni = horas();
		duracion = horas();
	}
	
	pelicula(std::string nombre, horas ini, horas fin){
		titulo = nombre;
		horaIni = ini;
		duracion = fin;
	}
	
	bool operator<(const pelicula &p) const {
		if((horaIni + duracion) < (p.getIni() + p.getDuracion()))
			return true;
		else if((p.getIni() + p.getDuracion()) < (horaIni + duracion))
			return false;
		else if(titulo < p.getTitulo())
			return true;
		else
			return false;
	}
	
	horas getIni() const{
		return horaIni;
	}
	
	horas getDuracion() const{
		return duracion;
	}
	
	horas getFin() const{
		return horaIni + duracion;
	}
	
	std::string getTitulo() const{
		return titulo;
	}
};

inline std::ostream& operator <<(std::ostream &out, pelicula const &p){
	out << p.getFin() << " " << p.getTitulo();
	return out;
}

inline std::istream& operator >>(std::istream &in, pelicula &p){
	horas ini, dur;
	std::string tit;
	
	in >> ini >> dur;
	std::getline(in, tit);
	p = pelicula(tit, ini, dur);
	return in;
}
#endif /* pelicula_h */
