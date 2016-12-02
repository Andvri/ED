#include <iostream>
#include "../DString.h"
#include "../Nodo\Nodo.h"
#include "../Listas\Listas.h"
#include "../Colas\Colas.h"


template <typename T,typename U=float>
class Grafo{
	private:
		ListaSE<T> *Vertices;
		bool Dir;
		bool Pes;
		size_t CantV;
		void  **Aristas; // ListaSE<ListaSE<U>*> Aristas o U **Aristas
		
		void LoadFile(DString file){
			
			
			
			
			
			
		}
		void RAnchura(){
		}
		void RProfundidad(){
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
		void AddArista(T verS,T verLL,U dis){
			int posS=this->Vertices->Buscar(verS);
			int posLL=this->Vertices->Buscar(verLL);
			
			if(posS==-1 || posLL==-1)
			std::cout<<"Algun vertice o Ambos no existe"<<std::endl;
			
		}
		/*
			Recorrido del grafo
			
			-Saliendo desde cualquier vertice se inicia la navegacion pasando por los adyacentes no visitados,
			asi sucesivamente hasta acabar la totalidad o llegar a un punto de finalizacion
			
			Tipos de recorrido:
			
			1) Anchura (Cola Auxiliar)
			2) Profundidad (Pila Auxiliar)
			
			Matriz de adyacencia o multilista	
			Vector de Marca
			
		
		*/
		void Recorrido(DString mode="Anchura"){
			if(mode=="Anchura")
			RAnchura();
			else
			RProfundidad();
		}
		
		// Floyd-Wharshall
		
		
		
		
		
		
		
};

