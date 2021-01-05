#include <queue>

int buyTicket(int *arr, int n, int k) {
    // Write your code here
    queue<int> q;
    priority_queue<int> pq;
    
    for(int i=0;i<n;i++){
        q.push(i);
        pq.push(arr[i]);
    }
    int timer=0;
    while(true){
        int frontIndex=q.front();
        if(arr[frontIndex]==pq.top()){
            if(frontIndex==k){
				return ++timer;
            }
            q.pop();
            pq.pop();
            timer++;
        }else{
            q.pop();
            q.push(frontIndex);
        }
    }
}