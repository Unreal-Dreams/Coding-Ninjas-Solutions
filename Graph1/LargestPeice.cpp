int get(vector<vector<int>> &cake, int n , bool** visited,int i,int j)
{
    if(i>=n || j>=n || i<0 || j<0)
    {
        return 0;
    }
    if(cake[i][j]==0||visited[i][j])
    {
        return 0;
    }
    visited[i][j]=true;
    int l,r,u,d;
    l = get(cake,n,visited,i,j-1);
    r = get(cake,n,visited,i,j+1);
    u = get(cake,n,visited,i-1,j);
    d = get(cake,n,visited,i+1,j);
    return l+r+d+u+1;
}
int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here
    bool** visited = new bool*[n];
    for(int i = 0 ; i < n ; i++)
    {
        visited[i] = new bool[n];
        for(int j = 0 ; j < n ; j++)
        {
            visited[i][j] = false;
        }
    }
    int max = 0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(visited[i][j])
            {
                continue;
            }
            int temp = get(cake,n,visited,i,j);
            if(temp>max)
            {
                max = temp;
            }
        }
    }
    return max;
}