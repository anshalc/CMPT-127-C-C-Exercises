//t4.c
#include<stdio.h>
#include<math.h>

int main(void)
{
	double value;
	int a =scanf("%lf", &value);
	if(a)
		printf("%d %d %d\n",(int)floor(value), (int)round(value), (int)ceil(value));
	else
		printf("scanf error: (%d)\n", a);
}