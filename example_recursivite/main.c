#include <stdio.h>

#define N 5
typedef int TabEntiers[N];


int functionRecursive(int * t, int m, int i) { 
	if (i >= 0){
		if (t[i] >m){
		  return functionRecursive(t, t[i], i-1);
		}else 
			return f(t, m, i-1);
	}else {
			return m;
}
	}

int main(int argc, char **argv)
{
	printf("Example recursivite: \n");
	TabEntiers monTab={8, 2, 3, 7, 5};
printf("%d \n", functionRecursive(monTab, monTab[N−1], N−1));
	return 0;
}
