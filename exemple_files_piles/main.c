#include <stdio.h>

///
#define MAX 20
#define VALUE_NULL -1

typedef float TAB[MAX];

typedef  struct {
	TAB values;	// pile d'éléments
	int card; // nombre d'éléments dans la pile
} PILE;

//p ; p doit etre vide en sortie de cette fonction.
void init(PILE *p){
   
	p->card = 0;
	for (int i =0; i< MAX; i++){
			p->values[i] = VALUE_NULL;
		}
	
}
//renvoie 1 si p ne contient rien, 0 sinon
int estVide(PILE p){
	
	if(p.card == 0){
		return 1;
	}
	else{
			return 0;
			}
	
}

//renvoie 1 si p ne contient rien, 0 sinon
int estVidePointer(PILE * p){
	//I can use -> because it's a pointer to one struct
	if(p->card == 0){
		return 1;
	}
	else{
			return 0;
			}
	
}
//// ajoute f dans p si f non pleine, renvoie 1 si OK, 0 sinon
int empiler(PILE * p, float valueToAdd){
	
	if (estPleine(*p)) {
		return 0;
	}
else{ 
	p-> values[p->card]= valueToAdd ;
     p->card=p->card +1;
  return 1;
}
	
}
// renvoie 1 si on ne peut plus rien ajouter dans p, 0 sinon
int estPleine(PILE p){
		if(p.card == MAX){
		return 1;
	}
	else{
			return 0;
	}
}

//// depile le sommet de p
// et le met dans le float pointe par pf si p non vide,
// renvoie 1 si OK, 0 sinon

int depiler(PILE *p, float * fp){
	printf("Removing\n");
	if (estVide(*p))
		return 0;
	else{
		
	//printf("Removing  %d\n", p->card);
	*fp = p -> values[p -> card-1];
	p-> values[p->card-1]= VALUE_NULL;
	p-> card = p -> card - 1;
	return 1;
}
	
}
// / affiche la valeur de sommet de p sans la depiler si p non vide,
// " pile vide" sinon
void afficheSommet(PILE p){
	if (!estVide(p)){
		printf("Somment: %f \n", p.values[p.card-1]);
		}
}


int main(int argc, char **argv)
{
	printf("TD 3 Exo 2 Files et piles: \n");
	
	PILE myPile;
	myPile.card;
	myPile.values;
	
	init(&myPile);
	
	//Dont use -> because myPile is not a pointer
	//myPile is a struct so for this reason we use . to access to its values
	printf("Size of pile: %d \n", myPile.card);
	
	int isEmpty = estVide(myPile);
	
	printf("is Empty? %d\n", isEmpty);
	
	int isFull = estPleine(myPile);
	
	printf("is Full? %d\n", isFull);
	
	float firstValue = 0.5;
	//Put a value 
	printf("\nAdding a value: \n");
	int firstIn = empiler(&myPile, firstValue);
	
	afficheSommet(myPile);
	
	isEmpty = estVide(myPile);
	
	printf("is Empty? %d\n", isEmpty);
	
	float valueRemoved = 0.0;
	printf("\nRemoving  a value: \n");
	
	int resultRemovement = depiler(&myPile, &valueRemoved);
	printf("\nRemoved value: %f \n",valueRemoved);
	
	
	isEmpty = estVide(myPile);
	
    printf("is Empty? %d\n", isEmpty);
	
	
	
	return 0;
	
	
}
