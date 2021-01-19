#include <stdio.h>

// Array of Char
typedef char Chaine[15];

typedef struct pdt { 
	Chaine idP; // identifiant Produit 
   int nbP; // quantite en Stock 
  float PU; // prix unitaire
  struct pdt *suiv, *  prec ; // pointeurs vers le suivant et le precedent 
} Produit, *  Liste;

typedef struct { Liste debut, fin ; } Stock ;

int main(int argc, char **argv)
{
	
	printf("TD 3 Exo 1- Listes doubles \n");
	return 0;
}
