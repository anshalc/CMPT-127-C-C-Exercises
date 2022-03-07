//t7.c
#include<stdio.h>
int main()
{
	int num;
	for (int i=0;;i++)
	{
		int result=scanf("%d", &num);
		if(result!=EOF)
		{
			for(int j=0;j<num;j++)
				printf("#");
		}
		else
			break;
		printf("\n");
	}
}