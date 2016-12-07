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
		
		
		void addVacia(){
			this->cabeza=new Nodo<T>();
			this->cola=this->cabeza;this->size++;
			
		}
		void addVacia(T e){
			this->cabeza=new Nodo<T>(e);
				this->cola=this->cabeza;this->size++;
			
		}
		void addF(){
			this->cabeza=new Nodo<T>(this->cabeza);
			this->size++;
			
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
		void generarNodos(int tam){
			this->cabeza=new Nodo<T>();
			Nodo<T> *aux=this->cabeza;
			for(int i=0;i<tam-1;i++){
				aux->siguiente(new Nodo<T>());
				aux=aux->siguiente();
			}
		}
		void generarNodos(int tam,T obj){
			this->cabeza=new Nodo<T>(obj);
			Nodo<T> *aux=this->cabeza;
			for(int i=0;i<tam-1;i++){
				aux->siguiente(new Nodo<T>(obj));
				aux=aux->siguiente();
			}
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
		
		ListaSE(int size,bool band=true){
			this->cabeza=this->cola=0;
			this->size=size;
			this->generarNodos(size);
			this->repe=band;
		}
		ListaSE(const T*v,int size,bool band=true){
			this->cabeza=this->cola=0;
			
			this->repe=band;
			for(int i=0;i<size;i++)
			this->Add(v[i],true);
		}
		ListaSE(int size,T obj,bool band=true){
			this->cabeza=this->cola=0;
			this->size=size;
			this->generarNodos(size,obj);
			this->repe=band;
		}
		
		/*
		 Agrega un elemento T al final o al inicio de la lista.
		 Utilizar true para add al final
		 Predefinido add al inicio
		*/
		void Add(T e,int end=false){
			
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
		void reDimensionar(int j=1){
			if(this->cabeza==0){
			this->cabeza=new Nodo<T>();
			this->size++;
			j--;
			}
			Nodo<T> *aux=this->cabeza;
			for(int i=1;i<this->size;i++){
				aux=aux->siguiente();
			}
			for(int i=0;i<j;i++){
				aux->siguiente(new Nodo<T>());
				this->size++;
				aux=aux->siguiente();
			}
			
		}
		
		void reDimensionar(T cop,int j=1){
			if(this->cabeza==0){
			this->cabeza=new Nodo<T>(cop);
			this->size++;
			j--;
			}
			Nodo<T> *aux=this->cabeza;
			for(int i=1;i<this->size;i++){
				aux=aux->siguiente();
			}
			for(int i=0;i<j;i++){
				aux->siguiente(new Nodo<T>(cop));
				this->size++;
				aux=aux->siguiente();
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
		void Put(int pos,T obj){
			
			if(vacia()){
				return;
			}
			if(pos>=this->size || pos<0 )
			return;
			
			
			Nodo<T>*aux=this->cabeza;
			for(int i=0;i<pos;i++)
			aux=aux->siguiente();
			
			
			aux->datNodo(obj);
			
			
		}
		
		void AddP(T e,int  Pos){
			
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
				if(a%10==0)
				std::cout<<std::endl;
				std::cout<<(a)<<")"<<prueba->datNodo()<<" ";
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
		
		
		T Get(int pos=0) const{
			T obj;
			if(pos<0 ||  pos>=this->size )	
				return obj;
			
			if(!pos)
			return this->cabeza->datNodo();
			
			Nodo<T> *aux=this->cabeza;

			for(int i=0;i<pos;i++)
			aux=aux->siguiente();
			
			return aux->datNodo();
			
		}
		
		void colear(){
			std::cout<<this->cola->datNodo()<<std::endl;
		}
		
		T* getArray()const{
				T *array;
				array=new T[this->size];
				Nodo<T>*aux=this->cabeza;
				
				for(int i=0;i<this->size;i++){
					array[i]=aux->datNodo();	
					aux=aux->siguiente();
					
				}
				return array;
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
		
	friend std::ostream& operator << (std::ostream &o,const ListaSE<T> &p)
	{
    Nodo<T> *aux=p.cabeza;
    int i=0;
	while(aux!=0){
    	if(i%10==0 && i!=0)
    	o<<"\n";
    	
		o<<i<<")"<<aux->datNodo()<<"\n";
    	aux=aux->siguiente();
    	i++;
	}
	
	
    return o;
	}
	
	friend std::ostream& operator << (std::ostream &o,const ListaSE<T> *p)
	{
		int i=0;
    Nodo<T> *aux=p->cabeza;
    while(aux!=0){
    	if(i%10==0 && i!=0)
    	o<<"\n";
    	
		o<<i<<")"<<aux->datNodo()<<"\n";
    	aux=aux->siguiente();
	i++;
	}
	
	
    return o;
	}
		
	ListaSE<T> & operator =(const ListaSE<T> &a){
				for(int i =0;i<a.size;i++){
					this->Add(a.Get(i),false);	
				}
			return *this;
		}

	
	
	
	
	
	
	
};

template <typename T>
class ListaSEO {
	protected:
		Nodo<T> *cabeza;//Apunta al inicio de la lista
		Nodo<T> *cola;//Apunta al ultimo elemento de la lista
		size_t size;//Indica la cantidad de elementos de la lista
		
		
		
		void addVacia(){
			this->cabeza=new Nodo<T>();
			this->cola=this->cabeza;this->size++;
			
		}
		void addVacia(T e){
			this->cabeza=new Nodo<T>(e);
				this->cola=this->cabeza;this->size++;
			
		}
		void addF(){
			this->cabeza=new Nodo<T>(this->cabeza);
			this->size++;
			
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
		ListaSEO(bool band=true){
			this->cabeza=this->cola=0;
			this->size=0;
		
		}
		ListaSEO(int size){
			this->cabeza=this->cola=0;
			this->size=size;
			this->generarNodos(size);
		
		}
		ListaSEO(const T*v,int size){
			this->cabeza=this->cola=0;
			
			
			for(int i=0;i<size;i++)
			this->Add(v[i],true);
		}
		ListaSEO(int size,T obj){
			this->cabeza=this->cola=0;
			this->size=size;
			this->generarNodos(size,obj);
		
		}	
		void visualizar(){
			Nodo<T> *prueba=this->cabeza;
			for(int a=0;a<size;a++){
				if(a%10==0)
				std::cout<<std::endl;
				std::cout<<(a)<<")"<<prueba->datNodo()<<" ";
				prueba=prueba->siguiente();	
			}
		}
		bool vacia(){
			return !(this->size);
		}
		unsigned int dim(){
			return this->size;
		}
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
		T Get(int pos=0) const{
			T obj;
			if(pos<0 ||  pos>=this->size )	
				return obj;
			
			if(!pos)
			return this->cabeza->datNodo();
			
			Nodo<T> *aux=this->cabeza;

			for(int i=0;i<pos;i++)
			aux=aux->siguiente();
			
			return aux->datNodo();
			
		}
		T* getArray()const{
				T *array;
				array=new T[this->size];
				Nodo<T>*aux=this->cabeza;
				
				for(int i=0;i<this->size;i++){
					array[i]=aux->datNodo();	
					aux=aux->siguiente();
					
				}
				return array;
		}
		int Buscar(T bus){
			
			Nodo<T> *prueba=this->cabeza;
			for(int a=0;a<size;a++){
				if(bus==prueba->datNodo()){

					return a;
				}
					prueba=prueba->siguiente();	
				
			}
			
			return -1;
		}
		void Add(T e){
			
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
