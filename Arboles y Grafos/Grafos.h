#include <iostream>
#include "../DString.h"
#include "../Nodo\Nodo.h"
#include "../Listas\Listas.h"


template <typename T>
class Grafo{
	private:
		ListaSE<T> *Vertices;
		bool Dir;
		bool Pes;
		size_t CantV;
		float **Aristas;
		
		void LoadFile(DString file){
			
			
			
			
			
			
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
	public:
		Grafo(DString file,bool Dir,bool Pes){
			this->Dir=Dir;
			this->Pes=Pes;
			Vertices=new ListaSE<T>(false);
			this->LoadFile(file);
			this->CantV=0;
		}
		Grafo(bool Dir,bool Pes){
			Vertices=new ListaSE<T>(false);
			this->Dir=Dir;
			this->Pes=Pes;
			this->CantV=0;
		}
	
		void AddVertice(T ver){
			this->Vertices->Add(ver,true);
			this->CantV++;
			
			
		}
		void VerVertices(){
			this->Vertices->visualizar();
		}
		void AddArista(T verI,T verLL,float dis){
			int posI=this->Vertices->Buscar(verI);
			int posLL=this->Vertices->Buscar(verLL);
			
			if(posI==-1 || posLL==-1)
			std::cout<<"Algun vertice o Ambos no existe"<<std::endl;
			
			std::cout<<"Vertice "<<verI<<" Pos "<<posI<<" dis "<< dis<<" Vertice "<<verLL<<" Pos "<<posLL<<std::endl; 
			
		}
		
};

