Ques:
Given an integer N, find and return the count of minimum numbers required to represent N as a sum 
of squares.

Explanation:
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}.The output will be 1,
as 1 is the minimum count of numbers required to represent N as sum of squares.

//This is the optimal solution

Sol:
#include <cmath>
int minCount(int n)
{
	//Write your code here
    if(n==1){
        return 1;
    }
    
    int *arr=new int[n+1];
    for(int i=0;i<n+1;i++){
		arr[i]=INT_MAX;
    }
    
    arr[0]=0;
    arr[1]=1;
    int lastPerfect=1;
    for(int i=2;i<n+1;i++){
        for(int j=lastPerfect;j>0;j--){
            
            if(i<pow(j+1,2)){
            	int temp=i-pow(j,2);
				arr[i]=min(arr[i],1+arr[temp]);
       		}else if(i>pow(j+1,2)){
                int temp=i-pow(j,2);
                arr[i]=min(arr[i],1+arr[temp]);
            }else{
            	arr[i]=1;
            	lastPerfect++;
				break;
        	}
        }
       
    }
    
    return arr[n];
}