//t5.c
#include<stdio.h>
#include<math.h>

int main(void)
{
	float value;
	for(int i=0;;i++)
	{
		int result=scanf("%f", &value);
		if(value==' ')
		{
			continue;
		}
		if(result!=EOF)
		{
			printf("%d %d %d\n",(int)floor(value), (int)round(value), (int)ceil(value));
		}
		else
		{
			printf("Done.\n");
			break;
		}
	}
}