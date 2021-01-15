#include <stdio.h>

typedef struct ddd{ int val; struct ddd * suiv;} 
CE;

typedef struct _cell{
	int valeur;
	struct _cell * suiv;
} CELL;

typedef CELL * LIST;

LIST addFirst(LIST listExistent, CELL * elementToAdd){
	
	elementToAdd->suiv = listExistent;
	listExistent = elementToAdd;
	return listExistent;
	
}

CELL* createCell(int valueDeLaCellule){
	
	CELL* newCell;
	newCell = (CELL*) malloc(sizeof(CELL));
	//Affectation -init-
	newCell->valeur = valueDeLaCellule;
	newCell->suiv = NULL;
	// return l addresse òu nous avons stocké la nouvelle cellule.
	return newCell;
}
void printList(LIST listToPrint){
//recursive
  if(listToPrint != NULL){
	   printf("v: %d, ", listToPrint->valeur);
	   printList(listToPrint->suiv);
	  }	

}

void printListAdress(LIST listToPrint){
//recursive
  if(listToPrint != NULL){
	   printf("adr: %p \n", listToPrint);
	   printListAdress(listToPrint->suiv);
	  }	

}




int main(int argc, char **argv)
{
	printf("Quizz Cours 3\n");
	
	int tabTest[] ={10,22, 13, 14}; 
	// Tableau et memoire
	int *p;
	p = tabTest;
	printf("\n");
	printf("\ntaille d Interger %d\n", sizeof(int));
	for (int i=0; i < 4; i++){
			printf("Adress of element nr %d is: %p \n", i, p);
			//Avance le pointer
			p++;
	}
	//printf("Value at possion 3: %d", tabTest[2]);
	
	/// Liste et memoire
	printf("\nExperiment List and memory: \n");
	CELL * createdCellTrois = createCell(3);
	//Ici on demande de la memoire que nous n outilisons pas dans la liste
	CELL* demandeAuxilier = (CELL*) malloc(sizeof(CELL));
	
	CELL * createdCellDeux = createCell(2);
	CELL * createdCellCinq = createCell(5);
	CELL * createdCellDix = createCell(10);
	LIST myList = NULL;
	
	
	myList = addFirst(myList,createdCellTrois);
	myList = addFirst(myList,createdCellDeux);
	myList = addFirst(myList,createdCellCinq);
	myList = addFirst(myList,createdCellDix);
	
	//Print the address of each element from the list
	printListAdress(myList);
	printf("\nAdress auxiliar %p \n",demandeAuxilier );
	
	
	//Nr 4:
	//Code exemple:
	LIST p1 = NULL;
	LIST s1 = NULL;
	//TODO: INIT p and s 
	while(p1-> suiv != NULL){ 
		p1 = p1->suiv;
		}  
	p1-> suiv = s1;   
	
	
	return 0;
}
