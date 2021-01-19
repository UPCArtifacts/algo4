#include <stdio.h>
#include <string.h>
// Array of Char
typedef char Chaine[15];

typedef struct pdt { 
	Chaine idP; // identifiant Produit 
   int nbP; // quantite en Stock 
  float PU; // prix unitaire
  struct pdt *suiv, *  prec ; // pointeurs vers le suivant et le precedent 
} Produit, *  Liste;

typedef struct { Liste debut, fin ; } Stock ;


//Exo 1- creation of Produit

Produit *  createProduit(Chaine identif, int quant, float prix){

	Produit * pNewProduct = NULL;

	pNewProduct = (Produit *) malloc(sizeof(Produit));
	
	strcpy(pNewProduct-> idP, identif);
	//;pNewProduct-> idP = identif;
	pNewProduct->nbP = quant;
	pNewProduct->PU = prix;
	
	return pNewProduct;
}


int main(int argc, char **argv)
{
	
	printf("TD 3 Exo 1- Listes doubles \n");
	
	char productName[15];
	
	printf("Enter Name of product: \n" );
	scanf("%s", productName);
	
	int quantity = 19;
	float prixUni = 0.5;
	Produit * newProduit = createProduit(productName, quantity, prixUni);
	
	printf("Product created with name: %s",newProduit->idP );
	
	printf("\nEnd\n");
	
	
	
	return 0;
}
