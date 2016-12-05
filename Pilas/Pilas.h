#include <iostream>
#include "Nodo.h"


/*
Tipo de dato Dato que se almacena en la pila
Operaciones
CrearPila Inicia la pila.
Insertar (push) Pone un dato en la pila.
Quitar (pop) Retira (saca) un dato de la pila.
Pilavacía Comprobar si la pila no tiene elementos.
Pilallena Comprobar si la pila está llena de elementos.
Limpiar pila Quita todos sus elementos y dejar la pila vacía.
CimaPila Obtiene el elemento cima de la pila.
Tamaño de la pila Número de elementos máximo que puede contener la pila.


*/

template <typename T>
class Pila{
	private:
		int size;
		int apilados;
		T *v;
		
	public:
		
		Pila(){
			this->v=new T[1];
			this->size=1;
			this->apilados=0;
		}
		Pila(int i){
			this->size=i;
			this->v=new T[this->size];
			this->apilados=0;
		}
		~Pila(){
			delete []v;
		}
		void Put(T obj){
			if(size==apilados)
			return;
			
			this->v[this->apilados++]=obj;
			
			
			
			
			
		}
		void Extract(T &obj){
			if(!apilados)
			return;
			
			obj=this->v[--this->apilados];
		//	this->apilados--;
			
		}
		bool Vacia(){
			return this->apilados==0;
		}
		bool Llena(){
			return this->apilados==this->size;
		}
		
		void Visualizar(){
			for(int i=0;i<apilados;i++)
			std::cout << this->v[i] << std::endl;
			
			
		}
		
		
		
	
	
	
	
};


template <typename T>
class PilaD{
	private:
		Nodo<T> *cabeza;
		int size;
		
	public:
		PilaD(){
			this->cabeza=0;
			this->size=0;
			
			
		}
		
		void Put(T obj){
			if(cabeza==0){
				cabeza=new Nodo<T>(obj);
				size++;
				return;
			}
			
			
			Nodo<T>*aux=new Nodo<T>(obj);
			aux->siguiente(this->cabeza);
			this->cabeza=aux;
			size++;
			
			
			
			
		}
		
		
		void Extract(T &obj){
			if(!size)
			return;
			
			
			
			Nodo<T> *aux=this->cabeza;
			obj=aux->datNodo();
			
			this->cabeza=this->cabeza->siguiente();
			
			delete aux;
			size--;
			
		}
		
		
		
		
		int TAM(){
			return this->size;
		}
		
		
			
		void Visualizar(){
			int i=0;
			Nodo<T> *aux=this->cabeza;
			while(aux!=0){
					std::cout <<i<<")" << aux->datNodo() << std::endl;
					aux=aux->siguiente();
					i++;
			}
		
			
			
		}
	
		
		
		void Delete(){
			T obj;
			while(this->cabeza!=0)
			this->Extract(obj);
		}		
		
		bool Vacia(){
			return this->TAM()==0;
		}	
	
	
	
	
	
	
	
	
	
};
