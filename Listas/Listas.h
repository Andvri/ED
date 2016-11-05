#ifndef LISTAS_H
#define LISTAS_H
#include <iostream>
#include "Nodo.h"
typedef unsigned int size;

template <typename T>
class ListaCSE{
	
};
template <typename T>
class ListaCDE{
	
};


template <typename T>
class ListaSE{
	private:
		Nodo<T> *cabeza;//Apunta al inicio de la lista
		Nodo<T> *cola;//Apunta al ultimo elemento de la lista
		size size;//Indica la cantidad de elementos de la lista
		
		
		
		
		void addVacia(T e){
			this->cabeza=new Nodo<T>(e);
				this->cola=this->cabeza;this->size++;
			
		}
		
	public:
		/*
		Constructor Base para lista vacia
		*/
		ListaSE(){
			this->cabeza=this->cola=0;
			this->size=0;
		}
		
		
		/*
		 Agrega un elemento T al final o al inicio de la lista.
		 Utilizar true para add al final
		 Predefinido add al inicio
		*/
		
		
		void add(T e,bool end=false){
			
			if(vacia()){
				addVacia(e);
				return;
			}
			
			switch(end){
				case false:{
					this->cabeza=new Nodo<T>(e,this->cabeza);
					break;
				}
				case true:{
					Nodo<T>*aux=new Nodo<T>(e);
					this->cola->siguiente(aux);
					this->cola=this->cola->siguiente();
					break;
				}
			}
			
			
			
			this->size++;
				
		}
		/*
		 Agrega un elemento T despues de un elemento de la lista.
		 Si no lo encuentra lo agrega al final
		*/
		void add(T add,T des){
			
			
			
			
			
		}
		/*
		 Agrega un elemento T despues de una posicion dada.
		 Si la posicion es mayor a this->size lo agrega al final
		 Si la posicion es negativa lo agrega al inicio
		*/
		void add(T add,unsigned int Pos){
	
		}
		
	
	
		
		/*
			Muestra Los elementos de la lista 
		*/
		void visualizar(){
			Nodo<T> *prueba=this->cabeza;
			for(int a=0;a<size;a++){
				std::cout<<(a+1)<<"-"<<prueba->datNodo()<<std::endl;
				prueba=prueba->siguiente();	
			}
		}
		bool vacia(){
			return !(this->size);
		}
		
	
};






template <typename T>
class ListaDE{
	
};




#endif
