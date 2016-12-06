#include <iostream>
#include "../DString.h"
#include "../Nodo\Nodo.h"
#include "../Listas\Listas.h"
#include "../Colas\Colas.h"
#include "../Pilas\Pilas.h"
const int INFINITO=INT_MAX/2;
template<typename T,typename U=float>
class Grafo;
template<typename T,typename U=float>
class GrafoL;
template<typename T,typename U=float>
class Arista;
template<typename T,typename U=float>
class Etiqueta;




template <typename T,typename U>
class Grafo{
	typedef U* Carril;
	private:
		
		ListaSE<T> *Vertices;
		bool Dir;
		bool Pes;
		bool Listas;
		size_t CantV;
		ListaSE< ListaSE<U>* > *Aristas;
		
		//void *Aristas; //    Carril *Aristas o ListaSE< ListaSE<U>* > *Aristas
		template <typename ED>
		void cargarAdyacencias(ED &ref,bool *b,T e,int N=0){
			int posE=this->Vertices->Buscar(e);
			ListaSE<U> *aux=this->Aristas->Get(posE);
			for(int i=0;i<CantV;i++){
				
				U eU=aux->Get(i);
				if(eU!=0){
					if(!b[i]){
						b[i]=true;
						ref.Put(this->Vertices->Get(i));
						
					}
					
				}
				
				
				
			}
			
			
			
		
		
		}
		void LoadFile(DString file){
			
		}
		void RAnchura(T N){
			int posN=this->Vertices->Buscar(N);
			if(posN==-1){
				std::cout<<"No se encuentra el vertice "<<std::endl;
				return;

			}
			ColaN<T> cola;
			cola.Put(this->Vertices->Get(posN));
			bool *VecBool=new bool[CantV];
			for(int i=0;i<CantV;i++)
				VecBool[i]=false;
				
			VecBool[posN]=true;	
			while(!cola.Vacia() ){
				
				T e;
				cola.Extract(e);
				std::cout<<" "<<e<<std::endl;
				cargarAdyacencias(cola,VecBool,e);
				
				
				
				
			}
			
			
		}
		void RProfundidad(T N){
			int posN=this->Vertices->Buscar(N);
			if(posN==-1){
				std::cout<<"No se encuentra el vertice "<<std::endl;
				return;

			}
			PilaD<T> pila;
			pila.Put(this->Vertices->Get(posN));
			bool *VecBool=new bool[CantV];
			for(int i=0;i<CantV;i++)
				VecBool[i]=false;
				
			VecBool[posN]=true;	
			while(!pila.Vacia() ){	
				T e;
				pila.Extract(e);
				std::cout<<" "<<e<<std::endl;
				cargarAdyacencias(pila,VecBool,e);
				
			}
		}
		ListaSE<U>* LAristas(T m){
			int p=this->Vertices->Buscar(m);
			if(p==-1)
			throw "Vertice No existe";
			return this->Aristas->Get(p);
		}
	public:
		Grafo(DString file,bool Dir,bool Pes,bool Listas=true, void (*_funcionleerArchivos)()=0 ){
			this->Dir=Dir;
			this->Pes=Pes;
			this->Listas=Listas;
			Vertices=new ListaSE<T>(false);
			if(_funcionleerArchivos==0)
			this->LoadFile(file);
			else
			_funcionleerArchivos();
			
			this->CantV=0;
			this->Aristas= new ListaSE< ListaSE<U> *>();
			
		}
		Grafo(bool Dir,bool Pes,bool Listas=true ){
			Vertices=new ListaSE<T>(false);
			this->Dir=Dir;
			this->Listas=Listas;
			this->Pes=Pes;
			this->CantV=0;
			this->Aristas= new ListaSE< ListaSE<U> *>();
		}
		void AddVertice(T ver){
			this->Vertices->Add(ver,true);
			this->CantV++;
			U p;
			ListaSE<U> *L=new ListaSE<U>(CantV,p);
			for(int i=0;i<CantV-1;i++){	
			ListaSE<U> *w=this->Aristas->Get(i);
				w->reDimensionar(p,1);
			}
			this->Aristas->reDimensionar(L);
			
		}
		void AddVertice(T ver,U p){
			this->Vertices->Add(ver,true);
			this->CantV++;
			
			ListaSE<U> *L=new ListaSE<U>(CantV,p);
			for(int i=0;i<CantV-1;i++){	
			ListaSE<U> *w=this->Aristas->Get(i);
				w->reDimensionar(p,1);
			}
			this->Aristas->reDimensionar(L);
			
		}
		void VerVertices(){
			std::cout<<this->Vertices<<std::endl;
		}
		void VerAristas(){
			VerVertices();
			for(int i=0;i<this->CantV;i++){
				std::cout<<this->Vertices->Get(i)<< " "<<this->Aristas->Get(i)<<std::endl;
			}
		}
		void AddArista(T verS,T verLL,U dis=1,bool vol=true){
			int posS=this->Vertices->Buscar(verS);
			int posLL=this->Vertices->Buscar(verLL);
			
			if(posS==-1 || posLL==-1){
				std::cout<<"Algun vertice o Ambos no existe"<<std::endl;
				return;
			}
			ListaSE<U> *w=this->Aristas->Get(posS);
			w->Put(posLL,(U)dis);
			if(!this->Dir && vol){
				AddArista(verLL,verS,dis,false);			
			}	
		}
		void Recorrido(T N,DString mode="Anchura"){
			if(mode=="Anchura")
			RAnchura(N);
			else
			RProfundidad(N);
		}	
		U Adyacente(T In,T Ll){
			int posIn=this->Vertices->Buscar(In);
			int posLl=this->Vertices->Buscar(Ll);
			if(posIn==-1 || posLl==-1){
				throw "No existe Algun vertice o Ambos ";
			}
			
			ListaSE<U> *w=LAristas(In);
			return w->Get(posLl);	
		}
		void EliminarV(T Ne){
			int pNe=this->Vertices->Buscar(Ne);
			if(pNe==-1){
				std::cout<<"Vertice no encontrado "<<std::endl;
				return;
			}
			std::cout<<Ne<<" eliminar pos "<<pNe<<std::endl;			
			this->Vertices->Delete(pNe);
			for(int i=0;i<CantV;i++)
			{
				ListaSE<U> *w=this->Aristas->Get(i);
				w->Delete(pNe);
			}
			this->Aristas->Delete(pNe);
			this->CantV--;			
		}		
		
		
		
		
		
};

