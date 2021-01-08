#include <stdio.h>
#include <stdlib.h>

//remplit monTab de n valeurs aleatoires

void  initRandomTab(int *monTab, int n){
	//Seed
	srand(4);
	for(int i = 0; i < n; i++ ){
			monTab[i] = rand() % 10;
		}
} 

 //renvoie 1 si val dans monTab, 0 sinon
int rechercheIterative(int val, int *monTab, int n){
  
	for(int i = 0; i<n;i++){
		//if(monTab[i] == val){
		if(*(monTab + i) == val){
			return 1;
			}
	}
	// fin
	return 0;
	
}


 //renvoie 1 si val dans monTab, 0 sinon
int rechercheRecursive(int val, int *monTab, int n){
  
	if( n >= 0 ){
		//if(monTab[i] == val){
		if(*(monTab + n) == val){
			return 1;
		}
		else{
				return rechercheRecursive(val, monTab, n - 1);
			}
	}else{
	// stop condition
	   return 0;
	}
	
}


int rechercheIndexRecursive(int *monTab, int i, int sizeOfArray){
  
	if( i < sizeOfArray){
		if(*(monTab + i) > 50){
			return i;
		}
		else{
				return rechercheRecursive(monTab, i+1, sizeOfArray);
			}
	}else{
	// stop condition
	   return 0;
	}
	
}



void  initRandomTabPointer(int *pointerToTab, int n){
	srand(0);
	for(int i = 0; i < n; i++ ){
			*pointerToTab = rand() % 10;
			 pointerToTab = pointerToTab + 1;
			  
		}
} 


void minMaxMoyenne(
    // Parametre d'Entrée
	int n[], int sizeOfArray,
	// Parametre d'Entrée, et a la fois, sorti
	int *pmin, int *pmax, float *pmoy
){
	
	*pmin = n[0];
    *pmax = n[0]; 
	 
	 int sum = 0;
	 
	for(int i= 0; i< sizeOfArray; i++ ){
		
		if(*pmin > n[i]) {
			*pmin = n[i];
			}
		if(*pmax < n[i]) {
			*pmax = n[i];
		}
		sum = sum + n[i];
	}
	
	*pmoy = sum / sizeOfArray; 
}

// Exo 5 : version iterative:
void printTable(int *p, int sizeArray){
		for(int i = 0; i < sizeArray; i++ ){
		   printf("Value at place i= %d is : %d\n", i , *(p+i));
		
	}
}

// Exo 5 : version recursive:
void printTableRecursive(int *p, int currentElementIndex){
		if(currentElementIndex >= 0){
		   printTableRecursive(p, currentElementIndex - 1 );
		   printf("'Recursive : Value at place i= %d is : %d\n", currentElementIndex , *(p+currentElementIndex));
		}
}

void exo3(){
	int sizeArray, * p;
	int resultMax = 0;
	int resultMin = 0;
	float resultMoy = 0.0;

	printf("\nWrite the size of the array:\n");
    scanf("%d", &sizeArray);
	printf("Value written %d",sizeArray );
    //P has the address to the memory where we have sizeArray X sizeof(4) bytes
	p = (int*)malloc(sizeArray*sizeof(int));
	
	//Auxiliary pointer
	int *pi ;
	//Copy of addresses
	pi = p;
	
	//Init du tableau dynamique
	for(int i = 0; i < sizeArray; i++ ){
		printf("\nWrite  value at place i= %d\n",i);
		scanf("%d", pi);
		pi++;
	}
	
	
	//Reset values
	resultMax = 0;
	resultMin = 0;
	resultMoy = 0.0;
	
	minMaxMoyenne(p,  sizeArray, &resultMin,  &resultMax, &resultMoy);
	printf("Min %d Max %d Moy %f", resultMin, resultMax, resultMoy);
	
}

int main(int argc, char **argv)
{

	printf("TD 1\n");
	// Exo 1 et 2
	//Tableau statique!!
	int n[]  = {5,6,7,8,3}; 

	//for (int i=0 ; i< N ; i++) 
	//	  n[i]=i+1 ; 
	
	int resultMax = 0;
	int resultMin = 0;
	float resultMoy = 0.0;
	
	//Ap
	minMaxMoyenne(n, 5, &resultMin,  &resultMax, &resultMoy);
	
	printf("Min %d Max %d Moy %f", resultMin, resultMax, resultMoy);
	
	// Exo 3:
	//exo3();
	
	
	//Exo 4:
	int sizeArray;
	printf("\nWrite the size of the array:\n");
	scanf("%d", &sizeArray);
	int * prandom;
	//Demane de memoire
	prandom = (int*)malloc(sizeArray*sizeof(int));
	//Initialisation
	//initRandomTab(prandom, sizeArray);
	initRandomTabPointer(prandom, sizeArray);
	
	//
	printf("Iterative Print");
	printTable(prandom, sizeArray);
	//
	printf("Recursive Print");
	printTableRecursive(prandom, sizeArray -1 );
	
	//Reset values
	resultMax = 0;
	resultMin = 0;
	resultMoy = 0.0;
	
	minMaxMoyenne(prandom,  sizeArray, &resultMin,  &resultMax, &resultMoy);
	printf("Min %d Max %d Moy %f", resultMin, resultMax, resultMoy);
	
	//Exo 6 
	
	int valeur = 8;
	int found = rechercheIterative(valeur, prandom, sizeArray);
	
	printf("\n\nis value %d on array?: %d \n", valeur, found);
	valeur = 5;
	
	found = rechercheIterative(valeur, prandom, sizeArray);
	
	printf("\n\nis value %d on array?: %d \n", valeur, found);
	
	valeur = 3;
	found = rechercheIterative(valeur, prandom, sizeArray);
	
	printf("\n\nis value %d on array?: %d \n", valeur, found);
	
	//Now with recursive
	printf("\nRecursive\n");
	valeur = 8;
	found = rechercheRecursive(valeur, prandom, sizeArray-1);
	
	printf("\n\nis value %d on array?: %d \n", valeur, found);
	valeur = 5;
	
	found = rechercheRecursive(valeur, prandom, sizeArray-1);
	
	printf("\n\nis value %d on array?: %d \n", valeur, found);
	
	valeur = 3;
	found = rechercheRecursive(valeur, prandom, sizeArray-1);
	
	printf("\n\nis value %d on array?: %d \n", valeur, found);
	
	print("\n---");
	// Exo 7
	printf("Last exo 7:");
	//Tableau statique!!
	int tableauStat[]  = {5,6,57,8,53}; 
	sizeArray = 5; // TODO: improve, compute the size with a function.
	int indexFirst = rechercheIndexRecursive(tableauStat, 0, sizeArray );
	
	printf("\nindex? %d \n", indexFirst);
	printf("\nEnd");
	return 0;
}
