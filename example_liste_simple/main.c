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

int countVal(LIST listExistent){
	
	if(listExistent == NULL){
		return 0;
	}
	else{
		return 1 + countVal(listExistent->suiv);
		}
	}
	
int countValIter(LIST listExistent){
	int count = 0;
	while(listExistent != NULL){
			count = count + 1;
			listExistent = listExistent->suiv;
		}
	return count;
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


LIST removeFirst(LIST listExistent){

	if(listExistent == NULL){
		return NULL;
	}else{
		LIST oldFirst = listExistent;
		LIST newFirst =  listExistent->suiv;
		
		free(oldFirst);
		
		return newFirst;
	}
	
}


int infList(LIST listExistent){
   
	if(listExistent != NULL){
	     
		if(listExistent->suiv == NULL)
			return   listExistent->valeur;
		else{
			int valueInf = infList(listExistent->suiv);
			if( listExistent->valeur < valueInf){
				  return  listExistent->valeur;
			}else{
				return valueInf;
			}
			}
	}
	else{
		//Pas de valeur minimal
		return 100000;
		}
}

LIST insertTrie(LIST listExistent, CELL * elementToAdd){

	 if(listExistent == NULL){
		 return elementToAdd;
		 }
	else{
		if(elementToAdd->valeur > listExistent->valeur ){
			//Pas a la bonne place 
			 listExistent -> suiv = insertTrie(listExistent->suiv, elementToAdd);
			 return listExistent;
			}
			else{
			 //Place to insert
				elementToAdd->suiv = listExistent;
				listExistent = elementToAdd;
				return listExistent;
			}
	}
}

LIST sortList(LIST listExistent){
		
	LIST resultatTrie = NULL;
	LIST temp = NULL;
	
	
	if(listExistent == NULL)
		return NULL;
	
	else{
			
		while(listExistent != NULL){
		     temp = 	listExistent;
			 listExistent = listExistent -> suiv;
			 temp->suiv = NULL;
			 resultatTrie =  insertTrie(resultatTrie, temp);
		}
		return resultatTrie;
	}
		
	
}

//a-> b->c 
//d at 1
//a-> d -> b ->c
CELL*  affectPosition(CELL * listExistent, int indexToAdd, int currentIndex, CELL * elementToAdd ){
	
	if(listExistent == NULL){
		//Nothing to add
		return NULL;
		}
	//We found the place to add
	if(currentIndex == indexToAdd ){
		elementToAdd-> suiv = listExistent;
		return elementToAdd;

	}else{
		listExistent-> suiv = affectPosition(listExistent-> suiv, indexToAdd, currentIndex + 1, elementTo);
		return listExistent;
	}
	
}


void printFirst(CELL * listExistent){// LIST listExistent
	if(listExistent != NULL){
			printf("First element: %d", listExistent->valeur);
	}else{
		printf("List is empty");
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

	printf("\nTaille list: %d\n", countVal(myList) );

	myList = addFirst(myList, createdCellDix);
	
	// Exo 5: 
	printf("\nPrint list:\n");
	
	printList(myList);
	printf("\nTaille list: %d\n", countVal(myList) );
	
	///Ajouter une nouvelle cellule au debut
	CELL * createdCellOnce = createCell(11);
	myList = addFirst(myList, createdCellOnce);
	
	printf("\nPrint list updated with 11:\n");
	printf("\nTaille list: %d\n", countVal(myList) );
	printList(myList);
	
	
	// Exo 4: 
		//Ajouter une nouvelle cellule a la fin
	printf("\nPrint list updated 9:\n");
	CELL * createdCellNeuf = createCell(9);
	myList = addLast(myList, createdCellNeuf);
	printList(myList);
	printf("\nTaille list (iterative version): %d\n", countValIter(myList) );
	
	int minval = infList(myList);
	printf("\nMin val: %d\n", minval);
	
	// Exo 8:
	printf("\nRemove first\n");
	myList = removeFirst(myList);
	printList(myList);
	
	
	//Insert Trie:
	LIST listTrie = NULL;
	
	CELL * createdCellTrois = createCell(3);
	CELL * createdCellDeux = createCell(2);
	CELL * createdCellCinq = createCell(5);
	
	listTrie = insertTrie(listTrie,createdCellTrois);
	listTrie = insertTrie(listTrie,createdCellDeux);
	listTrie = insertTrie(listTrie,createdCellCinq);
	
	printf("\nPrint trie: \n");
	printList(listTrie);
	
	
	//Exo 9:
	printf("\nBefore Sort\n");
	
	printList(myList);
	
	printf("\nAfter Sort\n");
	myList = sortList(myList);
	printList(myList);
	
	return 0;
}
