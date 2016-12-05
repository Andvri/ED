#include "Listas.h"
#include <cstring>

class Cedula{
	private:
		unsigned short edad;
		 char  *apellidos;
		 char  *nombres;
		 char  *edoC;
		 char  *fNac;
		 char  *fExp;
		 char  *fVen;
	     char  Nacionalidad;
		unsigned int   NumID;
		
	public:
		
		Cedula(){
			
		}
		Cedula(short ed,const char*ape,const char*nom,const char*edC,const char*FN,const char*FE,const char*FV,char Nat,int id):edad(ed),Nacionalidad(Nat),NumID(id){
			int tam=strlen(ape);
			this->apellidos=new char[tam];
			strcpy(this->apellidos,ape);
			
			tam=strlen(nom);
			this->nombres=new char[tam];
			strcpy(this->nombres,nom);
			
			tam=strlen(edC);
			this->edoC=new char[tam];
			strcpy(this->edoC,edC);
			
			tam=strlen(FN);
			this->fNac=new char[tam];
			strcpy(this->fNac,FN);
			
			tam=strlen(FE);
			this->fExp=new char[tam];
			strcpy(this->fExp,FE);
			
			tam=strlen(FV);
			this->fVen=new char[tam];
			strcpy(this->fVen,FV);
				
			
		}
	
	friend std::ostream& operator <<(std::ostream &o,const Cedula &c){
		o<<"("<<c.nombres<<","<<c.apellidos<<","<<c.fExp<<","<<c.fNac<<","<<c.fVen<<","<<c.edoC<<","<<c.Nacionalidad<<","<<c.NumID<<","<<c.edad<<")";
		return o;
	}
	
};


typedef float* carril;
int main(){
	const int MAX=20;
	
	ListaSE< ListaSE<float>* > *Aristas;
	ListaSE<float> *camino=new ListaSE<float>();
	camino->reDimensionar( (float(88)) ,MAX+1 );
	std::cout<<(camino)<<std::endl;
	camino->Put( MAX ,(float(98)) );
	carril putaprueba=camino->getArray();
	std::cout<<putaprueba[20]<<std::endl;
//	camino->visualizar();

	return 0;
}




/*



	ListaSE<int> g(true);
	g.Add(9);
	g.Add(8);
	g.Add(15);
	g.Add(66);
	g.Add(9);
	g.Add(32);
	g.Add(55);
	g.Add(55);
	g.Add(12);
	
	
	
	g.Put(20,255);
//		g.visualizar();

	ListaSE<char> lo(7,'h',true);
	
	//lo.Delete(4);
//	lo.visualizar();
	char *a=lo.getArray();
	for(int i=0;i<7;i++)
	std::cout<<a[i]<<std::endl;
	
	
	
	
	
	
	//////////////////////////
	for(int i=0;i<5;i++){
		std::cout<<i<<")"<<std::endl;
		Aristas->Put(i,camino );
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	ListaSE< ListaSE<float>* > *Aristas;
	ListaSE<float> *camino=new ListaSE<float>(MAX,(float)9);
	
	Aristas= new ListaSE< ListaSE<float> *>(MAX,camino);
	std::cout<<" TAmaño de Aristas "<< Aristas->dim()<<std::endl;
	carril *poder;
	void *B=poder;
	void *A=Aristas;
	
	
	ListaSE<float>*p;
	for(int i=0;i<MAX;i++){
		std::cout<<i<<")"<<std::endl;
		p=Aristas->Get(i);
		p->visualizar();	
		std::cout<<std::endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
*/

