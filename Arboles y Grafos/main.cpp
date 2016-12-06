#include "Grafos.h"
#include "../DString.h"





int main(){
	GrafoL<char,int> GrafoL;
	char A='A',B='B',C='C',D='D',E='E';
	GrafoL.AddVertice(A);
	GrafoL.AddVertice(B);
	GrafoL.AddVertice(C);
	GrafoL.AddVertice(D);
	GrafoL.AddVertice(E);
	
	GrafoL.AddArista(A,B,false,4);
	GrafoL.AddArista(A,C,false,5);
	GrafoL.AddArista(B,E,false,6);
	GrafoL.AddArista(C,E,false,1);
	GrafoL.AddArista(E,D,false,8);
	GrafoL.AddArista(D,A,false,1);
	GrafoL.VerVertices();
	GrafoL.VerAristas();;
	PilaD<char> *p;
	p=new PilaD<char>();
	int Dis=GrafoL.AlgoritmoDijkstra(A,p);
	return 0;
}




/*
	GrafoL<DString,int> l;
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
		
		
		int**mA=l.MAdyacencias();
		
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++)
				std::cout<<mA[i][j]<<" ";
			std::cout<<std::endl;
		}


*/
