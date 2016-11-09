#ifndef ARCHIVOMADRE_H
#define ARCHIVOMADRE_H

#include <fstream>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <Windows.h>
#include <sstream>
#include <iomanip>
#include "Persona.h"


class ArchivoMadre{
	
	private:
		
	static char estado[][30];
	static int totalEstados;
	
	//Atributos Generales
		std::fstream handler;
		char nomArch[35];
		Persona buffer;
		int longitud;
		
	//Atributos Binarios
		int tamanho;
		Persona bufferAux;
		
	public:
		
		///////////////
		//Constructor//
		///////////////
		
		ArchivoMadre(const char* nomArch){
	
		strcpy(this->nomArch, nomArch);
			agregarEstados();
			cargarBinario();
			calcularTamanho();				
		}
		
		///////////////////////////////////
		///////////////////////////////////
    	//Funciones de Propositos Comunes//
		///////////////////////////////////
		///////////////////////////////////
					
		void abrir(const std::ios_base::openmode &mode){
		this->handler.open(nomArch,mode);	
		}
			
		void cerrar(){
		this->handler.close();
		}
				
		void limpiar(){
		this->handler.clear();
		}
		
		bool falla(){
		return this->handler.fail();
		}
		
		bool finArchivo(){
		return this->handler.eof();
		}
		
		char* getNomArch(){	return this->nomArch; }
		
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////			
		//Manipulacion/Alteracion de Archivo de Texto y //
		//Creacion de Archivo Binario         			//
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////
		
		void agregarEstados(){
			
			std::ifstream lec("datos.txt");
			std::ofstream col("clone.txt");
			srand(time(NULL));
			int rango; //entre 0 y 24

			// rango =rand()%25;
			
				while(true){
					
					char base[300];
					lec.getline(base,300);
					rango=rand()%25;
					if(lec.eof()){
						break;
					}
				//	std::cout<<base<<std::endl;
					col<<strcat(base,estado[rango])<<std::endl;
				}
			
				lec.close();
				col.close();
			
		}
		
		void cargarBinario(){
			
			this->abrir(std::ios::out | std::ios::binary);
			this->calcularLongitud();			// Binary Constructor
			std::ifstream clone("clone.txt");
		
			while(true){
				
				char lec[300] = {};
		
				clone.getline(lec,300,'\n');
				std::istringstream se(lec);
				char nombre[150]={}, naCed[20]={}, estado[30]={};
				se.getline(naCed,20,'\t');
			 	se.getline(naCed,20,'\t');
				
				char aux[15]={};
				char na;
				
				std::istringstream iss(naCed);
				iss.getline(aux,15,'-');
				na = aux[0];
				iss.getline(aux,15,'-');
								
				se.getline(nombre,150,'\t');
				se.getline(estado,30,' ');
				se.getline(estado,30,'\0');
													
				if(clone.eof())	break;
				
			//	std::cout << "(" << estado << "," << naCed << "," << nombre << "," <<na<< "," << aux << ")" << '\n';
				Persona bufferAux(na,atoi(aux),nombre,estado);
				this->escribirBin(bufferAux);
				
						
			}	
	
			this->cerrar();
			clone.close();	
			
			
	
		}

	//////////////////////////////////////////////////	
	//////////////////////////////////////////////////
	//Metodos Tradicionales, Metodo de Ordenamiento //
	//y Metodo de Busqueda, para Archivos Binarios  //
	//////////////////////////////////////////////////
	//////////////////////////////////////////////////
	
		void calcularTamanho(){	
			this->abrir(std::ios::in | std::ios::binary);
			this->limpiar();
			this->handler.seekg(0,std::ios::end);
			this->tamanho = this->handler.tellg()/longitud;
			this->cerrar();
			//	std::cout << "Elements in Archive: " << nSize <<'\n';
			/* Metodo utilizado para obtener la cantidad de elementos que hay en dicho archivo binario */
		}
		
		void calcularLongitud(){
			this->longitud = sizeof(Persona);
			/* Metodo utilizado para obtener la cantidad de bytes de la clase Student */
		}
		void posicionar(int p){
			this->limpiar();
			this->handler.seekg(p*longitud, std::ios::beg);
			/* Metodo utilizado para redireccionar desde el archivo principal */
		}
		
