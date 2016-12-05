#include "Grafos.h"
#include "../DString.h"





int main(){
	GrafoL<DString,float> l;
	DString  A="Venezuela",B="Colombia",C="Mexico",D="Brasil",E="Chile";
		l.AddVertice(A);
		l.AddVertice(B);
		l.AddVertice(C);
		l.AddVertice(D);
		l.AddVertice(E);
	try{	
		l.AddArista(A,B,true,1403.56);
		l.AddArista(A,C,true,3589.04);
		l.AddArista(A,D,true,3207.34);
		l.AddArista(A,E,true,4899.02);
		l.AddArista(C,B,true,3170.37);
		l.AddArista(B,D,true,3218.83);
		l.AddArista(B,E,true,6313.71);
		l.AddArista(D,E,true,2844.10);
	}catch(const char *e){
		std::cerr<<e<<std::endl;
	}
		
		l.VerAristas();
		l.VerVertices();
		l.VerAristas();
		l.VerVertices();
		if(l.EsConexo())
		std::cout<<"El grafo es conexo"<<std::endl;
		else 
		std::cout<<"El grafo es disconexo"<<std::endl;
	return 0;
}




/*

Grafo<DString,float> l(false,false);
	DString  A="Venezuela",B="Colombia",C="Mexico",D="Brasil",E="Chile";
	
	l.AddVertice(A,(float)0);
	l.AddVertice(B,(float)0);
	l.AddVertice(C,(float)0);
	l.AddVertice(D,(float)0);
	l.AddVertice(E,(float)0);
	
	l.AddArista(A,B,1403.56);
	l.AddArista(A,C,3589.04);
	l.AddArista(A,D,3207.34);
	l.AddArista(A,E,4899.02);
	
	l.AddArista(C,B,3170.37);
	
	l.AddArista(B,D,3218.83);
	l.AddArista(B,E,6313.71);
	
	l.AddArista(D,E,2844.10);
	
	
	
	
	
//	l.VerVertices();
	l.VerAristas();
	std::cout<<"ANCHURA"<<std::endl;
	l.Recorrido(A);
	std::cout<<"PROFUNDIDAD "<<std::endl;
	l.Recorrido(A,"Profundidad");
	try
	{
		std::cout<<C<<" - "<<D<<" "<<l.Adyacente("cxcx",D);
	
	}catch(const char *e){
		std::cerr<<e<<std::endl;
	}
	
	

*/
