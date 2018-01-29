#include <stdio.h>

int square(int n){
	return n*n;
}

int cube(int n){
	return n*n*n;
}

int main(void){
	int (*fp)(int);
	fp = square;
	printf("square of %d: %d\n",10,fp(10)); 
	fp = cube;
	printf("cube of %d: %d\n",10,fp(10)); 
}
