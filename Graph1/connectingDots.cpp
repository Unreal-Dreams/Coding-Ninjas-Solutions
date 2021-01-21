void initialize(bool ** visited,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            visited[i][j]=false;
    }
}


bool dfs(vector<vector<char>> &board,char col,int pi,int pj,int i,int j,int n,int m,bool **visited){
    
    //cout<<i<<" "<<j<<endl;
    
    bool d1=(i+1<n && !(i+1==pi && j==pj) && visited[i+1][j]);
    bool d2=(j+1<m && !(i==pi && j+1==pj) && visited[i][j+1]);
    bool d3=(i-1>=0 && !(i-1==pi && j==pj)&& visited[i-1][j]);
    bool d4=(j-1>=0 && !(i==pi && j-1==pj) && visited[i][j-1]);
    
    if(d1 || d2 || d3 || d4)
        return true;
    
    bool ans=false;
    visited[i][j]=true;
    if(i+1<n && board[i+1][j]==col && !visited[i+1][j])
        ans=ans || dfs(board,col,i,j,i+1,j,n,m,visited);
    
    if(j+1<m && board[i][j+1]==col && !visited[i][j+1])
        ans=ans || dfs(board,col,i,j,i,j+1,n,m,visited);
    
    if(i-1>=0 && board[i-1][j]==col && !visited[i-1][j])
        ans=ans || dfs(board,col,i,j,i-1,j,n,m,visited);
    
    if(j-1>=0 && board[i][j-1]==col && !visited[i][j-1])
        ans=ans || dfs(board,col,i,j,i,j-1,n,m,visited);
    
    return ans;
}

int hasCycle(vector<vector<char>> &board,int n, int m)
{
	// Write your code here.
    bool **visited=new bool*[n];
    for(int i=0;i<n;i++){
        visited[i]=new bool[m];
    }
    initialize(visited,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bool ans=false;
            if(!visited[i][j]){
                char color=board[i][j];
                ans=dfs(board,color,i,j,i,j,n,m,visited);
                initialize(visited,n,m);
                //cout<<"======"<<endl;
                //cout<<endl;
                //cout<<ans<<endl;
                if(ans)
                    return 1;
            }
        }
    }
    return 0;
}