//contains.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[])
{
	char* input1 = argv[1];
	char* input2 = argv[2];
	char*new = strstr(input1, input2);
	if(new!=0)
		printf("true\n");
	else
		printf("false\n");
}