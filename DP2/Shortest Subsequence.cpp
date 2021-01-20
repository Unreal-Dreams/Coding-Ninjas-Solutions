#include <climits>
int solve(string s, string v,int **arr) {
    // Write your code here
    if(v.size()==0){
        return s.size();
    }
    if(s.size()==0){
        return 2000;
    }
    int n=s.size();
    int m=v.size();
    if(arr[n][m]!=-1){
        return arr[n][m];
    }
    int small1=solve(s.substr(1),v,arr);
    
    char temp=s[0];
    int index=-1;
    for(int i=0;i<v.size();i++){
        if(v[i]==temp){
            index=i+1;
            break;
        }
    }
  	
    if(index==-1){
    	arr[n][m]= 1;
        return arr[n][m];
    }
    
    int small2=1+solve(s.substr(1),v.substr(index),arr);
    arr[n][m]=min(small1,small2);
	return arr[n][m];
}

int solve(string s, string v){
    int **arr;
    int n=s.size()+1;
    int m=v.size()+1;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j]=-1;
        }
    }
    
    return solve(s,v,arr);
}