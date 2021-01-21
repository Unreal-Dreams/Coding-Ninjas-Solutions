#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
void bfs(int **edges,int n,bool *visited,int sv,vector<int> &arr){
    if(n==0){
        return;
    }
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty()){
        arr.push_back(q.front());
        sv=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(i==sv){
                continue;
            }
            if(edges[sv][i]==1 && !visited[i]){
               visited[i]=true; 
                q.push(i);
            }
        }
    }
    
    
  
    
}
 
int main(){
    int n,e;
    cin>>n>>e;
    int** edges =  new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
         for(int j=0;j<n;j++){
             edges[i][j]=0;
         }
    }
   
    
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool *visited = new bool[n];
     for(int i=0;i<n;i++){
         visited[i]=false;
       
    }
    
     vector<int> arr;
   
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            bfs(edges,n,visited,i,arr);
              sort(arr.begin(),arr.end());
            for(int j=0;j<arr.size();j++){
                cout<<arr.at(j)<<" ";
            }
            arr.clear();
            cout<<endl;
            

        }
        
      
    }
    
    
   
}