class Solution {
public:
    
    int longestCommonSubsequenceH(string text1, string text2,int**arr) {
        if(text1.size()==0 || text2.size()==0){
            return 0;
        }
        int row=text1.size()-1;
        int col=text2.size()-1;
        
        if(arr[row][col]!=-1){
            return arr[row][col];
        }
        if(text1[0]==text2[0]){
            arr[row][col]= 1+longestCommonSubsequenceH(text1.substr(1),text2.substr(1),arr);
            return arr[row][col];
        }else{
            int opt1=longestCommonSubsequenceH(text1.substr(1),text2,arr);
            int opt2=longestCommonSubsequenceH(text1,text2.substr(1),arr);
            int opt3=longestCommonSubsequenceH(text1.substr(1),text2.substr(1),arr);
            
            arr[row][col]= max(max(opt1,opt2),opt3);
            return arr[row][col];
        
        }
    }
    int longestCommonSubsequence(string text1, string text2){
        int **arr;
        int n=text1.size();
        int m=text2.size();
        arr = new int *[n];
	    for (int i = 0; i < n; i++){
		    arr[i] = new int[m];
	    }
	    for (int i = 0; i < n; i++){
		    for (int j = 0; j < m; j++){
			    arr[i][j]=-1;
		    }
	    }
	    // for (int i = 0; i < n; i++){
	    // for (int j = 0; j < m; j++){
	    // cout<<arr[i][j]<<" ";
	    // }
	    // cout<<endl;
	    // }
        return longestCommonSubsequenceH(text1,text2,arr);
    }
};