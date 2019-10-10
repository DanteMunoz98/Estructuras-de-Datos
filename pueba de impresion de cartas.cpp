#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct G_Info{
	char *Nombre;
	int ATK;
	int DEF;
};

G_Info* Info;

void fri(char X[]){
	int I;
	for(I=0;I<30;I++){
		X[I]='\0';
	}
}

char Mostrar_N(struct G_Info*Info){
	
}

void copy_N(char X[],int C){
	int N=strlen(X)+1;
	Info[C].Nombre=(char*)malloc(N*sizeof(char));
	if(Info[C].Nombre==NULL){
		printf("Revisa que pedo mi rey, ya te acabaste la memoria paps\n");
	}
	strcpy(Info[C].Nombre,X);
}

int main (){
	int C=0;
	int A=0;
	char X[500];
	FILE* cartas;
	cartas=fopen("Personajes.txt","r");
	if(cartas==NULL){
		printf("E we algo hiciste mal XD");
	}
	else{
		while(!feof(cartas)){
		fgets(X,100,cartas);
		A++;
		//printf("%d, ",A);
		}
		printf("\n");
	}
	rewind(cartas);
	Info=(G_Info*)malloc(A*sizeof(G_Info));
	if(Info==NULL){
		printf("No hay memoria ue");
	}
	for(C;!feof(cartas);C++){
		int E;
		fri(X);
		char R='0';
		for(E=0;R!=',';E++){
			R=fgetc(cartas);
			if(R!=','){
				X[E]=R;
			}
		}
		copy_N(X,C);
		fgets(X,31,cartas);
		Info[C].ATK=atoi(X);
		fgets(X,6,cartas);
		Info[C].DEF=atoi(X);
		printf("Nombre: %s \n ATK:%i , DEF:%i \n",Info[C].Nombre,Info[C].ATK,Info[C].DEF);
	}
	Mostrar(Info);
	return  0;
}
