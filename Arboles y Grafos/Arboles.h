#ifndef ARBOLES_H
#define ARBOLES_H

#include "../Nodo\Nodo.h"
#include "../DString.h"
#include "../Colas\Colas.h"
#include <iostream>
#include <iomanip> 
#include "../Listas\Listas.h"
template <typename T>
class ArbolBinarioB{
	protected:
	Nodo<T> *raiz;
	int Nivel;
	unsigned int CantN;
	ListaSE<T> palabra;	
	//++++++++++++++++ Metodos de Agregar Remover y Buscar ++++++++++++++++++++++++++
	void Add(T e,Nodo<T>*Ev){
			if(Ev->datNodo()==e)
			return;
			if(e> Ev->datNodo() ){
				
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
	void remove1H(Nodo<T>*e,Nodo<T>*eP){
		Nodo<T> *eSustituo=0;
	
		if(e!=eP){
			
		
		if(e->siguiente()!=0){
			eSustituo=e->siguiente();
			e->siguiente(0);
		}	
		else{
			eSustituo=e->anterior();
			e->anterior(0);
		}
			
	//	std::cout<<"voy a eliminar "<<e->datNodo()<<" por "<<eSustituo->datNodo()<<std::endl;
			
		if(eP->siguiente()==e)
			eP->siguiente(eSustituo);
		else
			eP->anterior(eSustituo);
			
			
			
		delete e;
		this->Nivel--;
		
		}else{
			eSustituo=e;
			if(e->siguiente()!=0){
				raiz=e->siguiente();
				
			}else
				raiz=e->anterior();
				
				

			delete eSustituo;
			this->Nivel--;
			
		}
		
		
		
	}
	void removeSinH(Nodo<T>*e,Nodo<T>*eP){
		
		if(e!=eP){
			if(eP->siguiente()==e)
			eP->siguiente(0);
			else
			eP->anterior(0);
			
			
		}else{
			eP->siguiente(0);
			eP->anterior(0);
		}
		
		delete e;
		this->Nivel--;
		
	}	
	void remove2H(Nodo<T>*e,Nodo<T>*eP){
		//Primera condicion de eliminacion la altura de sus hijos
		//Segunda condicion de eliminacion la cant de nodos de sus hijos
		
			int cantI=cantNodos(e->anterior());
			int cantD=cantNodos(e->siguiente());
			int nivelI=altura(e->anterior());
			int nivelD=altura(e->siguiente());
			
			Nodo<T> *sus=0;
			if(nivelI>nivelD || ( ( nivelI==nivelD) && (cantI>cantD) )  ){
			//sustituyo por la izq;
			sus= Camino(e->anterior());	
			}else{
			sus=Camino(e->siguiente(),false);
			}
			
		
			Nodo<T> *pSus=searchP(raiz,sus->datNodo() );
			
		//	std::cout<<"El sustituto es "<<sus->datNodo()<<" el Padre sus es: "<<pSus->datNodo()<<std::endl;
				e->setdatNodo(sus->datNodo());
			if(sus->siguiente()==sus->anterior()){
					removeSinH(sus,pSus );
			 } else{
			 	remove1H(sus,pSus);
			 }

			
			
			
			
			
			
	}

	bool search(Nodo<T> *e,T ele){
		if(e==0)
		return false;
		else if(e->datNodo()<ele){
			return search(e->siguiente(),ele);
			}
		else if(e->datNodo()>ele){
			return search(e->anterior(),ele);
		}	
		else{
			return true;
		}
		
	}
	Nodo<T>* Camino(Nodo<T>*e,bool der=true){
		if(der){
			if(e->siguiente()==0)
				return e;
			else
				return Camino(e->siguiente());	
		}else{
			if(e->anterior()==0)
				return e;
			else
				return Camino(e->anterior(),false);
			
		}
	}
	Nodo<T>* searchN(Nodo<T>*e,T enc){
		if(e==0)
		return 0;
		Nodo<T> *auxI,*auxD;
		if(e->datNodo()==enc)
		return e;
		else{
			auxI=searchN(e->anterior(),enc);
			auxD=searchN(e->siguiente(),enc);
		}
		
		if(auxI==auxD)
		return 0;
		
		return (auxI==0)?auxD:auxI;
		
		
		
		
		
	}
	Nodo<T>* searchP(Nodo<T>*e,T enc){
		if(e==0)
		return 0;
		Nodo<T> *auxI,*auxD;
		if(e->datNodo()==enc)
		return e;
		if(e->siguiente()!=0)
			if(e->siguiente()->datNodo()==enc)
				return e;
				
		if(e->anterior()!=0)
			if(e->anterior()->datNodo()==enc)
				return e;
		
		auxI=searchP(e->anterior(),enc);
		auxD=searchP(e->siguiente(),enc);
		
		
		if(auxI==auxD)
		return 0;
		
		return (auxI==0)?auxD:auxI;
		
		
		
		
		
	}
	Nodo<T>* buscarN(T enc,bool band=true){
	
		return band?searchN(this->raiz,enc):searchP(this->raiz,enc) ;
	}
	//++++++++++++++++ Metodos  Visualizacion ++++++++++++++++++++++++++++++++
	
	void preOrden(Nodo<T>*e,int level=0){
		if(!e)
		return;
		std::cout<<std::setw(level*2)<<level<<")"<<e->datNodo()<<std::endl;
		preOrden(e->anterior(),level+1);
		preOrden(e->siguiente(),level+1);
		
	}
	void inOrden(Nodo<T>*e,int level=0){
		if(!e)
		return;
		inOrden(e->anterior(),level+1);
		std::cout<<level<<")"<<e->datNodo()<<std::endl;
		inOrden(e->siguiente(),level+1);
	}
	void postOrden(Nodo<T>*e,int level=0){
		if(!e)
		return;
		postOrden(e->anterior(),level+1);
		postOrden(e->siguiente(),level+1);
		std::cout<<level<<")"<<e->datNodo()<<std::endl;
		
	}
	void anchura(){
		ColaN< Nodo<T>* > cola;
		Nodo<T> *aux=this->raiz;
		cola.Put(aux);
		while(!cola.Vacia()){
			Nodo<T> *aux2;
			cola.Extract(aux2);
				std::cout<<aux2->datNodo()<<std::endl;
			if(aux2->anterior()!=0)
			cola.Put(aux2->anterior());
			if(aux2->siguiente()!=0)
			cola.Put(aux2->siguiente());	
			
			
		}
		
	}
	
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	
	public:
	ArbolBinarioB(){
		this->raiz=0;
		this->Nivel=0;
		this->CantN=0;
	}
	
	

	int getNivel(){
		return altura(this->raiz);
	}
	void Delete(T obj){
	if(!this->buscar(obj))
	  return;
	  
	Nodo<T> *ele=buscarN(obj);  
	Nodo<T> *ele2=buscarN(obj,false);
	
// si ele==ele2 es la raiz

	if(ele->siguiente()==ele->anterior()){			
		removeSinH(ele,ele2);	
		return;			
	}
		
	if(  (ele->siguiente()==0 && ele->anterior()!=0 ) || (ele->siguiente()!=0 && ele->anterior()==0)  )	{
		remove1H(ele,ele2);
		return;	
	}
	
	//tiene dos hijos
	
//	std::cout<<ele->datNodo()<<" nodo isq: "<<this->cantNodos(ele->anterior())<<" nodo der: "<<this->cantNodos(ele->siguiente())<<std::endl;
	remove2H(ele,ele2);
	
	
	
	
	
//	if(ele->anterior()==ele->siguiente())
//7	removeSinH(ele);
	
	
	
	
	}
	void Put(T e,bool der=true){
		if(!this->Nivel){
			this->Nivel++;
			this->CantN++;
			this->raiz=new Nodo<T>(e);
			return;
		}
		Add(e,this->raiz);	
	}
	void Imprimir(DString mode="Pre"){
		if(Nivel==0){
			std::cout<<"Vacia"<<std::endl;
			return;
		}
		
		if(mode=="Pre")
		preOrden(this->raiz);	
		if(mode=="In")
		inOrden(this->raiz);
		if(mode=="Post")
		postOrden(this->raiz);
		if(mode=="Level")
		anchura();
		
		std::cout<<"Cant Nodos :"<<this->Nivel<<std::endl;
	}			
	int altura(Nodo<T> *e=0){
		if(e==0)
		e=this->raiz;
		if(e->siguiente()==e->anterior())
			return 0;
		int Ai=0,Ad=0;
		if(e->siguiente())
			Ai= 1+ altura(e->siguiente());				
		if(e->anterior())
			Ad= 1 + altura(e->anterior());
		return 	(Ai>Ad)?Ai:Ad;		
	}	
	
	bool buscar(T ele){
		return this->search(this->raiz,ele);
	}
	
 	int cantNodos(Nodo<T> *e=0){
 		if(Nivel==0)
 		return 0;
		if(e==0)
		e=this->raiz;
		
		if(e->siguiente()==e->anterior())
			return 1;
			
		int Ai=0,Ad=0;
		if(e->siguiente())
			Ad= cantNodos(e->siguiente());				
		if(e->anterior())
			Ai= cantNodos(e->anterior());
		return 	1+Ai+Ad;		
			
		
	}
	
	void perLevel(int level,ListaSE<T>&l){		
		return perLevel(this->raiz,l,level);		
	}
	
	void perLevel(Nodo<T> *aux,ListaSE<T> &l, int level){
		
//	int i = Nivel;
		
		if(!level){
		l.Add(aux->datNodo(),true);
		}
		
		if(aux->anterior())
		perLevel(aux->anterior(),l,level-1);
		if(aux->siguiente())
		perLevel(aux->siguiente(),l,level-1);
		
	
		
	}
	
	
	
	
	
};


template <typename T>
class ArbolAVL: public ArbolBinarioB<T>
{
	public:
	
	int FactorEquilibrio(Nodo<T>*e=0){
		if(e==0)
		e=this->raiz;
		int Ai=0,Ad=0;
		if(e->siguiente())
			Ad=1+this->altura(e->siguiente());
		if(e->anterior())
			Ai=1+this->altura( e->anterior() );
		
		
		return Ad-Ai;
		
	}
	void Agregar(T obj){
		this->Put(obj);
		R();
		
		
	}
	void Rebalanceo(Nodo<T>*e){
		if(e==0)
		return;
		
		Rebalanceo(e->anterior());
		Rebalanceo(e->siguiente());
		int FE= FactorEquilibrio(e);
		if(FE<-1 || FE>1){
			std::cout<<"Falta equilibrar el nodo "<<e->datNodo()<<" FE "<<FE <<std::endl;
			
		}
		
		
		
	}
	void R(){
		Rebalanceo(this->raiz);
	}
	void RI(Nodo<T> *e){
		
		
		
	}
	void RD(Nodo<T> *e){
		
	}
	void DRI(Nodo<T> *e){
		
	}
	
	void DRD(Nodo<T> *e){
		
	}
	
	void Rebalancear(Nodo<T> *e,int FE){
		
		
		
		
		
	}
	
	
};




#endif
