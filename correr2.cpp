//# include "heapSemaforo.cpp"
#include "djk.cpp"
const int numeroDeHabilitaciones = 10;
const int maximoPorSemaforo = 10;
//const int tamano_arcos = 420;
//const int num_listas= 64;

int arreglo [5] = {2,3,4,5,6};
class Correr  {
	private:
		heapSemaforos t;
		Vehiculos vehiculo;
		bool yaPaseVehiculo;
		int numeroIteracion;
		int obtenerUbicacion;
		int obtenerDestino;
		
	public:
		 Correr(heapSemaforos* );
		int getNumeroIteracion();
		void habilitarSemaforo(heapSemaforos* );
		void habilitarVehiculos(Semaforo* , heapSemaforos*);
		void setPonerTodos(heapSemaforos*);
		
};

	Correr::Correr(heapSemaforos* t){
		bool yaPaseVehiculo= false;
		numeroIteracion=0;
	//	this.t=t;
	t;
	}
	

int Correr::getNumeroIteracion(){
	for( int i=0; i<t.size() ; i++){
			if( t.recorre(i).getYaPase() == true){
				numeroIteracion++;
				t.recorre(i).setYaPase();
				return numeroIteracion -1;
		}
	}
}

void Correr::habilitarSemaforo(heapSemaforos* t){
	for(int i=0;  i< t->size() - t->lugaresDisponibles() ;i ++){
			if(t->recorre(i).getYaPase() == false){
				habilitarVehiculos(&t->recorre(i) , t);
				t->recorre(i).setYaPase();
			}
	}
}
	
			
void Correr::habilitarVehiculos(Semaforo* semaforoActual , heapSemaforos* t){
			//obtenerDestino= arreglo[0];
			
	for(int i=0 ; i< numeroDeHabilitaciones ; i++   ){
		if(semaforoActual->getCantDeVehiculos() >0){

			obtenerDestino= semaforoActual->getHeap().recorrer(0).porAcaVoy(); /// aca va el arreglo de fabrito
				if( t->recorre(obtenerDestino).getCantDeVehiculos() < maximoPorSemaforo ){
					vehiculo= semaforoActual->eliminaVehiculos();
						if(vehiculo.get_final() != t->recorre(obtenerDestino).getUbicacion()){
							t->recorre(obtenerDestino).insertar(vehiculo);
							obtenerUbicacion= t->recorre(obtenerDestino).getUbicacion();
							vehiculo.set_origen(obtenerUbicacion);
				}
			}else {
				cout <<" Vehiculo eliminado"<<endl;
			}
		}	
	}
}

void Correr::setPonerTodos(heapSemaforos* t){
	for(int i=0;  i< t->size() - t->lugaresDisponibles(); i ++){
			t->recorre(i).setYaPase();
	}
}

