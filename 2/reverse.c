//reverse.c
void reverse(int arr[], unsigned int len)
{
	//starts here.

	if(len>1) //if len = 1 or len = 0 the array doesn't need any modifications.
	{
		int i=0;
		while(i<len/2) // swapping the elements so that the elemts at last appears first.
		{
			int temp = arr[i];
			arr[i] = arr[len-i-1];
			arr[len-i-1] = temp;
			i++;
		}
	}
	//ends here.
}
