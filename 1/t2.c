//t2.c
#include<stdio.h>
#include<limits.h>

int main()
{
	printf("%lu ", CHAR_BIT*sizeof(char));
	printf("%lu ", CHAR_BIT*sizeof(unsigned char));
	printf("%lu ", CHAR_BIT*sizeof(int));
	printf("%lu ", CHAR_BIT*sizeof(unsigned int));
	printf("%lu ", CHAR_BIT*sizeof(long));
	printf("%lu ", CHAR_BIT*sizeof(unsigned long));
	printf("%lu ", CHAR_BIT*sizeof(float));
	printf("%lu ", CHAR_BIT*sizeof(double));
	printf("%lu\n", CHAR_BIT*sizeof(long double));

}