		void posicionar(std::fstream &aux, int p){
			aux.clear();
			aux.seekg(p*longitud, std::ios::beg);
			/* Metodo utilizado para redireccionar desde un archivo auxiliar */
		}	
		
		void escribirBin(Persona &toWrite){
			this->handler.write((char*)&toWrite,longitud); // Escribe el Archivo Principal
		}
				
		void escribirBin(std::fstream &aux,Persona &toWrite){
			aux.write((char*)&toWrite,longitud); // Escribe en un Archivo Auxiliar
		}
		
		void leerBin(Persona &toRead){
			this->handler.read((char*)&toRead,longitud); // Lee del Archivo Principal
		}
		
		void leerBin(std::fstream &aux, Persona &toRead){
			aux.read((char*)&toRead,longitud); // Lee de un Archivo Auxiliar 
		}
		
		void imprimirBin(){
		
			std::fstream printer("principal.dat",std::ios::in | std::ios::binary);
			Persona lBuffer;
		
			while(true){
			
				printer.read((char*)&lBuffer,longitud);
				if(printer.eof()) break;
				lBuffer.imprimir();
					
			}
		
			printer.close();
	
		}	
		
		void imprimirBin(std::fstream &toPrint){
	
			toPrint.open("MainAux.dat",std::ios::in | std::ios::binary);
			Persona lBuffer;
			
			while(true){
				
				toPrint.read((char*)&lBuffer,longitud);
				if(toPrint.eof()) break;
				lBuffer.imprimir();
						
			}
			
			toPrint.close();
	
		}
		
		void imprimirBin(int lim1, int lim2){
			
			std::fstream printer("principal.dat",std::ios::in | std::ios::binary);
			printer.clear();
			printer.seekg(0, std::ios::beg);
			Persona lBuffer;
		
			while(lim1<=lim2){
				
				printer.seekg(lim1*longitud, std::ios::beg);
				printer.read((char*)&lBuffer,longitud);
				lBuffer.imprimir();
				lim1++;
					
			}
		
			printer.close();
			
		}
		
		void imprimirBin(char* cad1, char* cad2,bool swi=true){
			
			std::fstream printer("principal.dat",std::ios::in | std::ios::binary);
			Persona lBuffer;
			bool found = false;
		
			std::cout << '\n';
			
			while(true){
				
				printer.read((char*)&lBuffer,longitud);
				
				if(printer.eof()) break;
				
				if(swi){
				
				char buf[150]={};
				
				std::istringstream iss(lBuffer.getNombre());
				
				while(iss.getline(buf,150,' ')){
				
					if(strcmpi(buf,cad1)==0 || strcmpi(buf,cad2)==0){
					lBuffer.imprimir();
					found = true;
					break;
					}
					
				}
				
				}else{
					
					if( strcmpi(cad1,lBuffer.getEstado()) <= 0 && strcmpi(cad2,lBuffer.getEstado()) >= 0 ){
					
					lBuffer.imprimir();
					found = true;
					
					}
										
				}
											
			}
						
			if(!found){
				std::cout << '\n' << "No encontrados en el registro!" << '\n';
			}
		
			printer.close();
					
		}
		
		int Busqueda_Binaria(int LL, int UL, int toSearch){
			
			limpiar();
			posicionar(0);
			Persona auxBuffer;
			
			int mid = (LL+UL)/2;
			
			posicionar(mid);
			leerBin(auxBuffer);
			
			if(auxBuffer.getCedula() == toSearch)
				return mid;
			if(LL > UL)
				return -1;
				
			if(toSearch < auxBuffer.getCedula())
				Busqueda_Binaria(LL,mid-1,toSearch);
			else
				Busqueda_Binaria(mid+1,UL,toSearch);
			
		}
			
