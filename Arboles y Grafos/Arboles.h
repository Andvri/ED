#ifndef ARBOLES_H
#define ARBOLES_H
#include "Nodo.h"

#include <iostream>
template <typename T>
class ArbolBinarioB{
	private:
	Nodo<T> *raiz;
	unsigned int Nivel;
	
	void Ver(Nodo<T>*e,int level=0){
				
				if(e->siguiente()!=0){
					std::cout<<level<<")"<<e->siguiente()->datNodo()<<std::endl;
					Ver(e->siguiente(),level+1);
				}
				
				if(e->anterior()!=0){
				
					std::cout<<level<<")"<<e->anterior()->datNodo()<<std::endl;
					Ver(e->anterior(),level+1);
				
				}
				
				
			}

	
	void Add(T e,Nodo<T>*Ev){
			if(Ev->datNodo()==e)
			return;
			if(Ev->datNodo() > e){
				
				if(Ev->siguiente()==0){
				
					Ev->siguiente(new Nodo<T>(e));
					this->Nivel++;
				
				}else{
					Add(e,Ev->siguiente());
				}
				
			}else{

				if(Ev->anterior()==0){
				
					Ev->anterior(new Nodo<T>(e));
					this->Nivel++;
				
				}else{
					Add(e,Ev->anterior());
				}
				
				
				
			}
		}
				
		
	public:
	ArbolBinarioB(){
		this->raiz=0;
		this->Nivel=0;
	}
	
	
	
	
	void Put(T e,bool der=true){
		if(!this->Nivel){
			this->Nivel++;
			this->raiz=new Nodo<T>(e);
			return;
		}
		Add(e,this->raiz);	
	}
		
			void Imprimir(){
				std::cout<<"0)"<<this->raiz->datNodo()<<std::endl;
				Ver(this->raiz,1);
			}	
		
		
		
		
	
	
	
	
	
	
	
	
};







#endif
