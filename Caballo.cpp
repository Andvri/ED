#include <iostream>
#include <Windows.h>
#include <stdio.h>
const int N = 8;
const int n = (N+1);// Esto es por si se sale una pos de la matriz XD
int cant=0;
int tablero[n][n];
int d[8][2] = {{2,1}, {1,2}, {-1,2}, {-2,1},{-2,-1},{-1,-2},//Movimientos posibles del caballo
               {1,-2}, {2,-1}}; 



void escribeTablero()
{
//Sleep(500);
std::cout<<"------------------------------"<<std::endl;
int i,j;
  for(i = 1; i <= N; i++){
  	for (j = 1; j <= N; j++)
       printf("%02d ",tablero[i][j] ) ;
    std::cout  << std::endl;

  }
    
}
void saltoCaballo(int i, int x, int y, bool& exito)
{
	cant++;
	//escribeTablero();	
  int newX, newY;
 
  exito = false;
  int CAMINOS = 0;   
  
  /*
  Con este dowhile recorro los 8 posibles mov del caballo
  */
  do {
    CAMINOS++;
    newX = x + d[CAMINOS - 1][0];
    newY = y + d[CAMINOS - 1][1];
      
    if ((newX >= 1) && (newX <= N) &&
        (newY >= 1) && (newY <= N) &&
		(tablero[newX][newY] == 0))
    {
      tablero[newX][newY]= i; 
      if (i < N * N)
      {
        saltoCaballo(i + 1, newX, newY, exito);
              // analiza si se ha completado la solución
        if (!exito)
        {                       
          tablero[newX][newY] = 0;     // se borra porque ese camino no sirve
        }
      }
      else
        exito = true;          
    }
  } while ((CAMINOS < 8) && !exito);
}

int main()
{
  		for(int i=0;i<N;i++)
  			for(int j=0;j<N;j++)
  				tablero[i][j]=0;
  	
  	
  	
  	
  	
  	escribeTablero();
  	bool band=false;
	saltoCaballo(0,1,1,band);  	

  	escribeTablero();
  	std::cout<<"num de llamados a la funcion: "<<cant<<std::endl;
  	return 0;
}