		void fusionDirecta(std::fstream &a1,std::fstream &a2,int n,int k,int modo){
			
			// std::cout<<"Entreaqui"<<std::endl;
		
			abrir(std::ios::in | std::ios::out | std::ios::binary);
			limpiar();
			posicionar(0);	
			
			a1.open("dat1.dat",std::ios::in | std::ios::binary);
			a2.open("dat2.dat",std::ios::in | std::ios::binary);
			
			Persona obj1, obj2;
			
			int b1=0,b2=0;
			bool new1=true, new2=true, Final=false;
						
			while(true){
				
					bool ultimobj1 = false, ultimobj2 = false;					
					if(new1 && b1<n){
						a1.read((char*)&obj1, longitud);
						
						if(modo == 5)
						ultimobj1 = true;
						//std::cout<<obj1<<std::endl;
					}
				
					if(new2 && b2<k){
					   	a2.read((char*)&obj2, longitud);
					 	//std::cout<<obj2<<std::endl;
					}
					
					if(a1.eof() && a2.eof())// leo y si ambos archivos estan al final me salgo
					break;
										
					if(!a1.eof() &&  a2.eof()){ // si el a2 se acabo  a1 no entonces escribo em el archivo
					
						while(true){ //mientras ya se supone que al menos en obj1 existe uno
							this->escribirBin(obj1);
							//std::cout<<"Escribi"<<obj1<<std::endl;
							a1.read((char*)&obj1, longitud);
							if(a1.eof()){
							Final=true;
							break;
							}
						}
						
					}
					
					if(!a2.eof() &&  a1.eof()){
						
						while(true){
							
							this->escribirBin(obj2);
							//std::cout<<"Escribi"<<obj2<<std::endl;
							a2.read((char*)&obj2, longitud);
							if(a2.eof()){
									Final=true;
									break;
							}
						}
						
					}
					
					
					if(!a1.eof() &&  !a2.eof()){
						
						switch(modo){
							
							case 1:{
								
								if(strcmpi(obj1.getNombre(),obj2.getNombre()) >= 0 ){
									this->escribirBin(obj2);
									//std::cout<<"Escribi"<<obj2<<std::endl;
									new1=false;
									new2=true;
									b2++;
								}else{
									this->escribirBin(obj1);
									//std::cout<<"Escribi"<<obj1<<std::endl;
									new1=true;
									new2=false;
									b1++;
								}	
												
							break;							
							}
							
							case 2:{
																	
								if(strcmpi(obj1.getEstado(),obj2.getEstado()) >= 0 ){
									this->escribirBin(obj2);
									//std::cout<<"Escribi"<<obj2<<std::endl;
									new1=false;
									new2=true;
									b2++;
								}else{
									this->escribirBin(obj1);
									//std::cout<<"Escribi"<<obj1<<std::endl;
									new1=true;
									new2=false;
									b1++;
								}	
								
							break;								
							}
							
							case 3:{
								
								if(obj1.getCedula() >= obj2.getCedula()){
									this->escribirBin(obj2);
									//std::cout<<"Escribi"<<obj2<<std::endl;
									new1=false;
									new2=true;
									b2++;
								}else{
									this->escribirBin(obj1);
									//std::cout<<"Escribi"<<obj1<<std::endl;
									new1=true;
									new2=false;
									b1++;
								}
								
							break;							
							}
							
							case 4:{
								
								if(obj1.getCedula() <= obj2.getCedula()){
									this->escribirBin(obj2);
									//std::cout<<"Escribi"<<obj2<<std::endl;
									new1=false;
									new2=true;
									b2++;
								}else{
									this->escribirBin(obj1);
									//std::cout<<"Escribi"<<obj1<<std::endl;
									new1=true;
									new2=false;
									b1++;
								}
																
							break;
							}
							
							case 5:{
								
								if(strcmpi(obj1.getEstado(),obj2.getEstado()) == 0 && obj1.getCedula() >= obj2.getCedula())    {
									this->escribirBin(obj2);
									//std::cout<<"Escribi"<<obj2<<std::endl;
									new1=false;
									new2=true;
									b2++;
								}else{
									this->escribirBin(obj1);
									//std::cout<<"Escribi"<<obj1<<std::endl;
									new1=true;
									new2=false;
									b1++;
								}
																
							break;
							}
																					
						}
												
					}
				
					if(b2==k && b1<n){
					//	escribir(obj1);
					//	std::cout<<"Escribi"<<obj1<<std::endl;
						
						while(b1<n && !a1.eof()){
							
							if(!a1.eof()){
							this->escribirBin(obj1);	
							b1++;
							}else{
							b1 = b2;
							}
							
						//	std::cout<<"Escribi"<<obj2<<std::endl;
							if(b1<n)
							a1.read((char*)&obj1, longitud);
							else
							break;
													
						}
					
					}
					
					if(b1==n && b2<k){
					//	escribir(obj2);
					//	std::cout<<"Escribi"<<obj2<<std::endl;
					
						while(b2<k){
							
							if(!a2.eof()){
							this->escribirBin(obj2);	
							b2++;
							}else{
							b2 = b1;
							}
						//	std::cout<<"Escribi"<<obj2<<std::endl;
							if(b2<k)
							a2.read((char*)&obj2, longitud);
							else
							break;
													
						}
										
					}
									
					if(b1==n && b2==k){
						b1=0;
						b2=0;
						new1=true;
						new2=true;
					}
					
 					if(Final)
					break;
					
								
			}
						
			a1.close();
			a2.close();
			cerrar();
			
		}
				
