#include <iostream>
#include <string.h> 
#include <stdlib.h> 
#include <fstream> 
#define TAM 64

//using namespace std;


class Vehiculos{
	private:
		int origen;
		int final;
		int prioridad;
		int patente;
		bool estoyAdentro;
		int previos[25];
		int contador;
		
	public:
		Vehiculos(){
			/*this->patente=patente;
			this->final=final;
			this->prioridad=prioridad;   //Sacamos la prioridad del constructor. A lo sumo agregarla de nuevo.
			this->origen=origen;*/
			origen=-1;
			final=-1;
			prioridad=-1;
			patente=-1;
			estoyAdentro=false;
			for(int i=0 ; i<27 ; i++){
				previos[i]= i+2;			
			} 
			contador=-1;
		}
		void set_origen(int);
		void set_final (int);
		void set_prioridad(int);
		void set_patente(int);
		int get_origen();
		int get_final();
		int get_patente();
		int get_prioridad();
		void activarAdentro();
		bool estado();
		void llenarPrev(int *pt,int i);
		int* getPrev(Vehiculos v);
		int porAcaVoy();
		

		
};

void Vehiculos::set_origen(int orig){
	origen=orig;
}

void Vehiculos::set_final(int fin){
	final=fin;	
}
	void Vehiculos::set_prioridad(int priori)
	{
		prioridad = priori;
	}
void Vehiculos::set_patente(int paten){
	patente=paten;
}
int Vehiculos::get_origen(){
	return origen;
}

int Vehiculos::get_final(){
	return final;
}
int Vehiculos::get_patente(){
	return patente;
}

int Vehiculos::get_prioridad(){
	return prioridad;
}

void Vehiculos::activarAdentro(){
	estoyAdentro=true;
}
bool Vehiculos::estado(){
	return estoyAdentro;
}

void Vehiculos::llenarPrev(int *pt,int i){
	
	previos[i]=*pt;
}

int* Vehiculos::getPrev(Vehiculos v){
	int *ptr_prev;
	ptr_prev=v.previos;
	return ptr_prev;
	
}

int Vehiculos::porAcaVoy(){
	contador ++;
	return previos[contador];
}
/*
int main(){   


int numero, arreglo[40], q;
ifstream archivo("ficheroAutos.txt"); 
if(archivo.good()){ 
while(archivo>>numero) 
arreglo[q++]=numero;

/*for(int i=0; i<q;i++){
	cout<<arreglo[i]<<endl;
}
*//*
for(int j=0;j<q;j++) {
	Vehiculos *v=new Vehiculos();
//	Vehiculos *v=new Vehiculos(arreglo[j],arreglo[j+1],arreglo[j+2],arreglo[j+3]);
		v->set_patente(arreglo[j]);
		v->set_origen(arreglo[j+1]);
		v->set_final(arreglo[j+2]);
		v->set_prioridad(arreglo[j+3]);
		
	cout<< "patente: "<< v->get_patente()<< endl;
	cout<< "origen: "<< v->get_origen()<< endl;
	cout<< "final: "<< v->get_final()<< endl;
	
	cout << "prioridad: " << v->get_prioridad() << endl;
	cout<<endl;
	j=j+3;
}}
    }//                                                 //	la clase main fue implementada
/*	const int max=6;												  // solo para hacer la prueba.
	for (int i=0; i<max;i++){										   //La saco para subirla a git y que 
		Vehiculos *v= new Vehiculos(00+i,i+1);						   //no tire errores.
		v->set_origen(i);
		v->set_prioridad(1);
	cout<< "origen: "<< v->get_origen()<< endl;
	cout<< "final: "<< v->get_final()<< endl;
	cout<< "patente: "<< v->get_patente()<< endl;
	
	
	if (i==3)
	{
		v->set_prioridad(0);
	}
	cout << "prioridad: " << v->get_prioridad() << endl;
	cout<<endl;
	*/
//}

//}





