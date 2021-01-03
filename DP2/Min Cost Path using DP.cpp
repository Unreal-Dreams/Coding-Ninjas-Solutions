 

int minCostPath(int **input, int m, int n){
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
    
    arr[m-1][n-1]=input[m-1][n-1];
    for(int i=m-1;i>=0;i--){
		for(int j=n-1;j>=0;j--){
            if(i==m-1 && j==n-1){
                continue;
            }
            
            int path1,path2,path3;
            if(i+1>=m){
				path1=INT_MAX;
            }else{
				path1=arr[i+1][j];
            }
            if(j+1>=n){
                path2=INT_MAX;
            }else{
                path2=arr[i][j+1];
            }
            if(i+1>=m || j+1>=n){
                path3=INT_MAX;
            }else{
                path3=arr[i+1][j+1];
            }
            
            arr[i][j]=input[i][j]+min(min(path1,path2),path3);
            
            
        }
    }
    
		// for (int i = 0; i < n; i++){
		// 	for (int j = 0; j < m; j++)
		// 	{
		// 		cout<<arr[i][j]<<" ";
		// 	}
		// cout<<endl;
		// }
    
    return arr[0][0];
}