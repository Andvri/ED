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




int main(){
	
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
		g.visualizar();

	

	return 0;
}
