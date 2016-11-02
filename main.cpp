#include <iostream>
#include "Listas/Listas.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ListaSE<int> F;
	F.add(5);
	F.add(9);
	F.add(100);
	F.visualizar();
//	F.Cola();	
	return 0;

}
