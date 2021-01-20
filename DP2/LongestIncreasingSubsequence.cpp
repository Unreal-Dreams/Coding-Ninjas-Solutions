#include <bits/stdc++.h>
int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
    int *sub=new int[n];
    
    sub[0]=1;
    if(arr[1]>arr[0]){
        sub[1]=2;
    }else{
        sub[1]=1;
    }
    
    for(int i=2;i<n;i++){
        sub[i]=1;
    }
    
	for(int i=2;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]){
                sub[i]=max(sub[i],1+sub[j]);
            }
        }
    }
    
    sort(sub,sub+n);
    return sub[n-1];
}