		int particionDirecta(std::fstream &a1,std::fstream &a2,int p){

			int vueltas=0;

			a1.open("dat1.dat",std::ios::out | std::ios::binary);
			a2.open("dat2.dat",std::ios::out | std::ios::binary);

			Persona objaux;
			
			while(true){
				
				int cont = 0;
				
				while(cont<p){	//llenar primer archivo
					
					this->leerBin(objaux);
					if(this->finArchivo())break;
					a1.write((char*)&objaux, longitud);				
					cont++;
					
				}
				
				cont = 0;
				
				while(cont<p){//lleno segundo archivo
				
					this->leerBin(objaux);
					if(this->finArchivo())break;
				  	a2.write((char*)&objaux, longitud);				
					cont++;
					
				}
				
				vueltas++;
				
				if(this->finArchivo())
					break;
				
								
			}
			
			a1.close();
			a2.close();
			return vueltas;
		
		}

		void Mezcla_Directa(int modo){
			
			std::fstream a1,a2;
			int p=1,aux=0;
			
				while(true){
					
				this->abrir(std::ios::in | std::ios::out | std::ios::binary);
				this->limpiar();
				this->posicionar(0);	
				aux=particionDirecta(a1,a2,p);
				this->cerrar();
				
				fusionDirecta(a1,a2,p,p,modo);
				
					//std::cout<<"Entre"<<std::endl;	
					if(aux!=1)
						p*=2;	
					else
						break;
													
				}
						
		}
				
		void imprimirEstado(char *estado){
	
	
			std::fstream printer("principal.dat",std::ios::in | std::ios::binary);
			Persona lBuffer;
		
			while(true){
			
				printer.read((char*)&lBuffer,longitud);
				if(printer.eof()) break;
				if(strcmp(lBuffer.getEstado(),estado) ==0)lBuffer.imprimir();
					
			}
		
			printer.close();
			
		}
		
		void verificarStatus(bool sortStatus[4]){
			
			abrir(std::ios::in | std::ios::binary);
			
			Persona aB1,aB2;
			
			limpiar();
			posicionar(0);
			leerBin(aB1);
			
			/* Revisando Cedulas Ascendentes*/
			while(sortStatus[2]){
				
				leerBin(aB2);
				if(finArchivo())break;
				if(aB1.getCedula()<=aB2.getCedula())				
				sortStatus[2] = true;
				else
				sortStatus[2] = false;
				
				aB1 = aB2;				
			}
			
			posicionar(0);
			leerBin(aB1);
			
			/* Revisando Cedulas Descendentes*/
			while(sortStatus[3]){
				
				leerBin(aB2);
				if(finArchivo())break;
				if(aB1.getCedula()>=aB2.getCedula())				
				sortStatus[3] = true;
				else
				sortStatus[3] = false;
				
				aB1 = aB2;				
			}
			
			posicionar(0);
			leerBin(aB1);
			
			/*Revisando Alfabeticamente*/
			while(sortStatus[0]){
				
				leerBin(aB2);
				if(finArchivo())break;
				if(strcmpi(aB1.getNombre(),aB2.getNombre()) <= 0)				
				sortStatus[0] = true;
				else
				sortStatus[0] = false;
				
				aB1 = aB2;				
			}
			
			posicionar(0);
			leerBin(aB1);
			
			/*Revisando Estados*/
			while(sortStatus[1]){
				
				leerBin(aB2);
				if(finArchivo())break;
				if(strcmpi(aB1.getEstado(),aB2.getEstado()) <= 0)				
				sortStatus[1] = true;
				else
				sortStatus[1] = false;
				
				aB1 = aB2;				
			}
			
			cerrar();
			
			
		}
		
