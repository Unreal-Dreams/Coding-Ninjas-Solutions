long staircase(int n)
{
	//Write your code here
    long *arr=new long[n+1];
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(n==3){
		return 4;
    }
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    
    for(int i=4;i<=n;i++){
		arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
    }
    
    return arr[n];

}