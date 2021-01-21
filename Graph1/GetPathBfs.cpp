#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
#include <vector>
vector<int> * getPath(int n,int sv,int ev,int**edges,bool* visited){
   
    if(sv==ev){
        vector<int>*vec=new vector<int>;
        vec->push_back(sv);
        return vec;
    }
    
    queue<int> q;
    q.push(sv);
    unordered_map<int,int> map;
	bool isPresent=false;
    while(!q.empty()){
        int cv=q.front();
        q.pop();
        
        for(int i=0;i<n;i++){
            if(edges[cv][i]==1 && !visited[i]){
                visited[i]=true;
                map[i]=cv;
                q.push(i);
                if(i==ev){
                    isPresent=true;
                    break;
                }
                
            }
        }
        if(isPresent){
			break;
        }
    }
    
    if(!isPresent){
		return NULL;
    }
    
    vector<int>*vec=new vector<int>;
    int cv=ev;
    int val=0;
    for (auto i = map.begin(); i != map.end(); i++){ 
    	if(map.count(cv)>0){
        	val=map[cv];
        }else{
            break;
        }
        vec->push_back(cv);
        cv=val;
        if(val==sv){
			break;
        }
    }
    vec->push_back(sv);
    return vec;
    
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
    
    int sv,ev;
    cin>>sv>>ev;
    
 	bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    visited[sv]=true;
    if(e==0){
		return 0;
    }
    vector<int> *small=getPath(n,sv, ev,edges, visited);
	if(small!=NULL){
		for(int i=0;i<small->size();i++){
            cout<<small->at(i)<<" ";
        }
    }
 
    
}