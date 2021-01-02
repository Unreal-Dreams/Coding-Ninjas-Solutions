int minCostPath(int **input, int m, int n, int i, int j,int **arr) {
	// Base case
	if(i == m- 1 && j == n- 1) {
		return input[i][j];
	}

	if(i >= m || j >= n) {
		return INT_MAX;
	}
    if(arr[i][j]!=-1){
        return arr[i][j];
    }

	// Recursive calls
	int x = minCostPath(input, m, n, i, j+1,arr);
	int y = minCostPath(input, m, n, i+1, j+1,arr);
	int z = minCostPath(input, m, n, i+1, j,arr);

	// Small Calculation
	int ans = min(x, min(y, z)) + input[i][j];
    arr[i][j]=ans;
	return arr[i][j];
}

int minCostPath(int **input, int m, int n) {
    int **ans= new int*[m];
    for(int i=0;i<m;i++){
        ans[i]=new int[n];
        for(int j=0;j<n;j++){
            ans[i][j]=-1;
        }
        
    }
	return minCostPath(input, m, n, 0, 0,ans);
}