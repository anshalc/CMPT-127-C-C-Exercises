//t3.c
#include<stdio.h>
#include<math.h>

int main(void)
{
	float value;
	scanf("%f", &value);
	printf("%d %d %d\n",(int)floor(value), (int)round(value), (int)ceil(value));
}