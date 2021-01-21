#include <bits/stdc++.h>
void initialize(bool **visited,int N,int M){
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            visited[i][j]=false;
    }
}


bool dfs(vector<vector<char>> Graph,char c[],int i,int j,int N,int M,bool ** visited,bool **dp){
    
    if(Graph[i][j]=='A')
        return true;
    
    if(i>=N || j>=M){
        return false;
    }
    
    visited[i][j]=true;
    bool ans=false;
    if(dp[i][j]){
        return dp[i][j];
    }
    
    if(i-1>=0 && j-1>=0 && Graph[i-1][j-1]==c[0] && !visited[i-1][j-1])
        ans=ans || dfs(Graph,c+1,i-1,j-1,N,M,visited,dp);
    
    if(i-1>=0 && Graph[i-1][j]==c[0] && !visited[i-1][j])
        ans=ans || dfs(Graph,c+1,i-1,j,N,M,visited,dp);
    
    if(i-1>=0 && j+1<M && Graph[i-1][j+1]==c[0] && !visited[i-1][j+1])
        ans=ans || dfs(Graph,c+1,i-1,j+1,N,M,visited,dp);
    
    if(j+1<M && Graph[i][j+1]==c[0] && !visited[i][j+1])
        ans=ans || dfs(Graph,c+1,i,j+1,N,M,visited,dp);
    
    if(i+1<N && j+1<M && Graph[i+1][j+1]==c[0] && !visited[i+1][j+1])
        ans=ans || dfs(Graph,c+1,i+1,j+1,N,M,visited,dp);
    
    if(i+1<N && Graph[i+1][j]==c[0] && !visited[i+1][j])
        ans=ans || dfs(Graph,c+1,i+1,j,N,M,visited,dp);
    
    if(i+1<N && j-1>=0 && Graph[i+1][j-1]==c[0] && !visited[i+1][j-1])
        ans=ans || dfs(Graph,c+1,i+1,j-1,N,M,visited,dp);
    
    if(j-1>=0 && Graph[i][j-1]==c[0] && !visited[i][j-1])
        ans=ans || dfs(Graph,c+1,i,j-1,N,M,visited,dp);
     visited[i][j]=false;
    dp[i][j]=ans;
    return ans;
    
    
    
    
    
}

bool hasPath(vector<vector<char>> &Graph, int N, int M) {
    char c[]="CODINGNINJA";
    bool **visited=new bool*[N];
    bool **dp=new bool*[N];
    for(int i=0;i<N;i++){
        visited[i]=new bool[M];
        dp[i]=new bool[M];

        
    }
    
    initialize(visited,N,M);
    initialize(dp,N,M);

    for(int i=0;i<N;i++){
        
        for(int j=0;j<M;j++){
            bool ans=false;
            if(Graph[i][j]=='C'){
                ans=dfs(Graph,c+1,i,j,N,M,visited,dp);
                if(ans)
                    return 1;
                
                initialize(visited,N,M);
                initialize(dp,N,M);

                
            }
        }
    }
    
    return 0;
}