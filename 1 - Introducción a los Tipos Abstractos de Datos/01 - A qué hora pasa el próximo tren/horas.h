//
//  horas.h
//  ED


#ifndef horas_h
#define horas_h


#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stdexcept>


class horas{
	int hora, minutos, segundos;
	
	bool proximaHora(const horas &horaLlegada, const horas &horarioEstacion) const {
		return horarioEstacion < horaLlegada;
	}
	
public:
	//CONSTRUCTORES
	horas(){
		hora = 0;
		minutos = 0;
		segundos = 0;
	}
	
	horas(int h, int m, int s) {
		hora = h;
		minutos = m;
		segundos = s;
		
		if(s < 0 || s > 59)
			throw std::invalid_argument("ERROR");
		else if (m < 0 || m > 59)
			throw std::invalid_argument("ERROR");
		else if (h < 0 || h > 23)
			throw std::invalid_argument("ERROR");
	}
	//FIN CONSTRUCTORES
	
	bool operator<(const horas &h) const{
		if(hora < h.hora)
			return true;
		else if(hora > h.hora)
			return false;
		else if(minutos < h.minutos)
			return true;
		else if(minutos > h.minutos)
			return false;
		else if(segundos < h.segundos)
			return true;
		else
			return false;
	}
	
	int getHora() const{
		return hora;
	}
	
	int getMinutos() const{
		return minutos;
	}
	
	int getSegundos() const{
		return segundos;
	}
	
	bool proximoTren(const horas &h, horas &horaPartida) const{
		if(!proximaHora(h, *this)){
			horaPartida = *this;
			return true;
		}
		return false;
	}
};


inline std::istream& operator >>(std::istream &in, horas &hora){
	int h, m, s;
	char aux;
	
	in >> h >> aux >> m >> aux >> s;
	hora = horas(h,m,s);
	
	return in;
}

inline std::ostream& operator <<(std::ostream &out, horas const &h){
	out << std::setfill('0') << std::setw(2) << h.getHora() << ":" <<
	std::setfill('0') << std::setw(2) << h.getMinutos() << ":" <<
	std::setfill('0') << std::setw(2) << h.getSegundos();

	return out;
}


#endif /* horas_h */
