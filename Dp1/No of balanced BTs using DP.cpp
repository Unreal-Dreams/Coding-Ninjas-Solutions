#include <cmath>
int balancedBTs(int n) {
    // Write your code here
    if(n==1){
        return 1;
    }
    if(n==2){
        return 3;
    }
    
    int *arr=new int[n+1];
    int mod=(int)(pow(10,9))+7;
	arr[1]=1;
    arr[2]=3;
    for(int i=3;i<n+1;i++){
		arr[i]=-1;
    }
    
    if(arr[n]!=-1){
        return arr[n];
    }
    
    for(int i=3;i<n+1;i++){
        long x=(long)(arr[i-1]);
        long y=(long)(arr[i-2]);
 		int temp1=(int)((x*x)%mod);
    	int temp2=(int)((2*x*y)%mod);
		int ans= (temp1+temp2)%mod;
        arr[i]=ans;
    }
    
    return arr[n];
}