#ifndef NODO_H
#define NODO_H
template <typename T>
class Nodo{
	private:
		T dat;
		Nodo<T> *sig;
		Nodo<T> *ant;
	public:
		Nodo(){
			this->sig=this->ant=0;
		}
		Nodo(T t){
			this->dat=t;
			this->sig=this->ant=0;
		}
		Nodo(T t,Nodo<T> *sig,Nodo<T> *ant=0){
			this->dat=t;
			this->sig=sig;
			this->ant=ant;
		}
		T datNodo()const{
		return this->dat;
		}
		void datNodo(T obj){
			this->dat=obj;
		}
		
		Nodo<T>* anterior(){
			return this->ant;
		
		}
		Nodo<T>* siguiente(){
			return this->sig;
		}
		
		void siguiente(Nodo<T> *sig){
			this->sig=sig;
		}
		void anterior(Nodo<T> *ant){
			this->ant=ant;
		}
		bool operator ==(const Nodo<T> &a){
			return this->dat==a.dat;
		}
		
	
};

 
#endif
