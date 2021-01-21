#include <iostream>
using namespace std;

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
    int tricycle=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(edges[i][j]==1){
                for(int k=0;k<n;k++){
                    if(k==i || k==j){
                        continue;
                    }
                    if(edges[k][j]==1 && edges[k][i]==1){
                        tricycle++;
                    }
                }
            }
        }
    }
    cout<<tricycle/6<<endl;
    
    
}