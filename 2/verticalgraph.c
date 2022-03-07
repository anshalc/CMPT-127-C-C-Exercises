#include <stdio.h>
#include <math.h>

int main( void )

{
	int i=0,j=0,count=0,max=0;
    int k;  
    int a[80]={-2};
    while (scanf("%d", &k)!=-1){
      a[i]=k;
      i=i+1;
      count=count+1;
      if (i>=80){
        break;
      }
    }   
	
	i=0;
	for (i=0;i<=count-1;i++){
		if (a[i]>max)
		{
			max = a[i];
		}
	}
	i=0;
	for (i=0;i<=count-1;i++){
		a[i]=max-a[i];		

	}
	i=0;
	for (i=0;i<=max-1;i++)	{ 		
 		for (j=0;j<=count-1;j++){
 			if (a[j]>0){
	 			printf(" ");
	 		}
	 		else if (a[j]<=0){
	 			printf("#");
	 		}	 		
 		}
 		printf("\n");
 		j=0;
 		for (j=0;j<=count-1;j++)
		{
			a[j]=a[j]-1;
		}
	}
	return 0;
}