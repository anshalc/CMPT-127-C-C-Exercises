#include<stdio.h>
#include<math.h>

int main()
{
	int x, y, z, left, right;
	scanf("%d %d %d", &x, &y, &z);
	for(int i=z-1;i>=0;i--)
	{
		left=floor(i*(x/(2.0*z)));
		right=ceil((x-1)+ -i*(x/(2.0*z)));
		for(int j=0;j<left;j++)
		{
			printf(" ");
		}
		for(int k=left;k<=right;k++)
		{
			if(k==left||k==right||i==z-1||i==0)
				printf("#");
			else
				printf(".");
		}
		printf("\n");
	}
}