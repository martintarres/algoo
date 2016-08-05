#include "correr2.cpp"
#include <iostream>
//#include<iostream>
//using namespace std;

int main(){
	
Lista *l= new Lista();	
   	Lista a[num_listas];
   	Vehiculos v;
   	heapSemaforos t;
   	heapVehiculos g;
   	Semaforo s;//=  Semaforo(e); 
   	Vehiculos arveh[20];
//   	grafo df;

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
	
	t.print();
	
	Dijkstra p ; //= Dijkstra();
	
		int origen =0;
	  	int final =0;
//	for(int i=0; i<1; i++){
	//	cout << "semaforo: " << i << endl;
	//	for(int j=0; j<1; j++){
	//	Dijkstra p;
		origen = t.recorre(0).getHeap().recorrer(0).get_origen();
		final = t.recorre(0).getHeap().recorrer(0).get_final();
		cout <<" origen " << origen;
		cout << "final " << final << endl;
				
	//	p.dijkstra(a, origen , final); 
	//	cout<< v.getPrev(t.recorre(0).getHeap().recorrer(0));
	//	t.print();
		static Correr c(&t);
		c.habilitarSemaforo(&t);
		c.setPonerTodos(&t);
		t.print();
		c.habilitarSemaforo(&t);
		t.print();
		
}
