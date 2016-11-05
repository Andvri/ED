#include "Listas.h"



int main(){
	
	ListaSE<int> F;
	F.add(5);
	F.add(9);
	F.add(8,true);
	F.add(4,2);
	F.visualizar();
	return 0;
}
