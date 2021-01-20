int countWaysToMakeChangeHelper(int arr[], int n, int value,int ** memo){
	//Write your code here
    
    if(n==0 ){
        return 0;
    }
    if(value==0){
        return 1;
    }
    if(memo[n][value]!=-1){
        return memo[n][value];
    }
    if(arr[n-1]>value){
        memo[n][value] =countWaysToMakeChangeHelper(arr,n-1,value,memo);
        return memo[n][value];
    }
    
    memo[n][value]=countWaysToMakeChangeHelper(arr,n-1,value,memo)+countWaysToMakeChangeHelper(arr,n,value-arr[n-1],memo);
    return memo[n][value];
}

int countWaysToMakeChange(int arr[], int n, int value){
    int **memo;
    int n1=n+1;
    int m=value+1;
	memo = new int *[n1];
	for (int i = 0; i < n1; i++)
	{
		memo[i] = new int[m];
	}
    
    for(int i=0;i<n1;i++){
        for(int j=0;j<m;j++){
            memo[i][j]=-1;
        }
    }
    return countWaysToMakeChangeHelper(arr,n,value,memo);
}