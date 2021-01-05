#include <bits/stdc++.h> 
typedef pair<int, pair<int, int> > ppi; 
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    // Write your code here
    vector<int> output;
    priority_queue<ppi, vector<ppi>, greater<ppi> > pq;
    for(int i=0;i<input.size();i++){
    	ppi p;
        p.first=input[i]->at(0);
        p.second.first=i;
        p.second.second=0;
        
        pq.push(p);
    }
    
    while(pq.size()!=0){
        ppi curr=pq.top();
        pq.pop();
        int i = curr.second.first; 
        int j = curr.second.second; 
  
        output.push_back(curr.first); 
         if (j + 1 < input[i]->size()) {
            pq.push({ input[i]->at(j + 1), { i, j + 1 } });
         }
    }
    
    return output;
    
    
}