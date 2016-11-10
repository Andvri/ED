#ifndef DSTRING_H
#define DSTRING_H

#include <iostream>
#include <cstring>

class DString
{
	private:
		char *V;
		size_t l;
	public:
		

		//Constructor por defecto
		DString(){
			this->l=1;
			this->V=new char [this->l];
		}

		//Constructor parametrizado
		DString(const char *c){
		this->l = strlen(c);
		this->V=new char[this->l];
		strcpy(this->V,c);

		}
		
		//Constructor Copia
		DString(const DString&a){
			*this=a;
		}

	
	DString& operator =(const DString &a){
			this->l=a.l;
			this->V=new char[this->l];
			this->V=a.V;
		return *this;
	}
	
	DString& operator =(const char *c){
		this->l=strlen(c);
		this->V=new char[this->l];
		strcpy(this->V,c);
		return *this;
		
	
	}
	
	char at(int index){
		
		if(index >= l){
			return -1;
		}
		
		return V[index];
		
	}
	friend std::ostream& operator << (std::ostream &o,const DString &p)
	{
    o << p.V;
    return o;
	}


	friend std::istream& operator >> (std::istream &i, DString &p){
    char c[1000];
    i.getline(c,1000);
    p.l=strlen(c);
    p.V=new char[p.l];
	strcpy(p.V,c);
    return i;
	}
	
	
	bool operator ==(const DString &B){
	if(strcmpi(this->V,B.V )==0 )
		return true;
		
	return false;
		
	}
	bool operator ==(const char *B){
	if(strcmp(this->V,B )==0 )
		return true;
	
	return false;
		
	}
	
	bool operator<(const DString &B){
		return strcmpi(this->V,B.V) < 0;
	}
	
	DString& operator +(const DString&a){
		size_t red=a.l+this->l;
		char *f =new char [red];
		strcpy(f,this->V);
		delete this->V;
		this->V =new char[red];
		strcat(f,a.V);
		strcpy(this->V,f);
		return *this;
		
		
	}
	
	DString& operator +(const char*a){
		size_t red=strlen(a)+this->l;
		char *f =new char [red];
		strcpy(f,this->V);
		delete this->V;
		this->V =new char[red];
		strcat(f,a);
		strcpy(this->V,f);
		return *this;
		
		
	}
	

	char* vChar(){
		return this->V;
	}


	int size(){
		return this->l;
	}
	

};

#endif
