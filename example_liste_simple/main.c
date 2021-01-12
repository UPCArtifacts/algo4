#include <stdio.h>

/// Exo 1

struct Client{
	int nrClient;
	int identifier;
	};

struct _cell{
	int valeur;
	//Si je veux une liste de Client, je change la valeur de la cellule i.e., du champ 'valeur' 
	//struct Client valeur;
	struct _cell * suiv;
};

// Redefinition of type: now we call 'CELL' to 'struct _cell'
typedef struct _cell CELL;
// Equivalent: 
//typedef struct _cell{
//	int valeur;
//	struct _cell * suiv;
//} CELL;

// 
typedef CELL * LIST;

// Exo 2 TD 2. Create cell
   CELL* createCell(int valueDeLaCellule){
	
	CELL* newCell;
	newCell = (CELL*) malloc(sizeof(CELL));
	//Affectation -init-
	newCell->valeur = valueDeLaCellule;
	newCell->suiv = NULL;
	// return l addresse òu nous avons stocké la nouvelle cellule.
	return newCell;
}

// Avec Client: 
//CELL* createCell(struct Client valueOfClient){
//....
///}

//CELL* createCell(int nrClient, int identifier){
//...
//}

LIST addFirst(LIST listExistent, CELL * elementToAdd){
	
	elementToAdd->suiv = listExistent;
	listExistent = elementToAdd;
	return listExistent;
	
}

void printList(LIST listToPrint){
//recursive
  if(listToPrint != NULL){
	   printf("v: %d", listToPrint->valeur);
	   printList(listToPrint->suiv);
	  }	

}

LIST addLast(LIST listExistent, CELL * elementToAdd){
	
	if(listExistent == NULL){
			return elementToAdd; 
	}
	else{
		listExistent->suiv = addLast(listExistent->suiv, elementToAdd);
		return listExistent;
		}
	
}

int main(int argc, char **argv)
{
	printf("hello world TD 2 Liste Simple\n");
	
	printf("Exo 2: \n");
	
	int valueOfNewElement = 10;
	CELL * createdCellDix = createCell(valueOfNewElement);
	//Equivalent: LIST est la redeclaration de CELL * (Regardez le typedef)
	//LIST createdCellDix = createCell(valueOfNewElement);
	
	printf("La valeur à l'interieur de la cellule est: %d", createdCellDix->valeur);
	//equivalent:
	//printf("La valeur à l'interieur de la cellule est: %d", (*createdCellDix).valeur);
	
	// Exo 3
	LIST myList = NULL;

	myList = addFirst(myList, createdCellDix);
	
	// Exo 5: 
	printf("\nPrint list:\n");
	
	printList(myList);
	
	///Ajouter une nouvelle cellule au debut
	CELL * createdCellOnce = createCell(11);
	myList = addFirst(myList, createdCellOnce);
	
	printf("\nPrint list updated with 11:\n");
	
	printList(myList);
	
	
	// Exo 4: 
		//Ajouter une nouvelle cellule a la fin
	printf("\nPrint list updated 9:\n");
	CELL * createdCellNeuf = createCell(9);
	myList = addLast(myList, createdCellNeuf);
	printList(myList);
	
	return 0;
}