		////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////
		// Menu Principal, Sub-menus, y Creacion del Archivo clasifica.txt//
		////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////	
			
		void menuClasificacion(bool sortStatus[4]){
		
			int op=0;
	
			system("cls");
			std::cout<<"\tSelecciona Opcion:"<<std::endl;
			std::cout<<"\t\t 1)Ordenar Alfabeticamente"<<std::endl;
			std::cout<<"\t\t 2)Ordenar por Estado"<<std::endl;
			std::cout<<"\t\t 3)Ordenar por CI Ascendentemente"<<std::endl;
			std::cout<<"\t\t 4)Ordenar por CI Descendentemente"<<std::endl;
			std::cout<<"\t\t 5)Regresar al menu principal"<<std::endl;
	
			std::cout<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl;
	
	
			do{
		
			std::cout<<"Ingrese una opcion: ";
			std::cin>>op;
		
			}while(op<1 || op>5);
		
		
			switch(op){
			
				case 1:{
				
					if(!sortStatus[0]){
					Mezcla_Directa(op);	
						
					for(int i = 0; i < 4; i++)
					if(op-1 == i)
					sortStatus[i] = true;
					else
					sortStatus[i] = false;
					
					std::cout << "Se ha organizado con exito." << std::endl;	
					
					}else{
						std::cout << "Ya esta ordenado de esta forma." << std::endl;
					
					}
				
				break;
				}
				
				case 2:{
					
					if(!sortStatus[1]){
					Mezcla_Directa(op);		
					for(int i = 0; i < 4; i++)
					if(op-1 == i)
					sortStatus[i] = true;
					else
					sortStatus[i] = false;
					
					std::cout << "Se ha organizado con exito." << std::endl;
					
					}else{
						std::cout << "Ya esta ordenado de esta forma." << std::endl;
					
					}
				
				break;
				
				}
				case 3:{	
							
					if(!sortStatus[2]){
					Mezcla_Directa(op);		
					for(int i = 0; i < 4; i++)
					if(op-1 == i)
					sortStatus[i] = true;
					else
					sortStatus[i] = false;
					
					std::cout << "Se ha organizado con exito." << std::endl;
					
					}else{
						std::cout << "Ya esta ordenado de esta forma." << std::endl;
					
					}
				
				break;
				}
				case 4:{
					
					if(!sortStatus[3]){
					Mezcla_Directa(op);		
					for(int i = 0; i < 4; i++)
					if(op-1 == i)
					sortStatus[i] = true;
					else
					sortStatus[i] = false;
					
					std::cout << "Se ha organizado con exito." << std::endl;
					
					}else{
						std::cout << "Ya esta ordenado de esta forma." << std::endl;
					
					}
					
				break;
				
				}
				
				default:{
				return;
				break;
				}
						
			}
		
	
		system("pause>0");	
	
		}

		char* seleccionarEstado(){
		
			int op=0;
			char spacing[50] = {" "};
	
			system("cls");
		
			for(int i=0;i<25;i++){
			std::cout << (i+1) << ")" << estado[i] << std::endl;	
			
			std::cout << spacing;
			strcat(spacing," ");
			
			}		
			std::cout<<std::endl;
	
			do{
		
				std::cout<<"Ingrese una opcion: ";
				std::cin>>op;
			
			}while(op<1 || op>25);
		
			std::cout<<"Escogiste el estado "<<estado[op-1] << " pulsa enter para mostrar el listado."<<std::endl;
			system("pause>0");
	
			return estado[op-1];
	
		}

