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
	
	ListaSE<Cedula> F;
Cedula GE(22,"Escalante Delgado","Guadalupe de Valle","Soltera","06/04/1994","18/09/2015","09/2025",'V',24820359);
	F.Add(GE);
	F.visualizar();
	std::cout<<F.Get(4)<<std::endl;
	std::cout<<GE<<std::endl;
	return 0;
}
