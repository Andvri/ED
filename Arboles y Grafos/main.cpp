#include "Grafos.h"
#include "../DString.h"

int main(){
	GrafoL<char,int> P,*al=0;
	char A='A',B='B',C='C',D='D',E='E',F='F',G='G',H='H';
	//////////////////////////////
	P.AddVertice(A);
	P.AddVertice(B);
	P.AddVertice(A);
	P.AddVertice(C);
	P.AddVertice(D);
	P.AddVertice(E);
	P.AddVertice(F);
	P.AddVertice(G);
	P.AddVertice(H);
	/////////////////////////////	
	P.AddArista(A,B,true,3);
	P.AddArista(A,C,true,1);
	P.AddArista(B,G,true,5);
	P.AddArista(B,D,true,1);
	P.AddArista(C,F,true,5);
	P.AddArista(C,D,true,2);
	P.AddArista(D,F,true,2);
	P.AddArista(D,E,true,4);
	P.AddArista(G,E,true,2);
	P.AddArista(F,H,true,3);
	P.AddArista(E,H,true,1);
	std::cout<<std::endl;
	int **c=P.AlgoritmoFloyd();
	for(int i=0;i<P.CantV();i++){
		for(int j=0;j<P.CantV();j++){
			std::cout<<c[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	for(int k=0;k<P.CantV();k++){
		
		int * omega=P.AlgoritmoDijkstra(P.obtVertice(k));
		std::cout<<std::endl<<" Dijkstra para vertice "<< P.obtVertice(k)<<std::endl;
		
		for(int i=0;i<P.CantV();i++)
			std::cout<<omega[i]<<std::endl;
		
		std::cout<<std::endl;
		
	}
	
	
	
	////////////////////////////
	//pildora informatica java

	return 0;

}


/*
*/
