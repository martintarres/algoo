#include <iostream>
#include <math.h>

#include "Nodo1.cpp"
#include "heapVehiculos.cpp"
#include <string.h> 
#include <stdlib.h> 
#include <fstream> 


using namespace std;

//const int cant=10;
class Semaforo {//: public heapVehiculos{
private:
	int cantVehiculos;
	bool verde;
	bool mano;  // si se puede avanzar en esa direccion, es mano = true;
	int ubicacion;
	int origen;
	heapVehiculos h;
//	Vehiculos *v;
	bool fueVisitado;
	bool yaPaseSemaforo;
public: 
	Semaforo(){
		cantVehiculos=-1;
		 h;
		fueVisitado=false;
		bool yaPaseeSemaforo=false;
	}
	Semaforo(Edge e);
	int getCantDeVehiculos();
	void setCantDeVehiculos(int);
	bool esMano();
	bool ponerVerde(); //pone en verde. A su vez da un booleano que ayuda a saber su estado;
	int getUbicacion();
	int getOrigen();
	void insertar(Vehiculos);
	Vehiculos eliminaVehiculos();
	heapVehiculos getHeap();
	 void setFuiVisitado();
	bool getFuiVisitado();
	bool getYaPase();
	void setYaPase();
	

	
	
};

Semaforo::Semaforo(Edge e)
		{
		ubicacion = e.get_dest();
		origen=e.get_source();
		cantVehiculos = e.get_weight();
		verde = false;
		mano = false;
		h;
		fueVisitado=false;
		bool yaPaseSemaforo=false;
	}

int Semaforo::getCantDeVehiculos()
{
	return cantVehiculos;
}

int Semaforo::getUbicacion()
{
	return ubicacion;
}

int Semaforo::getOrigen(){
	return origen;
}

bool Semaforo::ponerVerde()   //Saca el verde si está en verde y al revés.
{
	if (verde){
		verde = false;
	}else {
		verde = true;
	}
	return verde;
}

bool Semaforo::esMano()
{
	if(mano){
		return true;
	}else
	return false;

}

void Semaforo::setCantDeVehiculos(int cant){
	cantVehiculos=cant;
	
}

void Semaforo::insertar(Vehiculos v){
	h.insert(v);
	if(cantVehiculos == 999999999){
	cantVehiculos= 0;
	cantVehiculos++;
	
	}else {

	cantVehiculos++;
	}
}

Vehiculos Semaforo::eliminaVehiculos(){
	Vehiculos v;
	v= h.eliminar();
	cantVehiculos--;
	return v;
}

heapVehiculos Semaforo::getHeap(){
	return h;
}
void Semaforo::setFuiVisitado(){
	if(fueVisitado=true){
		fueVisitado=false;
	}else {
		fueVisitado=true;
	}
}

bool Semaforo::getFuiVisitado(){
	return fueVisitado;
}

bool Semaforo::getYaPase(){
	return yaPaseSemaforo;
}

void Semaforo::setYaPase(){
	if(yaPaseSemaforo == false){
		yaPaseSemaforo = true;
	}else {
		yaPaseSemaforo= false;
	}
}

/*


int main()
{
	Edge e =  Edge(5,10,20);
	Semaforo s=  Semaforo(e);
	Semaforo s1= Edge();
//	heapVehiculos h;
 	Vehiculos v;
 	v.set_origen(1);
 	v.set_final(2);
 	v.set_patente(0);
 	v.set_prioridad(0);
 		Vehiculos v1;
 	v1.set_origen(1);
 	v1.set_final(9);
 	v1.set_patente(1);
 	v1.set_prioridad(1);
 	
 	s.insertar(v);
 	s.insertar(v1);
 	s1.insertar(v);
 	s1.insertar(v1);
 	cout<< "semaforo 1 "<<endl;
 	s.getHeap().print();
 		cout<< "semaforo 2 "<<endl;
 	s1.getHeap().print();
 	s.eliminaVehiculos();
 	s1.eliminaVehiculos();
 	cout<< "semaforo 1 despues de eliminar "<<endl;
 	s.getHeap().print();
 		cout<< "semaforo 2 despues de eliminar "<<endl;
 		s1.getHeap().print();
 	
 	
 //	s.print();
 }
/*	cout << s.getUbicacion() << endl;
	cout << "está activado? :" << s.ponerVerde()<< s.ponerVerde() << s.ponerVerde() << endl;
	*/
//}

//int Semaforo::getCantDeVehiculos()*/