template <typename T,typename U>
class Arista{
	friend class  GrafoL<T,U>;
	friend class  Grafo<T,U>;
		private:
			T Destino;
			U Distancia;
		public:
			Arista(){
				
			}
			Arista(T De,U Di){
				this->Destino=De;
				this->Distancia=Di;
			}
			
			
		bool operator ==(const Arista<T,U>&w){
			return this->Destino==w.Destino;	
		}	
			
			
					
		friend std::ostream& operator << (std::ostream &o,const Arista<T,U> &p){
	    o<<"(Destino:"<<p.Destino<<",Distancia:"<<p.Distancia<<")";
	    return o;
		}
		
		friend std::ostream& operator << (std::ostream &o,const Arista<T,U> *p){
		o<<"(Destino:"<<p->Destino<<",Distancia:"<<p->Distancia<<")";
	    return o;
		}
};


template<typename T,typename U>
class Etiqueta{
	friend class  GrafoL<T,U>;
	friend class  Grafo<T,U>;
	private:
		T Ant;
		U DisA;
		int itera;
	public:
		Etiqueta(){
			this->DisA=0;
			itera=0;
		}
		Etiqueta(T a,U b){
			Ant=a;
			DisA=b;
			itera=0;
		}
	
};
template <typename T,typename U>
class GrafoL{
	typedef ListaSE< Arista<T,U> > ListaAristas;
	typedef U* Carril;
	private:
		ListaSE<T> *Vertices;
		ListaSE< ListaAristas* > *Aristas;
		ListaAristas* LAristas(T In){
			int I=this->Vertices->Buscar(In);
			if(I==-1)
			throw "No existe el vertice";
			return this->Aristas->Get(I);
			
		}
		template <typename ED>
		void Recorrer(ED &ref,int posN,bool *b,bool *as){
			ref.Put(this->Vertices->Get(posN));
			while(!ref.Vacia() ){	
				T e;
				ref.Extract(e);
				if(as==0)
				std::cout<<" "<<e<<std::endl;
				cargarAdyacencias(ref,b,e);
				
			}
		}
		template <typename ED>
		void cargarAdyacencias(ED &ref,bool *b,T e){
			int posE=this->Vertices->Buscar(e);
			ListaAristas *aux=this->Aristas->Get(posE);
			for(int i=0;i<aux->dim();i++){
				int f=this->Vertices->Buscar((aux->Get(i)).Destino);
					if(!b[f]){
						b[f]=true;
						ref.Put(this->Vertices->Get(f));	
					}	
					
			}
		}
	public:
		GrafoL(DString file,bool Listas=true, void (*_funcionleerArchivos)()=0 ){
			
			Vertices=new ListaSE<T>(false);
			if(_funcionleerArchivos==0)
			this->LoadFile(file);
			else
			_funcionleerArchivos();
			this->Aristas= new ListaSE< ListaAristas *>(false);
			
		}
		GrafoL(){
			Vertices=new ListaSE<T>(false);
			this->Aristas= new ListaSE< ListaAristas *>(false);
			}
		
