#include <queue>
#include <vector>

void printRunningMedian(int *arr, int n) {
    // Write your code here
    
    //Min Heap Max Heap Approach
    if(n==0){
		return;
    }
    
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int>> min;
    
	max.push(arr[0]);
    cout<<arr[0]<<" ";
    
    for(int i=1;i<n;i++){
        if(arr[i]>max.top()){
            min.push(arr[i]);
            if(min.size()-max.size()>1){
                max.push(min.top());
                min.pop();
            }
        }else{
            max.push(arr[i]);
            if(max.size()-min.size()>1){
                min.push(max.top());
                max.pop();
            }
        }
        
        if((min.size()+max.size())%2==0){
            cout<<(min.top()+max.top())/2<<" ";
        }else{
            if(min.size()>max.size()){
				cout<<min.top()<<" ";
            }else{
				cout<<max.top()<<" ";
            }
        }
    }
}