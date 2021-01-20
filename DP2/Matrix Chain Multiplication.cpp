#include <climits>
int matrixChainMultiplication(int* arr, int s,int e,int **memo){
    if(s==e || s==e-1){
        return 0;
    }
    if(memo[s][e]!=-1){
        return memo[s][e];
    }
    int small=INT_MAX;
    for(int i=s+1;i<e;i++){
        small=min(small,matrixChainMultiplication(arr,s,i,memo)+matrixChainMultiplication(arr,i,e,memo)+arr[s]*arr[i]*arr[e]);
    }
    
    memo[s][e]=small;
    
    return memo[s][e];
}
int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    int **memo;
    int n1=n+1;
    int m=n1;
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
    return matrixChainMultiplication(arr,0,n,memo);
}