		void busquedaAvanzada(bool sortStatus[4]){
	
			int op=0;
			char resp;
			
			system("cls");
			std::cout<<"\tSelecciona Opcion:"<<std::endl;
			std::cout<<"\t\t 1)Rango entre CIs"<<std::endl;
			std::cout<<"\t\t 2)Cadenas en Nombre"<<std::endl;
			std::cout<<"\t\t 3)Rango entre Estados"<<std::endl;
			std::cout<<"\t\t 4)Regresar al menu principal"<<std::endl;
		
			std::cout<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl;
		
			do{
		
			std::cout<<"Ingrese una opcion: ";
			std::cin>>op;
		
			}while(op<1 || op>4);
		
		
			switch(op){
			
				case 1:{
					
					do{
										
						if(sortStatus[2]){
												
						std::cout<<"Rango entre Cedulas: "<<std::endl << std::endl;
						//Rango Cedulas	
						int c1,c2;
						int lim1, lim2;
				
						abrir(std::ios::in | std::ios::binary);	
									
						std::cout<<"Ingrese la primera CI: ";
						std::cin>>c1;
						
						std::cout<<"Ingrese la segunda CI: ";
						std::cin>>c2;
							
						lim1=Busqueda_Binaria(0,tamanho,c1);
						lim2=Busqueda_Binaria(0,tamanho,c2);
						
						if(lim1 >= lim2){
							int aux = lim2;
							lim2 = lim1;
							lim1 = aux;						
						}
						
						std::cout << '\n';
						
				    	if( (lim1 == -1) || (lim2 == -1) )
				    	std::cout << "Rango Invalido, No se han encontrado ambas o alguna cedula." << '\n';
				    	else
				    	this->imprimirBin(lim1,lim2);					
				    	cerrar();
				    	resp = 'N';
				    	}else{
				    		
				    		std::cout << "El archivo no se encuentra ordenado con criterio de Cedulas actualmente" << '\n';
				    		std::cout << "Desea ordenarlo de esta forma e iniciar la busqueda inmediatamente? S/N" << '\n';
				    		std::cin >> resp;
							
							if(resp == 'S' || resp == 's'){
								Mezcla_Directa(3);	
								for(int i = 1; i < 5; i++)
								if(i == 2)
								sortStatus[i] = true;
								else
								sortStatus[i] = false;						
							}	
						}		
					
					}while(resp!='N' && resp!= 'n');
				
					break;
				}
				
				case 2:{
					std::cout<<"Cadenas en nombre: "<<std::endl << std::endl;
					char a[50],b[50];
					std::cin.ignore();
					std::cout<<"Ingrese un nombre: ";std::cin.getline(a,50);
					std::cout<<"Ingrese un nombre: ";std::cin.getline(b,50);
					
					imprimirBin(a,b);	
					
					break;
					
				}
				
				case 3:{
					
					do{
						
						if(sortStatus[1]){
										
						bool foundA = false, foundB = false;
										
						std::cout<<"Rango entre Estados: "<<std::endl << std::endl;
						char a[50],b[50];
						std::cin.ignore();
						std::cout<<"Ingrese un estado: ";std::cin.getline(a,50);
						std::cout<<"Ingrese un estado: ";std::cin.getline(b,50);
						
						for(int i = 0; i < this->totalEstados && (!foundA || !foundB);i++){
							
							if(!foundA){
								if(strcmpi(a,this->estado[i])==0)
								foundA = true;						
							}
							
							if(!foundB){
								if(strcmpi(b,this->estado[i])==0)
								foundB = true;						
							}
														
						}
						
						if(foundA && foundB){
												
						if(strcmpi(a,b) >= 0){
							char aux[50];
							strcpy(aux,a);
							strcpy(a,b);
							strcpy(b,aux);						
						}
												
						imprimirBin(a,b,false);	
						
						}else{
							std::cout << "No se han encontrado ambos o un Estado en el registro." << std::endl;
						}
						
						
						resp = 'N';
						}else{
					
						std::cout << "El archivo no se encuentra ordenado con criterio de Estados actualmente" << '\n';
				  	 	std::cout << "Desea ordenarlo de esta forma e iniciar la busqueda inmediatamente? S/N" << '\n';
				  		std::cin >> resp;
							
							if(resp == 'S' || resp == 's'){
								Mezcla_Directa(2);	
								for(int i = 1; i < 5; i++)
								if(i == 1)
								sortStatus[i] = true;
								else
								sortStatus[i] = false;						
							}	
										
						}
						
					}while(resp!='N' && resp!= 'n');
						
					break;
				}
				case 4:{
					return;
					break;
				}	
			}
		
			system("pause>0");
	
		}


