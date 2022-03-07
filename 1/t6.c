//t6.c
#include<stdio.h>
#include<math.h>
int main(){
	int a;
	float num;
	float totalValues=0,sum=0,max=-100000,min=100000,mean;

	while((a=scanf("%f",&num))!=EOF)
	{
		if(a==EOF)
		{
			break;
		}
		else
		{
			if(num>max)
			{
				max=num;
			}
			if(num<min)
			{
				min=num;
			}
			sum+=num;
			totalValues++;
		}
	}
	mean=sum/totalValues;
	printf("%.2f %.2f %.2f\n",min,max,mean);
	return 0;
}