#include <bits/stdc++.h>
int minCostPathHelper(int **input,int m, int n,int row,int col){
	   
    if(row>=m || col>=n){
        return INT_MAX;
    }
    
     
	if(m-row==1 && n-col==1){
		return input[row][col];
    }
   
    
    int path1=minCostPathHelper(input,m,n,row,col+1);
    int path2=minCostPathHelper(input,m,n,row+1,col);
    int path3=minCostPathHelper(input,m,n,row+1,col+1);
	int min1n2=min(path1,path2);
    
    return input[row][col]+min(min1n2,path3);
    
}

int minCostPath(int **input, int m, int n)
{
	//Write your code here
    return minCostPathHelper(input,m,n,0,0);
}