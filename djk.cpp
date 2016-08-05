#include <iostream>
#include "heapSemaforo.cpp"
//using namespace std;

class Dijkstra{
	private:
		  
		int distancia[num_listas];
		int previo[num_listas];
		heapSemaforos t, t1;
		Semaforo auxiliar;
		int actual;
		bool visitado[num_listas];
		heapSemaforos q;
		int y;      
		int previoS[num_listas];        // 64  va guardando los previos solamente del auto solicitado;      
		void cargaPrevios(int);
		int p;
		
public:
	Dijkstra(){
		for(int i=0; i< num_listas; i++){	
		visitado[ i ] = false;
		distancia[i]=INF;
		previo[i]=-1;
		previoS[i] = -1;
		}
		t;
		int V;
		p = -1;
		
	}
	void dijkstra(Lista a[], int, int );
	void relajacion(int actual, int adyacente, int peso);
	void print (int);
	int getPrevios(int);
	int enviarArreglo(int);
	
};

void Dijkstra::dijkstra(Lista a[], int k, int y){
	Lista A[MAX];
	int adyacente;
	int peso;
	int x;
	
	Edge e(k, k, 0);
	Semaforo s(e);
	
	q.insert(s);
	distancia [0]= 0;
	distancia [k] = 0;
	
	while(q.size()-q.lugaresDisponibles() !=0)
	{
		actual = q.eliminarFondo().getUbicacion();
		if (visitado[actual] ) continue;
			visitado[actual] = true;
			for(int i= 0; i< a[actual - 1].getContador() ; i++){
				adyacente = a[actual-1].destinos(i);
				peso = a[actual-1].pesos(i);
				if(!visitado[adyacente]){
					relajacion(actual, adyacente, peso);
				}
			}
	}
	for (int l=0; l<6; l++){
		cout << "Vertice" << l<< endl;
		cout << "distancia l: " << distancia [l] << " " ;
		cout << "previo l: "<<previo [l];
		cout << endl;
	}
//	cout << "ingrese destino" << endl;
//	 cin >> x;			
	print(y);
	cargaPrevios(y);
//	enviarArreglo(y);
	cout << "arreglo de previos de x: " << endl;
	
	for (int k = 0; k< 5 ; k++){
	
	previoS[k];
	}
}

void Dijkstra::relajacion(int actual, int adyacente, int peso)
{
		if(distancia[actual] + peso < distancia[adyacente]){
			distancia[adyacente] = distancia [actual] + peso;
			previo [adyacente] = actual;
			Edge e(actual, adyacente, distancia[adyacente]);
			Semaforo s(e);
			q.insert(s);
		}	

}
void Dijkstra::print(int destino){
	
	if( previo[ destino ] != -1 )    //si aun poseo un vertice previo
        //print (previo [destino]);
		print( previo[ destino ] );  //recursivamente sigo explorando
    //printf("%d " , destino );   
	cout << destino << " ";
}
/*
int Dijkstra::enviarArreglo(int destino){
	int contador=0;
	if( previo[ destino ] != -1 )
		auxiliar.getHeap().recorrer(contador).llenarPrev(&previo[destino] , contador);
		contador++;
		enviarArreglo(previo[destino]);
}*/
void Dijkstra::cargaPrevios(int buscaprevio){
	p++ ;
	int l=0;
	if( previo[ buscaprevio ] != -1 ){    //si aun poseo un vertice previo
        l= previo[buscaprevio];
		previoS[p] = l;
		cargaPrevios( previo[ buscaprevio ] );
		}  
}
int Dijkstra::getPrevios(int y){
	return previoS[y];
	}

/*

int main(){
	


	Lista *l= new Lista();	
   	Lista a[num_listas];
   	Vehiculos v;
   	heapSemaforos t;
   	heapVehiculos g;
   	Semaforo s;//=  Semaforo(e); 
   	Vehiculos arveh[25];
   //	grafo df;

int numeroo, arregloo[100], qq;
int h=0;
int k = 0;
int q=0,arreglo[tamano_arcos],numero; 


ifstream archivo("ficheroTexto.txt"); 
if(archivo.good()){ 
while(archivo>>numero) 

arreglo[q++]=numero;	

}

ifstream archivoo("ficheroAutos.txt"); 
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
//t.print();

cout<<endl;
cout<< " ciudad :"<<endl;

for(int i=0; i<64; i++){
	
	a[i].mostrar();
	cout<<endl;
//	cout<<a[i].tamList()<<endl;
	}
//t.print();
	cout<<" t: " << endl;
 //a[0].mostrar();	
	//Dijkstra p;
//	t.print();
//	int kk;
	cout<<"inicial"<<endl;
	//cin>>kk;
//	int inicial;
//	cout<< " Ingrese semaforo incial "<<endl;
//	cin>>inicial;
	  int origen =0;
	  int final =0;
	for(int i=0; i<3; i++){
		cout << "semaforo: " << i << endl;
		for(int j=0; j<3; j++){
		Dijkstra p;
		origen = t.recorre(i).getHeap().recorrer(i).get_origen();
		final = t.recorre(i).getHeap().recorrer(i).get_final();
		cout <<" origen " << origen;
		cout << "final " << final << endl;
				
		p.dijkstra(a, origen , final); 
		
		}
	}
}

//	dijkstra(inicial);

*/
