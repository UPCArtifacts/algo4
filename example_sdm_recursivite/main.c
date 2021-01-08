#include <stdio.h>



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
	int sizeArray, * p;
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
	
	printf("Checking initialization\n");
	for(int i = 0; i < sizeArray; i++ ){
		printf("Value at place i= %d is : %d\n", i , *(p+i));
		
	}
	
	//Reset values
	resultMax = 0;
	resultMin = 0;
	resultMoy = 0.0;
	
	minMaxMoyenne(p,  sizeArray, &resultMin,  &resultMax, &resultMoy);
	printf("Min %d Max %d Moy %f", resultMin, resultMax, resultMoy);
	
	printf("\nEnd");
	return 0;
}
