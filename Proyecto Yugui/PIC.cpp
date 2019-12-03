#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char
Cartas_M ()
{
  char C;
  FILE *Archivos_de_cartas;
  Archivos_de_cartas = fopen ("Personajes.txt", "r");
  if (Archivos_de_cartas == NULL)
    {
      printf ("Error");
    }

  else

    {
      printf ("\nLos mounstruos que tienes son: \n\n");
      while ((C = fgetc (Archivos_de_cartas)) != EOF)

	{
	  printf ("%c", C);
	}
    }
  fclose (Archivos_de_cartas);
  return 0;
}

char
Cartas_m ()
{
  char C;
  FILE *Archivos_de_cartas;
  Archivos_de_cartas = fopen ("Magicas.txt", "r");
  if (Archivos_de_cartas == NULL)
    {
      printf ("Error");
    }

  else

    {
      printf ("\nLas cartas magicas que tienes son: \n\n");
      while ((C = fgetc (Archivos_de_cartas)) != EOF)

	{
	  printf ("%c", C);
	}
    }
  fclose (Archivos_de_cartas);
  return 0;
}

struct G_Info
{
  char *Nombre;
  int ATK;
  int DEF;
};
G_Info *Info;
void
fri (char X[])
{
  int I;
  for (I = 0; I < 30; I++)
    {
      X[I] = '\0';
    }
}

void
copy_N (char X[], int C)
{
  int N = strlen (X) + 1;
  Info[C].Nombre = (char *) malloc (N * sizeof (char));
  if (Info[C].Nombre == NULL)
    {
      printf ("Revisa que pedo mi rey, ya te acabaste la memoria paps\n");
    }
  strcpy (Info[C].Nombre, X);
}

int
main ()
{

  //Cartas_M();
  //Cartas_m();
  int C = 0;
  int A = 0;
  char X[1000];
  FILE *cartas;
  cartas = fopen ("Personajes.txt", "r");
  if (cartas == NULL)
    {
      printf ("E we algo hiciste mal XD");
    }

  else
    {
      while (!feof (cartas))
	{
	  fgets (X, 1000, cartas);
	  A++;

	  //printf("%d, ",A);
	}
      printf ("\n");
    }
  rewind (cartas);
  Info = (G_Info *) malloc (A * sizeof (G_Info));
  if (Info == NULL)
    {
      printf ("No hay memoria ue");
    }
  for (C; !feof (cartas); C++)
    {
      int E;
      fri (X);
      char R = '0';
      for (E = 0; R != ','; E++)
	{
	  R = fgetc (cartas);
	  if (R != ',')
	    {
	      X[E] = R;
	    }
	}
      copy_N (X, C);
      fgets (X, 200, cartas);
      Info[C].ATK = atoi (X);

      //      for(E;R!='-';E){
      Info[C].DEF = atoi (X);

      //      }
      printf ("Nombre: %s \n ATK:%i , DEF:%i \n", Info[C].Nombre,
	      Info[C].ATK, Info[C].DEF);
    }
}
