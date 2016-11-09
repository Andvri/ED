#include "Colas.h"
#include <iostream>



int main(){
	
	ColaC<int> g(5);
	int h;
	
	g.Put(60);
	g.Put(80);
	g.Extract(h);
	g.Put(90);
//	g.Visualizar();
	std::cout<<h;
	
	return 0;
}
