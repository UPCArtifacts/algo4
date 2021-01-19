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

//Exo 2: 
void insertNewProduct(Stock * currentStock, Produit * newProduct){
	
	//Insert newProduct into current Stock
	//Case 1: Stock is empty:
	if( currentStock-> debut == NULL &&  currentStock-> fin == NULL ){
		currentStock-> debut = newProduct;
		currentStock-> fin = newProduct;
	}else{
	    // Case 2:  Stock is not empty:
		// Add at the end:
	 Produit *  previousEnd = currentStock-> fin ;
	 // New product is the last one, so prec is the element that was previosly at the end.
	 newProduct -> prec = previousEnd;
	 // New product goes to the end of the list, so suiv is Null
	 newProduct -> suiv = NULL;
	 
	 // The element that was at the end now has a next element.
	 previousEnd -> suiv = newProduct;
	 
	 //Now the stock has a new last element
	 currentStock -> fin = newProduct;
	 
	}
	
}

//exo 3 print:

void printStock(Stock myStock){
	
	//
	Produit * currentProduct = myStock.debut;
	int nrProduct = 0;
	while (currentProduct != NULL){
		nrProduct++;
		printf("nrProduct %d:  ID %s  Quantity: %d Prix %f \n", 
		 nrProduct,currentProduct->idP, currentProduct->nbP, currentProduct->PU   );
		
		currentProduct = currentProduct -> suiv;
		}
	
	
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
	
	printf("Enter Name of product 2: \n" );
	scanf("%s", productName);
	quantity = 29;
	prixUni = 3;
	Produit * newProduit2 = createProduit(productName, quantity, prixUni);
	
	
	printf("Product created with name: %s",newProduit->idP );
	
	printf("\nEnd\n");
	
	
	//Exo 2:
	Stock myStock;
	//Init  du Stock
	myStock.debut = NULL;
	myStock.fin = NULL;
	
	insertNewProduct(&myStock, newProduit);
	
	insertNewProduct(&myStock, newProduit2);
	
	//Exo 3
	printf("Printing stock: \n");
	printStock(myStock);
	
	
	return 0;
}
