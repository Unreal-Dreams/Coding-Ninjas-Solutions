int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
    
    if(n==0 && m==0){
        return 0;
    }
	//Write your code here
    int **dp;
	dp = new int *[n];
	for (int i = 0; i < n; i++)
	{
		dp[i] = new int[m];
	}
    
    for(int i=0;i<n;i++){
        if(arr[i][0]==0){
        	dp[i][0]=1;
        }else{
            dp[i][0]=0;
        }
    }
    
    for(int i=0;i<m;i++){
        if(arr[0][i]==0){
        	dp[0][i]=1;
        }else{
            dp[0][i]=0;
        }
    }
    int max=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1){
                dp[i][j]=0;
                continue;
            }
            dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            if(dp[i][j]>max){
                max=dp[i][j];
            }
        }
    }
    
    return max;
    
}