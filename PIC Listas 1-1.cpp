#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct G_Info{
	char Nombre;
	int ATK;
	int DEF;
	struct G_Info* sig;
};


struct G_Info* NuevaC(struct G_Info* lista,int Nombre){
	struct G_Info* NuevaC=NULL;
	NuevaC=(struct G_Info* )malloc(sizeof(struct G_Info));
	if(NuevaC==NULL){
		printf("Revisa que pedo mi rey, ya te acabaste la memoria paps");
		return NULL;
	}else{
		NuevaC->Nombre=Nombre;
		NuevaC->sig=lista;
	}
	return NuevaC;
}

int main (){
	FILE* cartas;
	cartas=fopen("Personajes.txt","r");
	if(cartas==NULL){
		printf("E we algo hiciste mal XD");
	}
	else{	
		struct G_Info* NC=NULL;
		
	//	NC(NuevaC);
		
	}
//	printf("Nombre: %s \n ATK:%i , DEF:%i \n",);
	}
