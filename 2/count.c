//counts.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int word = 1;
	unsigned long int charcount = 0;
	unsigned long int wordcount = 0;
	unsigned long int linecount = 0;
	char c;
	while((c = getchar())!= EOF)
	{
		charcount++;
		if(c == '\n')
		{
			linecount++;
			word = 1;
		}
		else if((c>='a' && c<='z')||(c>='A' && c<='Z')||c == '\'')
		{
			if(word ==1)
			{
				wordcount++;
				word = 0;
			}
		}
		else
		{
			word = 1;

		}
	}
		printf("%lu %lu %lu\n", charcount, wordcount, linecount);
		return 0;

}



