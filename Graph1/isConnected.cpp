#include <iostream>
using namespace std;

#include <queue>
void print(int n,int sv, int**edges,bool *visited){
	if(n==0){
        return;
    }
    
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty()){
        int cv=q.front();
        q.pop();
        
    
       
        for(int i=0;i<n;i++){
			if(edges[cv][i]==1 && !visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
    
}

bool BFS(int n,int**edges,bool *visited ){
	print(n,0,edges,visited);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            return false;;
        }
    }
}

int main() {
    // Write your code here
    int n,e;
    cin>>n>>e;
    
    int**edges=new int*[n];
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
    
 	bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[n]=false;
    }
    
	if(n==0){
		cout<<"true"<<endl;
        return 0;
    }

    if(BFS(n,edges,visited)){
        cout<<"true"<<endl;
    }else{
        cout<<"false";
    }
    
}