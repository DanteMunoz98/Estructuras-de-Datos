#include <stdio.h>
#include <stdlib.h>

struct G_Info			//strcut lista de Informacion de cartas
{

  char Nombre;

  int ATK;

  int DEF;

  int Nivel;

  struct G_Info *sig;

};


struct Tablero			//struct lista de tablero
{

  char Nombre;

  int ATK;

  int DEF;

  int Nivel;

  struct Tablero *sig;

};


struct Mano			//struct lista de Mano
{

  char Nombre;

  int ATK;

  int DEF;

  int Nivel;

  struct Mano *sig;

};


struct G_Info *
NuevaC (struct G_Info *lista, char Nombre, int ATK, int DEF, int Nivel)	//Creacion de las cartas y guardado en el deck
{

  struct G_Info *NuevaC = NULL;

  NuevaC = (struct G_Info *) malloc (sizeof (struct G_Info));

  if (NuevaC == NULL)

    {

      printf ("Revisa que pedo mi rey, ya te acabaste la memoria paps");

      return NULL;

    }

  NuevaC->ATK = ATK;

  NuevaC->DEF = DEF;

  NuevaC->Nivel = Nivel;

  NuevaC->Nombre = Nombre;

  NuevaC->sig = lista;

  //p rintf("Nuevo dato ingresado\n ");
  return NuevaC;

}



void
Imprimir (struct G_Info *l)	//Impresion de cartas en pantalla
{

  while (l != NULL)

    {

      printf ("%c %d %d %d", l->Nombre, l->ATK, l->DEF, l->Nivel);

      l = l->sig;

      //printf("Datos mostrados");
      printf ("\n");

    }

  printf ("\n");

}



struct Tablero *
slot (struct Tablero *t, char Nombre, int ATK, int DEF, int Nivel)	//Creacion del tablero
{

  struct Tablero *slot = NULL;

  slot = (struct Tablero *) malloc (sizeof (struct Tablero));

  if (slot == NULL)

    {

      return NULL;

    }

  slot->ATK;

  slot->DEF;

  slot->Nivel;

  slot->Nombre;

  slot->sig = t;

  printf (" ----- \n|     |\n ----- \n");

  return slot;

}



struct Mano *			//Creacion de la mano
M (struct Mano *t, char Nombre, int ATK, int DEF, int Nivel)	//
{

  struct Mano *M = NULL;

  M = (struct Mano *) malloc (sizeof (struct Mano));

  if (M == NULL)

    {

      return NULL;

    }

  M->ATK;

  M->DEF;

  M->Nivel;

  M->Nombre;

  M->sig = t;

  printf ("" "\n|  |\n" "");

  return M;

}



int
DM (struct Mano *m, struct G_Info *Info)
{				//Funcion que manda las "cartas" de la mano al tablero
  system ("cls");

  struct G_Info *a;

  if (Info != NULL && m->ATK == 0)
    {

      a->ATK = Info->ATK;

      a->DEF = Info->DEF;

      a->Nombre = Info->Nombre;

      a->Nivel = Info->Nivel;

      a->sig = Info->sig;

      m->ATK = a->ATK;

      m->DEF = a->DEF;

      m->Nombre = a->Nombre;

      m->Nivel = a->Nivel;

      m = m->sig;

    }

  Info = Info->sig;

  m = m->sig;

  free (Info);

}


//}

int
MT (struct Mano *m, struct Tablero *t)
{				//Invocacion Mano-Tablero
  system ("cls");

  if (t->ATK == 0)
    {

      t->ATK = m->ATK;

      t->DEF = m->DEF;

      t->Nombre = m->Nombre;

      t->Nivel = m->Nivel;

    }
  else
    {

      m = m->sig;

      t = t->sig;

    }

  free (m);

}




int
ITM (struct Mano *m, struct Tablero *t)
{				//Impresion Tablero-Mano
  system ("cls");

  int C = 0;
  for (C; C < 3; C++)
    {

      printf ("" "\n| %d %c |\n" "", m->ATK, m->Nombre);

    }

  printf ("\n");

  for (C = 0; C < 3; C++)
    {

      printf (" -------- \n| %d %c  |\n -------- \n", t->ATK, t->Nombre);

    }

}



int
main (void)
{

  struct G_Info *Info = NULL;


  Info = NuevaC (Info, 'a', 120, 100, 8);	//Creacion de las cartasde manera manual

  Info = NuevaC (Info, 'b', 180, 60, 6);

  Info = NuevaC (Info, 'c', 80, 180, 3);

  Info = NuevaC (Info, 'd', 10, 190, 5);

  Info = NuevaC (Info, 'e', 200, 30, 9);

  Info = NuevaC (Info, 'f', 20, 110, 2);

  Info = NuevaC (Info, 'g', 70, 120, 1);

  Info = NuevaC (Info, 'h', 50, 150, 8);

  Info = NuevaC (Info, 'i', 160, 10, 6);

  Info = NuevaC (Info, 'x', 100, 30, 8);


  //Imprimir(Info);                                                             //Impresion de cartas.Si es necesario
  int i = 0;

  struct Tablero *T;

  for (i; i < 3; i++)		//Creacion de los 3 ranuras de tablero
    {

      T = slot (T, 0, 0, 0, '0');

    }

  struct Mano *m;

  for (i = 0; i < 3; i++)	//Creacion de los 3 lugares que tendra la mano para las cartas
    {

      m = M (m, 0, 0, 0, '0');

    }

  int LP = 1000;

  DM (m, Info);
  ITM (m, T);
  char O;			//Deck a Mano, la primera recogida en el juego
  while (LP != 0)
    {

      printf ("\nElija:\nI:invocar\nA:Atacar\n");

      O = getchar ();

      printf ("%d\n", LP);

      switch (O)
	{
	case 'i':

	case 'I':

	  MT (m, T);

	  ITM (m, T);

	  // DM (m, Info);

	  O = 'q';

	  break;

	case 'a':

	case 'A':

	  LP = LP - T->ATK;

	  if (LP <= 0)

	    {
	      LP = 0;

	    }

	  ITM (m, T);

	  O = 'Q';

	  break;

	default:

	  printf ("---Elije I o A---\n");

	}

    }

  printf ("Has ganado\n");

  system ("cls");

  free (Info);

  free (m);

  free (T);

}
