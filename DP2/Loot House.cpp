int maxMoneyLooted(int *arr, int n)
{

    int *loot=new int[n];
    loot[0]=arr[0];
    loot[1]=max(arr[0],arr[1]);
    for(int i=2;i<n;i++){
		int val1=arr[i]+loot[i-2];
        int val2=loot[i-1];
        loot[i]=max(val1,val2);
    }
 	return loot[n-1];   
}
    
