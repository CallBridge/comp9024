#include <stdio.h>
#include <stdlib.h>

void printMark(int x){
	printf("Marks: %d\n", x);
}

void printResult(int x){
	if(x>50){
		printf("Unfortunately, Failed.\n");
	}else{
		printf("Congratulations, Passed.\n");
	}
}

void resultSheet(int *a, int size, void (*fp) (int)){
	for(int i=0;i<size;i++){
		fp(a[i]);
	}
}

int main(int argc, char *argv[]){
	void (*fp)(int);
	int a[5] = {1, 2, 3, 4, 5};
	

	fp = printMark;
	resultSheet(a, 5, fp);
	printf("-`-`-`-`-`-`-`-`-`-`-`-`-\n");
	fp = printResult;
	resultSheet(a, 5, fp);

	return EXIT_SUCCESS;
}