/*
class Nodo {
	public:
	Edge dato;
	Nodo *next;
	Nodo (Edge numero, Nodo *next_ptr=NULL){
		dato=numero, next= next_ptr;
	}
	Nodo *getNext (){return next;
	}
};

class Lista{
	private:
		Nodo *cabeza;
	//	Nodo *cabeza1;
		int contador;
	
		
		
	public:
		Lista(){
			cabeza=NULL;
			contador=0;
		//	*cabeza1=*cabeza;
		}
		void agregar(Edge);
		void mostrar();
		int getDest();
		int getSource();
		int tamList();
		int recorrerDest();
		int pesos(int);
		int destinos(int);
		int getContador();
};

int Lista::pesos(int i){
	Nodo *aux;
	aux= cabeza;
	int pesos[5];
	for(int j=0 ; j<5 ; j++){
		if(cabeza != NULL){
			pesos [j] = cabeza->dato.get_weight();
			cabeza=cabeza->next;
		}
	}
	cabeza=aux;
	return pesos [i];
}

int Lista::destinos(int i){
	Nodo *aux;
	aux= cabeza;
	int dest[5];
	for(int j=0 ; j<5 ; j++){
		if(cabeza != NULL){
			dest [j] = cabeza->dato.get_dest();
			cabeza=cabeza->next;
		}
	}
	cabeza=aux;
	return dest [i];	
}

int Lista::getDest(){
	Nodo *aux;
	

	aux=cabeza;
	
	if(cabeza!=NULL){

		return aux->dato.get_dest();

	}
	

}

int Lista::getSource(){
	Nodo *aux;
	aux=cabeza;
		if(cabeza!=NULL){
		return cabeza->dato.get_source();

	cabeza=cabeza->next;

	}
	cabeza=aux;
}

	void Lista::agregar(Edge edge){
		cabeza= new Nodo(edge, cabeza);
		contador++;

	}
	
	int Lista::getContador(){
		return contador;
	}
	
		int Lista::tamList(){
	Nodo *aux;
	aux=cabeza;
		if (cabeza!=NULL){
			
			cabeza=cabeza->next;
		 contador++;
		//	cout<< contador<<endl;
		
		tamList();
	
}
	cabeza=aux;
	}
	
	void Lista::mostrar(){
		
//int contador1=0;
		Nodo *aux;
		aux=cabeza;
		if (cabeza!=NULL){
		
		cout<<"("<< cabeza->dato.get_source()<<", ";
		cout<< cabeza->dato.get_dest()<<", ";
		cout<< cabeza->dato.get_weight()<<" )";
		
		cabeza=cabeza->next;
	//	contador1++;
	//	cout<< contador1<<endl;;
		mostrar();
	

	}
	cabeza=aux;
	//	cabeza=cabeza1;
}
/*
int main(){

	Lista *l= new Lista();	
   	Lista a[num_listas];
   	Vehiculos v;
   	heapSemaforos t;
   	heapVehiculos g;
   	Semaforo s;//=  Semaforo(e); 
   	Vehiculos arveh[20];
	

int numeroo, arregloo[100], qq;
int h=0;
int k = 0;
int q=0,arreglo[tamano_arcos],numero; 


ifstream archivo("ficheroTexto.txt"); 
if(archivo.good()){ 
while(archivo>>numero) 

arreglo[q++]=numero;	

}

ifstream archivoo("ficheroAutos1.txt"); 
if(archivoo.good()){ 
while(archivoo>>numeroo) 

arregloo[qq++]=numeroo;
}
int ggg=0;
for(int j=0;j<qq;j++) {
	Vehiculos v;

		v.set_patente(arregloo[j]);
		v.set_origen(arregloo[j+1]);
		v.set_final(arregloo[j+2]);
		v.set_prioridad(arregloo[j+3]);
		

		arveh[ggg]=v;
		j=j+3;
		ggg++;	
//	df.djistra(v.get_origen(), v.get_final());
//	df.print(v.get_origen());
	
	}


	

for(int j=0;j<q;j++) {
	
	Edge e;



e.set_source(arreglo[j]);
e.set_dest(arreglo[j+1]);
e.set_weight(arreglo[j+2]);


s= Semaforo (e);

	int contador=0;
for(int i=0; i<20;i++){

	if(arveh[i].get_origen()== s.getUbicacion() && arveh[i].estado()==false){
		s.insertar(arveh[i]);

			e.set_weight(s.getCantDeVehiculos());

		arveh[i].activarAdentro();
		}

		

	}
	


if (e.get_source()==arreglo[j-3]||e.get_source()==1)
{

	l->agregar(e);
	a[k]=*l;

}
else
{
	k++;
	
	Lista *l1=new Lista();
	l1->agregar(e);
	a[k]= *l1;
	l =l1;

}


j=j+2;

t.insert(s);
s.insertar(v);

}


cout<<endl;
cout<< "Soy ciudad :"<<endl;

for(int i=0; i<64; i++){
	
	a[i].mostrar();
	cout<<endl;

	}
	cout<<endl<<endl<<endl;
cout<< " lista Semaforos mas cargados " <<endl;
t.print();
	
cout<<endl<<endl<<endl;
Correr c(&t);
cout<< "Numero iteracion "<< c.getNumeroIteracion()<<endl;;

//heapSemaforos &tt = t;
c.habilitarSemaforo(&t);
cout<<" habilite semaforos "<< endl;
t.print();


}*/
