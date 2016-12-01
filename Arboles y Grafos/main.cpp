#include "Arboles.h"
#include "Grafos.h"




int main(){
	Grafo<char> l(false,false);
	l.AddVertice('F');
	l.AddVertice('A');
	l.VerVertices();
	l.AddArista('A','A',4);
	return 0;
}
