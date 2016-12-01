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
			Vertices=new ListaSE<T>(true);
			this->LoadFile(file);
		}
		Grafo(bool Dir,bool Pes){
			Vertices=new ListaSE<T>(true);
			this->Dir=Dir;
			this->Pes=Pes;
		}
	
	
};
