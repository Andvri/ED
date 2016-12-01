#ifndef LISTAS_H
#define LISTAS_H
#include <iostream>
#include "Nodo.h"

template <typename T>
class ListaCSE{
	
};
template <typename T>
class ListaCDE{
	
};


template <typename T>
class ListaSE{
	protected:
		Nodo<T> *cabeza;//Apunta al inicio de la lista
		Nodo<T> *cola;//Apunta al ultimo elemento de la lista
		size_t size;//Indica la cantidad de elementos de la lista
		bool  repe;
		
		
		
		void addVacia(T e){
			this->cabeza=new Nodo<T>(e);
				this->cola=this->cabeza;this->size++;
			
		}
		void addF(T e){
			this->cabeza=new Nodo<T>(e,this->cabeza);
			this->size++;
			
		}
		void addE(T e){
			Nodo<T>*aux=new Nodo<T>(e);
			this->cola->siguiente(aux);
			this->cola=this->cola->siguiente();
			this->size++;
		}
		
	public:
		/*
		Constructor Base para lista vacia
		*/
		ListaSE(bool band=true){
			this->cabeza=this->cola=0;
			this->size=0;
			this->repe=band;
		}
		
		/*
		 Agrega un elemento T al final o al inicio de la lista.
		 Utilizar true para add al final
		 Predefinido add al inicio
		*/
		void Add(T e,bool end=false){
			
			if(vacia()){
				addVacia(e);
				return;
			}
			if(this->Buscar(e)!=-1)
			return;
			
			switch(end){
				case false:{
					addF(e);			
					break;
				}
				case true:{
					addE(e);
					break;
				}
			}
			
			
			
		
				
		}
		
		/*
		 Agrega un elemento T despues de un elemento de la lista.
		 Si no lo encuentra lo agrega al final
		*/
		void Add(T e,T des,bool a){
			if(vacia()){
				addVacia(e);
				return;
			}
			
			
			
			
		}
		
		/*
		 Agrega un elemento T despues de una posicion dada.
		 Si la posicion es mayor a this->size lo agrega al final
		 Si la posicion es negativa lo agrega al inicio
		*/
		void Add(T e,int  Pos){
			
			if(vacia()){
				addVacia(e);
				return;
			}
			
			if(this->Buscar(e)!=-1)
			return;
			
			if(Pos<=0){
				addF(e);
				return;
			}		
			
			if(Pos>=this->size){
				addE(e);
				return;
			}		
			
			Nodo<T>*aux=new Nodo<T>(e);
			Nodo<T>*aux2=this->cabeza;
			for(int i=0;i<Pos-1;i++){
				aux2=aux2->siguiente();
			}
			aux->siguiente(aux2->siguiente());
			aux2->siguiente(aux);
			this->size++;
			aux=aux2=0;
			delete aux;
			delete aux2;
		}
		
		/*
			Muestra Los elementos de la lista 
		*/
		void visualizar(){
			Nodo<T> *prueba=this->cabeza;
			for(int a=0;a<size;a++){
				std::cout<<(a)<<"-"<<prueba->datNodo()<<std::endl;
				prueba=prueba->siguiente();	
			}
		}
		
		/*
			Identifica si la pila esta vacia
		*/
		bool vacia(){
			return !(this->size);
		}
		
		/*
			Muestra el tamanio de la lista
		*/
		unsigned int dim(){
			return this->size;
		}
		
		/*
		
		
		*/
		void Delete(int pos=0 ){
			
			if(pos<0 ||  pos>this->size-1 )	
				return;
			
					
			Nodo<T>*aux=this->cabeza;
			if(!pos){
				
				this->cabeza=this->cabeza->siguiente();
				delete aux;
				this->size--;
				return;				
			}
			
			
			
			
			
			aux=this->cabeza;
			for(int i=0;i<pos-1;i++){
				aux=aux->siguiente();				
			}
			Nodo<T>*aux2=aux->siguiente();
			aux->siguiente(aux2->siguiente());
			if(this->size-1==pos)
			this->cola=aux;
			
			delete aux2;
			this->size--;
			

		}	
		
		
		T Get(int pos=0){
			T obj;
			if(pos<0 ||  pos>this->size-1 )	
				return obj;
			
			if(!pos)
			return this->cabeza->datNodo();
			
			if(this->size-1==pos)
			return this->cola->datNodo();
			Nodo<T> *aux=this->cabeza;

			for(int i=0;i<pos;i++)
			aux=aux->siguiente();
			
			return aux->datNodo();
			
		}
		
