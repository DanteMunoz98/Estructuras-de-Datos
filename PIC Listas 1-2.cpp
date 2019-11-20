#include <stdio.h>
#include <stdlib.h>

struct G_Info{
	char Nombre;
	int ATK;
	int DEF;
	int Nivel;
	struct G_Info* sig;
};

struct G_Info* NuevaC(struct G_Info* lista, char Nombre, int ATK, int DEF,int Nivel){
	struct G_Info* NuevaC=NULL;
	NuevaC=(struct G_Info* )malloc(sizeof(struct G_Info));
	if(NuevaC==NULL){
		printf("Revisa que pedo mi rey, ya te acabaste la memoria paps");
		return NULL;
	}
	NuevaC->ATK=ATK;
	NuevaC->DEF=DEF;
	NuevaC->Nivel=Nivel;
	NuevaC->Nombre=Nombre;
	NuevaC->sig=lista;
	//printf("Nuevo dato ingresado\n ");
	return NuevaC;
}

void Imprimir(struct G_Info*l){
	while(l!=NULL){
		printf("%c %d %d %d",l->Nombre,l->ATK,l->DEF,l->Nivel );
		l=l->sig;
		//printf("Datos mostrados");
		printf("\n");
	}
	printf("\n");
}

struct Tablero{
	char Nombre;
	int ATK;
	int DEF;
	int Nivel;
	struct Tablero* sig;
};

struct Tablero* slot(struct Tablero*t, char Nombre, int ATK,int DEF, int Nivel){
	struct Tablero* slot=NULL;
	slot=(struct Tablero*)malloc(sizeof(struct Tablero));
	if(slot==NULL){
		return NULL;
	} 
	slot->ATK;
	slot->DEF;
	slot->Nivel;
	slot->Nombre;
	slot->sig=t;
	printf(" ----- \n| %d %d  |\n ----- \n",slot->ATK,slot->DEF);
	return slot;
}

struct Mano{
	char Nombre;
	int ATK;
	int DEF;
	int Nivel;
	struct Mano* sig;
};

struct Mano* M(struct Mano*t, char Nombre, int ATK,int DEF, int Nivel){
	struct Mano* M=NULL;
	M=(struct Mano*)malloc(sizeof(struct Mano));
	if(M==NULL){
		return NULL;
	} 
	M->ATK;
	M->DEF;
	M->Nivel;
	M->Nombre;
	M->sig=t;
	
	return M;
}

struct Cem{
	char Nombre;
	int ATK;
	int DEF;
	int Nivel;
	struct Cem*sig;
};

struct Deck{
	char Nombre;
	int ATK;
	int DEF;
	int Nivel;
	struct Deck*sig;
};

//void Reglas(struct G_Info*C){
//	C=C->Nivel;
//	if(C<5){
		
//}

int main (void){
	struct G_Info* Info=NULL;
	
	Info=NuevaC(Info,'a',120,100,8);
	Info=NuevaC(Info,'b',180,60,6);
	Info=NuevaC(Info,'c',80,180,3);
	Info=NuevaC(Info,'d',0,190,5);
	Info=NuevaC(Info,'e',10,30,9);
	Info=NuevaC(Info,'f',200,110,2);
	Info=NuevaC(Info,'g',70,120,1);
	Info=NuevaC(Info,'h',50,150,8);
	Info=NuevaC(Info,'i',160,10,6);
	Info=NuevaC(Info,'j',140,30,4);
	//Imprimir(Info);
	int i=0;
	struct Tablero* T;
	for(i;i<3;i++){
		T=slot(T,NULL,NULL,NULL,NULL);
		Info=Info->sig;
		printf(" ----- \n| %d %d  |\n ----- \n",Info->ATK,Info->DEF);
	}	
	//while(1){
		
	//}
}
