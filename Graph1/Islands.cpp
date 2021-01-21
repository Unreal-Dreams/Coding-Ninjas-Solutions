#include <bits/stdc++.h>
using namespace std;

void helper(int **edge,int n,int src,bool *vis){
    vis[src]=true;
    for(int i=0;i<n;i++){
        if(i==src)continue;
        if(edge[src][i]==1){
            if(vis[i])continue;
            helper(edge,n,i,vis);
        
    }}
}
int main() {
    // Write your code here
    int n,e;
    cin>>n>>e;
    int **edge=new int*[n];
    for(int i=0;i<n;i++){
        edge[i]=new int[n];
        for(int j=0;j<n;j++)edge[i][j]=0;
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edge[f][s]=1;
        edge[s][f]=1;}
    int c=0;
     bool *vis=new bool[n];
    for(int i=0;i<n;i++)vis[i]=false;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            helper(edge,n,i,vis); 
            c++;
        }
    }
    
    cout<<c;
}