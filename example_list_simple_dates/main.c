#include <stdio.h>

struct _date{
	int jour;
	int mois;
	int annee;
	struct _date * suiv;
};

// Redefinition of type
typedef struct _date DATE;
typedef DATE * LIST;

DATE* createDate(int jour, int mois, int annee){
	
	DATE* newDate;
	newDate = (DATE*) malloc(sizeof(DATE));
	//Affectation -init-
	newDate->jour = jour;
	newDate->mois = mois;
	newDate->annee = annee;
	newDate->suiv = NULL;
	// return l addresse òu nous avons stocké la nouvelle cellule.
	return newDate;
}


LIST addFirst(LIST listExistent, DATE * elementToAdd){
	
	elementToAdd->suiv = listExistent;
	listExistent = elementToAdd;
	return listExistent;
	
}

void printList(LIST listToPrint){
//recursive
  if(listToPrint != NULL){
	  printf("date: %d / %d / %d\n", listToPrint->jour, listToPrint->mois, listToPrint -> annee);
	   printList(listToPrint->suiv);
	  }	

}

int main(int argc, char **argv)
{
	printf("TD 2: Exo 2\n");
	
	DATE* dateToday = createDate(15, 1, 2021);
	DATE* dateHier= createDate(14, 1, 2021);
	
	printf("date: %d / %d / %d", dateToday->jour, dateToday->mois, dateToday -> annee);
	LIST allDate;
	
	allDate = addFirst(allDate, dateToday);
	allDate = addFirst(allDate, dateHier);
	printf("\n created list: \n");
	printList(allDate);
	return 0;
}
