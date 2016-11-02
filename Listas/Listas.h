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
		Nodo<T> *cabeza;
		Nodo<T> *cola;
		size size;
		
	public:
		ListaSE(){
			this->cabeza=this->cola=0;
			this->size=0;
		}
		
		
		
		void add(T e){
			if(this->cabeza!=0){
			this->cabeza=new Nodo<T>(e,this->cabeza);
			}
			else{
				this->cabeza=new Nodo<T>(e);
				this->cola=new Nodo<T>(e);
			}
			
			
			this->size++;	
		}
		void visualizar(){
			Nodo<T> *prueba=this->cabeza;
			for(int a=0;a<size;a++){
				std::cout<<prueba->datNodo()<<std::endl;
				prueba=prueba->siguiente();	
			}
		}
		void Cola(){
			std::cout<<this->cola->datNodo()<<std::endl;
		}
	
};






template <typename T>
class ListaDE{
	
};




#endif
