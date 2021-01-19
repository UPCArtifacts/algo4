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
	
	//Exo 2:
	Stock monMagasin;
	//Init  du Stock
	monMagasin.debut = NULL;
	monMagasin.fin = NULL;
	
	int nrProductsToAdd;
	
	printf("Enter number  of products to be added: \n" );
	scanf("%d", &nrProductsToAdd);
	
	for (int i=0;i<nrProductsToAdd;i++){
				printf("\nEnter Name of product nr %d \n",i+1 );
				scanf("%s", productName);
				
				int quantity;
				printf("Enter Quantity of product nr %d \n",i+1 );
				scanf("%d", &quantity);
				
				float prixUni;
				printf("Enter Prix of product nr %d \n",i+1 );
				scanf("%f", &prixUni);
				
				Produit * newProduit = createProduit(productName, quantity, prixUni);
				printf("Product created with name: %s\n",newProduit->idP );
				insertNewProduct(&monMagasin, newProduit);
	}
	
	//Exo 3
	printf("Printing stock: \n");
	printStock(monMagasin);
	

	printf("\nEnd\n");
	return 0;
}
