class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int **arr;
        int m=text1.size();
        int n=text2.size();
        arr = new int *[m+1];
	    for (int i = 0; i <= m; i++){
		    arr[i] = new int[n+1];
	    }
        //Initialize First Row and Column by zero as if length of any string is zero there is no common subsequence
         
        //Col
        for (int j = 0; j <=n; j++){
			arr[0][j]=0;
		}
        //Row
        for (int j = 1; j <= m; j++){
			arr[j][0]=0;
		}
         
        for (int i = 1; i <=m; i++){
		    for (int j = 1; j <= n; j++){
			    if(text1[m-i]==text2[n-j]){
                    arr[i][j]=arr[i-1][j-1]+1;
                }else{
                    arr[i][j]=max(max(arr[i-1][j-1],arr[i-1][j]),arr[i][j-1]);
                }
		    }
        }
        
        return arr[m][n];
    }
};