int countStepsToOne(int n)
{
	//Write your code here
    int *arr=new int[n+1];
    arr[1]=0;
    arr[2]=1;
    arr[3]=1;
    for(int i=4;i<n+1;i++){
        arr[i]=-1;
    }
    for(int i=4;i<n+1;i++){
		if(i%2==0 && i%3==0){
            arr[i]=min(min(1+arr[i/3],1+arr[i/2]),1+arr[i-1]);
        }
        else if(i%3==0){
			arr[i]=min(1+arr[i/3],1+arr[i-1]);		
        }
        else if(i%2==0){
            arr[i]=min(1+arr[i/2],1+arr[i-1]);
        }else{
            arr[i]=1+arr[i-1];
        }
    }
    
    return arr[n];
}