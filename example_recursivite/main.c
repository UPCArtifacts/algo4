#include <stdio.h>

#define N 5
typedef int TabEntiers[N];

//The function returns the number of elements (greater than x) 
//from the table that are at the right of the current position
int nrValuesGreater(TabEntiers myTab, int x, int currentPosition){

	if(currentPosition  >= 0){
		
	if(myTab[currentPosition] > x){
			return 1 + nrValuesGreater(myTab, x, currentPosition - 1);
		}
		else{
			return 0 + nrValuesGreater(myTab, x, currentPosition - 1);
			}
		}
	else{
		return 0; 
		}
	
}


int main(int argc, char **argv)
{
	printf("Example recursivite: \n");
	TabEntiers monTab={8, 2, 3, 7, 5};
	int x = 7;
	printf("%d \n", nrValuesGreater(monTab, x, N- 1));
	return 0;
}