		void AddVertice(T ver){
			this->Vertices->Add(ver,true);
			this->Aristas->Add(new ListaAristas(false),true);
		}	
		void AddArista(T In,T Ll,bool NoDir=true,U Peso=1){
			int I=this->Vertices->Buscar(In);
			int D=this->Vertices->Buscar(Ll);
			if(I==-1 || D==-1)
			throw "Almenos un vertice no Existe";
			ListaAristas *w=LAristas(In);
			w->Add( *(new Arista<T,U>(Ll,Peso)),true);
			if(NoDir){
				AddArista(Ll,In,false,Peso);
			}			
		} 
		void VerVertices(){
			std::cout<<this->Vertices<<std::endl;			
		}
		
		void VerArista(T In){
			try{
				std::cout<<LAristas(In)<<std::endl;
			}catch(const char *e){
			
			std::cerr<<e<<std::endl;
			}
			
		}
		void VerAristas(){
			for(int i=0;i<Vertices->dim();i++){
				std::cout<<"Vertice: "<<Vertices->Get(i)<<" : "<<std::endl<<LAristas(Vertices->Get(i))<<std::endl;
			}
		}
		// Elimina una vertice si no encuentre lanza uan excepcion
		void EliminarV(T v){
			int El=this->Vertices->Buscar(v);	
			if(El==-1)
			throw "No se encuentra el Vertice a Eliminar";
			
			for(int i=0;i<this->Vertices->dim();i++){
				try{
				EliminarA(this->Vertices->Get(i),v);
				}catch(const char *e){
					std::cerr<<e<<std::endl;
				}
			}
			this->Vertices->Delete(El);
			this->Aristas->Delete(El);
			
			
		}
		// Elimina una arista si no encuentre uno o los Vertices lanza uan excepcion
		void EliminarA(T iD,T lL){
			int piD=this->Vertices->Buscar(iD);	
			int plL=this->Vertices->Buscar(lL);
			if(piD==-1||plL==-1)
			throw "No se encuentra el Vertice a Eliminar";
			ListaAristas *w=LAristas(iD);
			if( w->Buscar( *(new Arista<T,U>(lL,0) ) ) !=-1 ){
				w->Delete(w->Buscar( *(new Arista<T,U>(lL,0) ) ));
			}
			
		}
		
		void Recorrido(T N,DString mode="Anchura",bool *as=0){
			int posN=this->Vertices->Buscar(N);
			if(posN==-1)
			throw "No se encuetra el Vertice";
			bool *VecBool=new bool[this->Vertices->dim()];
			for(int i=0;i<this->Vertices->dim();i++)
				VecBool[i]=false;
			VecBool[posN]=true;	
			ColaN<T> f;
			PilaD<T> p;
			if(mode =="Anchura")
			Recorrer(f,posN,VecBool,as);
			else
			Recorrer(p,posN,VecBool,as);
			if(as!=0)
			for(int i=0;i<this->Vertices->dim();i++)
				as[i]=VecBool[i];
						
				
		}
		