		void colear(){
			std::cout<<this->cola->datNodo()<<std::endl;
		}
		
		int Buscar(T bus){
			if(this->repe)
			return -1;
			
			Nodo<T> *prueba=this->cabeza;
			for(int a=0;a<size;a++){
				if(bus==prueba->datNodo()){

					return a;
				}
					prueba=prueba->siguiente();	
				
			}
			
			return -1;
		}
		
		
	
};

template <typename T>
class ListaSEO:public ListaSE<T> {
	private:
	
	public:
		void Add(T e,bool end=false){
			
			if(this->vacia() ){
				this->addVacia(e);
				return;
			}
			Nodo<T> *aux=this->cabeza;
			Nodo<T> *aux2= new Nodo<T>(e);
			
			if(this->cabeza->datNodo()>=aux2->datNodo()){
				this->addF(e);
				return;
			}
			
			while(true){
				if(aux->siguiente()!=0 ){
					if(aux->siguiente()->datNodo()>=aux2->datNodo() ){
						aux2->siguiente(aux->siguiente());
						aux->siguiente(aux2);
						this->size++;
						return;
					}else
						aux=aux->siguiente();
					
					
				}else
					break;
				
				
				
			}
			this->addE(e);
			
			
			
			
		
				
		}
		
		
	
	
};




template <typename T>
class ListaDE{
	private:
		Nodo<T> *cabeza;//Apunta al inicio de la lista
		Nodo<T> *cola;//Apunta al ultimo elemento de la lista
		size_t size;//Indica la cantidad de elementos de la lista
		
		void addF(T e){
			Nodo<T>*aux=new Nodo<T>(e,this->cabeza);
			this->cabeza->anterior(aux);
			this->cabeza=aux;
			this->size++;
			
		}
		void addE(T e){
			Nodo<T>*aux=new Nodo<T>(e,0,this->cola);
			
			this->cola->siguiente(aux);
			this->cola=this->cola->siguiente();
			this->size++;
		}
		void addV(T e){
			Nodo<T>*aux=new Nodo<T>(e);
			this->cabeza=aux;
			this->cola=aux;
			this->size++;
				
		}
		
		
	public:
		
		ListaDE(){
			this->cabeza=this->cola=0;
			size=0;
				
		}
		
		
		bool Vacia(){
			return this->size==0;
		}
		int TAM(){
			return this->size;
		}
		
		void Add(T e,bool first =true){
		
			if(Vacia()){
			
				this->addV(e);
				return;	
			}
			switch(first){
				case true:{
					this->addF(e);
					break;
				}
				case false:{
					this->addE(e);
					break;
				}
					
		
			}
		}
		
		void Put(T e,int pos){
			if(Vacia()){
				this->addV(e);	
				return;
			}
			if(!pos){
				this->addF(e);
				return;
			}
			if(pos>=size){
				this->addE(e);
				return;
			}
			
			Nodo<T> *aux=new Nodo<T>(e);
			Nodo<T> *mov=this->cabeza;
			for(int i=0;i<pos-1;i++){
				mov=mov->siguiente();
				
			}
			aux->anterior(mov);
			aux->siguiente(mov->siguiente());
			Nodo<T> *aux2=mov->siguiente();
			aux2->anterior(aux);
			mov->siguiente(aux);
			size++;
			
			
			
		}
		
		void Extract(T &obj,int pos=0){
			if(pos<0 || pos>=size)
			return;
			
			
			Nodo<T> *aux=this->cabeza;
			for(int i=0;i<pos;i++){
				aux=aux->siguiente();
			}
			obj=aux->datNodo();
			
		}
		
		
		void Delwte(int pos=0){
			
		}
		
		
		void Visualizar(){
			int k=0;
			Nodo<T>*aux=this->cabeza;
			while(true){
				
				std::cout<<k<<")"<<aux->datNodo()<<std::endl;
				k++;
				if(aux->siguiente()==0)
				break;
				
				
				aux=aux->siguiente();
				
				
			}
			
			
			
		}
	
};




#endif