		void menuPrincipal(){
	
			int op=0;
			bool sortStatus[4];
			
			for(int i = 0; i < 4; i++)
				sortStatus[i] = true;
			
			verificarStatus(sortStatus);
			
				do{
		
				system("cls");
				std::cout<<"\tSelecciona Opcion:"<<std::endl;
				std::cout<<"\t\t 1)Clasificar los registros por orden especifico"<<std::endl;
				std::cout<<"\t\t 2)Mostrar personas inscritas en un estado"<<std::endl;
				std::cout<<"\t\t 3)Busqueda avanzada"<<std::endl;
				std::cout<<"\t\t 4)Generar archivo texto ordenado por dos claves"<<std::endl;
				std::cout<<"\t\t 5)Mostrar registro actual"<<std::endl;
				std::cout<<"\t\t 6)Salir"<<std::endl;
				std::cout<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl;
	
				do{	
		
				std::cout<<"Ingrese una opcion: ";
				std::cin>>op;
		
				}while(op<1 || op>6);
			
				switch(op){
				
					case 1:{
						menuClasificacion(sortStatus);
						break;
					}
			
					case 2:{			
						char estado[150];
						strcpy(estado,seleccionarEstado());	
						system("cls");	
						imprimirEstado(estado);
						system("pause>0");
						break;
					}
			
					case 3:{
						busquedaAvanzada(sortStatus);
						break;
					}
			
					case 4:{
						Mezcla_Directa(2);
						std::cout<<"1era Fase de Ordenamiento: Estados"<<std::endl;
						Mezcla_Directa(5);
						std::cout<<"2da Fase de Ordenamiento: Cedulas"<<std::endl;
						this->generarAr();
						std::cout<<"Se ha generado el archivo clasifica.txt"<<std::endl;
						system("pause>0");
						break;
					}
			
					case 5:{
						imprimirBin();
						system("pause>0"); // imprimir el archivo binario
						break;
					}
					
				}

			}while(op!=6);
	
		std::cout << "Integrantes: " << std::endl;
		std::cout << "Javier Martinez V-24338432" << std::endl;
		std::cout << "Neptali Duque V-24355188" << std::endl;
		
		}
	
		void generarAr(){
					
			std::ofstream a2;
			a2.open("clasifica.txt");
			abrir( std::ios::in | std::ios::binary);
			Persona f;
			a2 << std::setw(15) << std::left << "Estado" << std::setw(15) << std::left << "Cedula" << std::setw(15) << std::left <<"Nombre" << std::endl;
			while(true){
				leerBin(f);
				if(finArchivo())
				break;
				a2 <<  std::setw(15) << std::left << f.getEstado() << std::setw(15) << std::left << f.getCedula() << std::setw(15) << std::left << f.getNombre() << std::endl;				
			}
			
			a2.close();
			cerrar();			
	
		}	

		
		
};

char ArchivoMadre::estado[][30]= { "AMAZONAS", "ANZOATEGUI", "APURE", "ARAGUA", "BARINAS", "BOLIVAR", "CARABOBO", "COJEDES", 
					"DELTA AMACURO", "DISTRITO CAPITAL", "FALCON", "GUARICO", "LARA", "MERIDA", "MIRANDA", "MONAGAS",
					"NUEVA ESPARTA", "PORTUGUESA", "SUCRE", "TACHIRA", "TRUJILLO", "VARGAS", "YARACUY", "ZULIA",
					"DEPENDENCIAS FEDERALES"
					};

int ArchivoMadre::totalEstados = 25;

#endif

