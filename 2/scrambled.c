int scrambled( unsigned int arr1[], unsigned int arr2[], unsigned int len );
int scrambled( unsigned int arr1[], unsigned int arr2[], unsigned int len ){
	int new[100]={0},i,j,val; //flag[100] array is used for differentiating same elements getting repeated
	
	if(len==0){
	return 1;
	}

	else{
	for(i=0;i<len;i++){
		
		val=0; //value for individual iteration whether the element is found or not
		
		for(j=0;j<len;j++){
			if(arr1[i]==arr2[j] && new[j]==0){
			new[j]=1;
			val=1;
			break;
		}
	}
	if(val==0)
		return 0;
	}//end of for loop.
}//end of else statement.
		return 1;
}