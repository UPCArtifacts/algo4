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

void printListFilterAnne(LIST listToPrint, int annee){
//recursive
  if(listToPrint != NULL){
	  if (listToPrint -> annee == annee){
				printf("date: %d / %d / %d\n", listToPrint->jour, listToPrint->mois, listToPrint -> annee);
	     }
	   printListFilterAnne(listToPrint->suiv, annee);
	  }	

}


int nbValMoisAnnee(LIST currentElement, int m, int a){
   
  if(currentElement != NULL){
	  
	  int resultsSuivant = nbValMoisAnnee(currentElement->suiv, m, a);
	  if(currentElement-> mois == m && currentElement -> annee == a){
		     return 1 + resultsSuivant;
	  }else{
		    return resultsSuivant;
		  }
	  
	}else{
		return 0;
		}	

}

LIST supprimeAnnee(LIST listToAnalyze, int anneeToRemove){
	
	if(listToAnalyze == NULL){
		return NULL;
		}
	else{
		if (listToAnalyze -> annee == anneeToRemove){
			 /// je vais retourner l'address de suivant, parce que    listToAnalyze doit etre supprimé
			return supprimeAnnee(listToAnalyze-> suiv, anneeToRemove);
			}
		else{
			// je vais retourner l adress de listToAnalyze.
			listToAnalyze ->  suiv = supprimeAnnee(listToAnalyze-> suiv, anneeToRemove);
			return listToAnalyze ;
			}
		}
	
}


int estAvant (LIST d1, LIST d2){
   // 1 d1 < d2
   
   if( d1-> annee < d2 -> annee){
			return 1;
   } else 
	   if( d1-> annee > d2 -> annee){
	   return 0;
	   // idem annees:
	   }else 
		   if( d1 -> mois < d2 -> mois){
		   return 1;
		   } 
		   else {
				   if( d1 -> mois > d2 -> mois){
					   return 0;
					   }
					   else{
						   // TODO: compared jours.
						   }
			   }	
}

LIST supprimeDerniere(LIST listDates){
	
		if( listDates != NULL){
		   //printf("date: %d / %d / %d\n", listDates->jour, listDates->mois, listDates -> annee);
		
			if( listDates -> suiv == NULL){
					//C est le dernier
				//printf("Found last\n");	
				free(listDates);
				return NULL;
				}
				else{
					listDates-> suiv = supprimeDerniere(listDates -> suiv);
					return listDates;
					}
			
			}
			else{
				return NULL;
			}
	

	
}

LIST insertTrie(LIST listExistent, LIST elementToAdd){

	 if(listExistent == NULL){
		 return elementToAdd;
		 }
	else{
		if(estAvant(elementToAdd, listExistent ) != 0 ){
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


LIST trier(LIST listExistent){
		
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

int main(int argc, char **argv)
{
	printf("TD 2: Exo 2\n");
	
	DATE* dateToday = createDate(15, 1, 2021);
	DATE* dateHier= createDate(14, 1, 2021);
	DATE* datePast= createDate(14, 1, 1986);
	DATE* datePastPast= createDate(14, 1, 1985);
	
	printf("date: %d / %d / %d", dateToday->jour, dateToday->mois, dateToday -> annee);
	LIST allDate;
	
	allDate = addFirst(allDate, dateToday);
	allDate = addFirst(allDate, dateHier);
	allDate = addFirst(allDate, datePast);
	allDate = addFirst(allDate, datePastPast);
	printf("\n created list: \n");
	printList(allDate);
	
	// Exo 6 
	int moisToQuery = 1;
	int anneeToQuery = 2021;
	int nrElements = nbValMoisAnnee(allDate ,moisToQuery, anneeToQuery );
	printf("\nnr of dates %d \n", nrElements);
	
	printf("Print by year: \n");
	printListFilterAnne(allDate, 1986);
	

	printf("\nPrint by year: \n");
	printListFilterAnne(allDate, 2021);
	
	// Exo 8: 
	int resultComparison = estAvant (dateToday, datePast);
	
	//Exo 9: 
	//printf("\nRemove last\n");
	//allDate = supprimeDerniere(allDate);
	//printf("\nPrint list \n");
	//printList(allDate);
	//Exo 10:
	int yearToRemove  = 1986;
	printf("\nRemove one year %d \n", yearToRemove);
	allDate = supprimeAnnee(allDate, yearToRemove);
	printList(allDate);
	
	//Exo 11
	//TODO: test.
	
	return 0;
}


