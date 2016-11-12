#include <iostream>
#include "Listas/Listas.h"
#include "Colas/Colas.h"
#include "Pilas/Pilas.h"
#include "DString.h"
#include <fstream>
#include <cstdlib>
#include <typeinfo>
#include <sstream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

PilaD<DString> ruta;

struct Town{
	DString Nombre;
	float Distancia;		
}typedef Pueblo;

class Ciudad{
	private:
		
		
		
	public:
		int Codigo;
		float Distancia;
		DString Name;
		ListaDE<Pueblo> *cercanias;
		
		
		Ciudad(int c,float d,DString nom):Codigo(c),Distancia(d),Name(nom){
		this->cercanias=new ListaDE<Pueblo>();
		std::ifstream file("pueblos.txt");
		char f[150];
		
		while(true){
			file.getline(f,150);
			if(file.eof())
			break;	
			
			std::istringstream isis(f);
			char aux[300];
			isis.getline(aux,300,',');
			int  cod=atoi(aux);	
			Pueblo agre;
			
			
				if(cod==Codigo){
				
					isis.getline(aux,300,',');
					agre.Nombre=aux;
					
					isis.getline(aux,300);
					agre.Distancia=atof(aux);
					
					this->cercanias->Add(agre,false);
				
				}
			
			
			
			
					
		}
		
		
		
		}
	
		void Ver(){
			Pueblo f;
			std::cout<<"Codigo "<<Codigo<<" Nombre:" <<Name<<std::endl;
			std::cout<<"Pueblito: "<<" Distancia"<<std::endl;
			
			for(int i=0;i<this->cercanias->TAM();i++){
				this->cercanias->Extract(f,i);
				std::cout<<f.Nombre<<"      "<<f.Distancia<<std::endl;
				
			}
			
			std::cout<<"Distancia:"<<Distancia<<std::endl
			<<"----------------------------------------"<<std::endl;
			
			
		}	
	
	
	
};
ListaDE <Ciudad*> city;
template <typename ED>
bool pueblos(Ciudad*cit,DString encontrar,ED &pil){
	
	for (int i=0;i<cit->cercanias->TAM();i++){
		Pueblo aux;
		cit->cercanias->Extract(aux,i);
	//	std::cout<<aux.Nombre;
		pil.Put(aux);
		if(aux.Nombre==encontrar)
		return true;
	
	}
	
	pil.Delete();
	return false;
	
	
	
	
	
	
	
	
}







int main(int argc, char** argv) {
		
		std::ifstream file("ciudades.txt");
		char f[150];
		while(true){
			
			file.getline(f,150);
			if(file.eof())
			break;	
			
			std::istringstream isis(f);
			char aux[300];
			isis.getline(aux,300,',');
			int  cod=atoi(aux);	
		
			
			
				
				
					isis.getline(aux,300,',');
					DString name=aux;
					
					isis.getline(aux,300);
					float dis=atof(aux);
					city.Add(new Ciudad(cod,dis,name) ,false);

				
			
			
			
			
			
			
		}
			Ciudad *oo;
			for(int i=0;i<city.TAM();i++){
			city.Extract(oo,i);
			oo->Ver();
		}
		DString enc,destino;
		std::cout<<"Buscar origen ";
		std::cin>>enc;
		std::cout<<"Destino ";
		std::cin>>destino;
		
		
		
		PilaD<Pueblo> ori;
		ColaN<Pueblo> des;
	
		bool loencontro=false,loencontro2=false;
		short i1=0,i2=0;
		
		
		for(int i=0;i<city.TAM();i++){
			city.Extract(oo,i);
		//	oo->Ver();
			
			
			if(!loencontro){
				
				
				loencontro=pueblos(oo,enc,ori);
				if(oo->Name==enc)
				loencontro=true;
						
				if(loencontro)
				i1=i;	
				
			}
			
			
			
			if(!loencontro2){
				
				loencontro2=pueblos(oo,destino,des);
				if(oo->Name==destino)
				loencontro2=true;
				
				if(loencontro2)
				i2=i;	
				
			}
			
			
			
			
			
			
			
		}
		if(loencontro && loencontro2)
		std::cout <<"Loencontre"<<std::endl;
		
			
		
		file.close();
		float dis=0;
		DString data;
		Pueblo extr;
		int recor=ori.TAM();
		
		while(recor>0){
			ori.Extract(extr);
			std::cout<<extr.Nombre<<std::endl;
			ruta.Put( extr.Nombre);
			dis+=extr.Distancia;
			recor--;
			
		}
		if(i2>i1){
			for(int i=i1;i<=i2;i++){
				city.Extract(oo,i);
				std::cout<<oo->Name<<std::endl;
				ruta.Put(oo->Name);
				dis+=oo->Distancia;
				
			}	
			
			
		}
		if(i2<i1){
			for(int i=i1;i>=i2;i--){
				city.Extract(oo,i);
				std::cout<<oo->Name<<std::endl;
				ruta.Put(oo->Name);
				dis+=oo->Distancia;
				
			}
			
			
			
			
		}
		recor=des.TAM();
		while(recor>0){
			des.Extract(extr);
			std::cout<<extr.Nombre<<std::endl;
			ruta.Put( extr.Nombre);
			dis+=extr.Distancia;
			recor--;
			
		}
		if(loencontro && loencontro2)
		std::cout<<" Encontrados "<<std::endl;
		
		
		std::cout<<"----------------------------"<<std::endl;
		DString caminofinal;
		while(ruta.TAM()>0){
			ruta.Extract(caminofinal);
			std::cout<<caminofinal<<"<-";
			
		}
		std::cout <<std::endl<<dis<<std::endl;
		
		
		
		

/*
Nodo<Ciudad*> *asco=new Nodo<Ciudad*>(new Ciudad(44,3,"Javier"));
	 void* fffff=asco;
	Ciudad *aps= ( (Nodo<Ciudad*> *)  fffff)->datNodo();
	aps->Ver();
	
	

	DString Busqueda,Destino;
	std::cout<<"Ingrese el origen: ";
	std::cin>>Busqueda;
	ruta.Put(Busqueda);
	std::cout<<"Ingrese Destino ";
	std::cin>>Destino;
	DeterminarInicio(Busqueda);



*/	
	
	
	
	
	
	return 0;
}