		void AlgoritmoFloyd(){
			
		}
		int ** AlgoritmoWarshall(){
			int **mB=this->MBooleana();
			  for (int k = 0; k < this->Vertices->dim(); k++)
   				 for (int i = 0; i < this->Vertices->dim(); i++)
    				  for (int j = 0; j < this->Vertices->dim(); j++)
    				        if (mB[i][k] * mB[k][j])
          							mB[i][j]=1;
			return mB;
			
		}
		
		
		U* AlgoritmoDijkstra(T partida,T destino){
				int NVertices=this->Vertices->dim();
				int posI=this->Vertices->Buscar(partida);
				int posD=this->Vertices->Buscar(destino);
				if(posI==-1 || posD==-1)
				throw "No se encuentra un vertice";
				bool *VecBool=new bool[NVertices];
				U* DistanciasM=new U[NVertices];
				for(int i=0;i<NVertices;i++){
					DistanciasM[i]=this->Adyacente(partida,Vertices->Get(i),true);
					VecBool[i]=false;	
				}
				VecBool[posI]=true;
				DistanciasM[posI]=0;
				for(int k=1;k<NVertices;k++){
					U menor=(U)INFINITO;
					int posMenor=0;	
					for (int j = 0; j < NVertices; j++){
					  	if (!VecBool[j] && (menor >= DistanciasM[j])){
						         menor = DistanciasM[j];
						         posMenor= j;
						}
					}
					VecBool[posMenor]=true;	       
    		        for (int w = 0; w < NVertices; w++){
    		       		if (!VecBool[w]){
		    		       	if (DistanciasM[posMenor] + this->Adyacente(Vertices->Get(posMenor),Vertices->Get(w),true) < DistanciasM[w]) {
					               DistanciasM[w] = DistanciasM[posMenor] + this->Adyacente(Vertices->Get(posMenor),Vertices->Get(w),true);
					            //aGRAGRA PI LA w=posMenor
					        }
						}
				 	}
				}
			
			
			
			
			
				return DistanciasM;
		}
		//Retorna una matriz de adyacencia Booleana todo num diferente de cero lo vuelve 1
		int ** MBooleana(){
			int **p=new int*[this->Vertices->dim()];
			for(int i=0;i<this->Vertices->dim();i++)
				p[i]=new int[this->Vertices->dim()];
				
				
			U**mA=this->MAdyacencias();
				
			
			  for (int i = 0; i < this->Vertices->dim(); i++)
    			 for (int j = 0; j <  this->Vertices->dim(); j++)
						p[i][j]=(this->Adyacente(this->Vertices->Get(i),this->Vertices->Get(j))>0)?1:0;
			
			
			return p;
			
			
			
		}
		//Retorna un booleano con la condicion de si el grafo es conexo, utiliza el recorrido para determinar si todos los nodos estan conectados
		bool EsConexo(){
			bool *c=new bool[this->Vertices->dim()];
			
			if(this->Vertices->dim()==1)
			return true;
			this->Recorrido(this->Vertices->Get(0)," ",c);
			for(int i=0;i<this->Vertices->dim();i++){
				if(!c[i])
					return false;
			}
			return true;
			
		}
		U Adyacente(T In,T Ll,bool as=false){
			int posIn=this->Vertices->Buscar(In);
			int posLl=this->Vertices->Buscar(Ll);
			if(posIn==-1 || posLl==-1){
				throw "No existe Algun vertice o Ambos ";
			}
			
			ListaAristas *w=this->Aristas->Get(posIn);
			int p=w->Buscar( *(new Arista<T,U>(Ll,0)) );
			
			
			return (p!=-1)? (w->Get(p)).Distancia:((as)?(U)INFINITO:0);
			
		}
		Carril *MAdyacencias(bool Infinito=false){
			Carril *aux=new Carril[this->Vertices->dim()];
			for(int i=0;i<this->Vertices->dim();i++)
					aux[i]= new U[this->Vertices->dim()];
					
					
					
			for(int i=0;i<this->Vertices->dim();i++){
				for(int j=0;j<this->Vertices->dim();j++){
					T ida=this->Vertices->Get(i);
					T ll=this->Vertices->Get(j);
					
					
					aux[i][j]=this->Adyacente(ida,ll);
					if(Infinito && aux[i][j]==0){
						aux[i][j]=(U)INFINITO;
					}
				}				
			}
			return aux;
		}
		
};


