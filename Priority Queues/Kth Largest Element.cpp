bool isMaxHeap(int arr[], int n) {
    // Write your code here
    int li=(n-2)/2;
    int strt=0;
    while(strt<=li){
		int c1=2*strt+1;
        int c2=2*strt+2;
    	if(c2<n){
			if(arr[strt]>arr[c1] && arr[strt]>arr[c2]){
                strt++;
                continue;
            }else{
				return false;
            }
        }else{
			if(arr[strt]>arr[c1]){
                return true;
            }else{
                return false;
            }
        }
        strt++;
    }
    return true;
}