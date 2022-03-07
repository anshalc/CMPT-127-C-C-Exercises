// identical.c
int identical(int arr1[], int arr2[], unsigned int len)
{
	if(len == 0)
		return 1;
	int count = 0;
	for(int i=0;i<len;i++)
	{
		if(arr1[i] == arr2[i])
			count++;
	}
	if(count == len)
		return 1;
	return 0;
}