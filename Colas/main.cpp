#include "Colas.h"
#include <iostream>



int main(){
	
	ColaN<int> g;
	int h;
	
	g.Put(60);
	g.Put(80);
	g.Extract(h);
	g.Visualizar();

	
	return 0;
}
