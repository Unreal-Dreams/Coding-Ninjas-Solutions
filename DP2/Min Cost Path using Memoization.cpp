#include <bits/stdc++.h>
int minCostPathHelper(int **input,int m, int n,int row,int col,int **arr){
	   
    if(row>=m || col>=n){
        return INT_MAX;
    }
    
     
	if(m-row==1 && n-col==1){
		return input[row][col];
    }
   
    if(arr[row][col]!=-1){
        return arr[row][col];
    }
    int path1=minCostPathHelper(input,m,n,row,col+1,arr);
    int path2=minCostPathHelper(input,m,n,row+1,col,arr);
    int path3=minCostPathHelper(input,m,n,row+1,col+1,arr);
	int min1n2=min(path1,path2);
    
    arr[row][col]=input[row][col]+min(min1n2,path3);
    return arr[row][col];
    
}

int minCostPath(int **input, int m, int n)
{
	//Write your code here
    
    int **arr;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j]=-1;
		}
	}
    
    return minCostPathHelper(input,m,n,0,0,arr);
}