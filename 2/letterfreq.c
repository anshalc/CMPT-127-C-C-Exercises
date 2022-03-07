#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main( )
{
    int i,sum=0;
    float freq;
    char letter;char c;
    char alp [26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int count[26]={0};
    while( (c=getchar())!= EOF ) 
    {    
    	if (c=='a' || c=='A')
        {
            count[0]+=1;
        }
        else if (c=='b' || c=='B')
        {
            count[1]+=1;
        }
        else if (c=='c' || c=='C')
        {
            count[2]+=1;
        }
        else if (c=='d' || c=='D')
        {
            count[3]+=1;
        }
        else if (c=='e' || c=='E')
        {
            count[4]+=1;
        }
        else if (c=='f' || c=='F')
        {
            count[5]+=1;
        }
        else if (c=='g' || c=='G')
        {
            count[6]+=1;
        }
        else if (c=='h' || c=='H')
        {
            count[7]+=1;
        }
        else if (c=='i' || c=='I')
        {
            count[8]+=1;
        }
        else if (c=='j' || c=='J')
        {
            count[9]+=1;
        }
        else if (c=='k' || c=='K')
        {
            count[10]+=1;
        }
        else if (c=='l' || c=='L')
        {
            count[11]+=1;
        }
        else if (c=='m' || c=='M')
        {
            count[12]+=1;
        }
        else if (c=='n' || c=='N')
        {
            count[13]+=1;
        }
        else if (c=='o' || c=='O')
        {
            count[14]+=1;
        }
        else if (c=='p' || c=='P')
        {
            count[15]+=1;
        }
        else if (c=='q' || c=='Q')
        {
            count[16]+=1;
        }
        else if (c=='r' || c=='R')
        {
            count[17]+=1;
        }
        else if (c=='s' || c=='S')
        {
            count[18]+=1;
        }
        else if (c=='t' || c=='T')
        {
            count[19]+=1;
        }
        else if (c=='u' || c=='U')
        {
            count[20]+=+1;
        }
        else if (c=='v' || c=='V')
        {
            count[21]+=1;
        }
        else if (c=='w' || c=='W')
        {
            count[22]+=1;
        }
        else if (c=='x' || c=='X')
        {
            count[23]+=1;
        }
        else if (c=='y' || c=='Y')
        {
            count[24]+=1;
        }
        else if (c=='z' || c=='Z')
        {
            count[25]+=1;
        }
        
	}
	
        
    
    for (i=0;i<=25;i++) 
    {
        sum=sum+count[i];
    }
    
    for (i=0;i<=25;i++) 
    {
        letter=alp[i];
        freq=count[i]/(float)sum;
        if (count[i]!=0)
        {
            printf( "%c %.4f\n", letter, freq); 
        }
        
    }
    return 0;
}