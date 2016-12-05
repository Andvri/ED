#include "Nodo.h"
#include <iostream>

template <typename T>
class ColaC{
private:
		T*V;
		int tam,inicial,ingresados;
public:
		ColaC():tam(1),inicial(0),ingresados(0){}
		ColaC(const ColaC<T> &A){
			*this=A;
		}	
		ColaC(int t):tam(t),inicial(0),ingresados(0){
			this->V=new T[this->tam];
		}
	
		
		~ColaC(){
			delete []V;
		}
		void Put(T obj){
			if(ingresados==tam)
				return;

			this->V[ (inicial +ingresados)%tam]=obj;
			(ingresados++);

		}

		int size(){
			return this->tam;
		}
		int Extract(T &obj){
	

			if(ingresados==0)
			return 0;
				

				ingresados--;
		obj=this->V[inicial];
		inicial=(inicial+1)%tam;
		return 1;
		}

		void Visualizar(){
			if(ingresados==0)
			return;
			
			
			
			int print=inicial;
			for(int i=0;i<ingresados;i++)
			{
				if(print==(tam) )
				print =0;
				
				
				
				
				std::cout<<this->V[print]<<std::endl;
				print++;
				
			}
			
			
		}
		
		bool Vacia(){
			if(ingresados==0)
			return true;
			
			
			
			return false;
		}
		
		
		bool LLena(){
			if(ingresados==tam)
			return true;
			
			
			return false;
		}

		
};

template <typename T>
class ColaN{
	private:
		Nodo<T> *cabeza;
	
		int size;
	public:
		ColaN(){
			this->cabeza=0;
			this->size=0;
		}
		void Put(T Obj){
			if(!this->cabeza){
				this->cabeza=new Nodo<T>(Obj);
				size++;
				return;
			}
				
				
			Nodo<T> *aux=this->cabeza;	
			while(aux->siguiente()!=0){
				aux=aux->siguiente();
			}
			
				aux->siguiente( new Nodo<T>(Obj) );
					size++;
		}		
		
		void Visualizar(){
			Nodo<T> *aux=this->cabeza;	
			int col=0;
			
			while(aux!=0){
				
				std::cout<<col++<<")"<<aux->datNodo()<<std::endl;
				aux=aux->siguiente();
				
				
			}
			
		}
		
		void Extract(T &obj){
			if(!size)
			return;
			obj=this->cabeza->datNodo();
			Nodo<T> *aux=this->cabeza;
			this->cabeza=this->cabeza->siguiente();
			delete aux;
			size--;
			
		}
		int TAM(){
			return this->size;
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

template <typename T>
class Cola{
	private:
		T *v;
		int size,cant;
		
	public:
		Cola(){
			this->v=new T[1];
			this->cant=this->size=0;
			
		}
		Cola(int t){
			this->v=new T[t];
			this->size=t;
			this->cant=0;
		}
		
		
		~Cola(){
			delete []v;
		}
		
		void Put(T obj){
			if(cant>=size)
			return;
			this->v[this->cant++]=obj;
		
		
		
		}
		
		
		void Extract(T &obj){
			if(!cant)
			return;
			obj=this->v[0];
			for(int i=0;i<cant;i++)
			this->v[i]=this->v[i+1];
			
			
			cant--;
		}
		
		
		void Visualizar(){
			if(!cant)
			return;
			
			for(int i=cant;i>=0;i--)
			std::cout<<this->v[i]<<std::endl;
			
		}
		
	
	
	
	
};
