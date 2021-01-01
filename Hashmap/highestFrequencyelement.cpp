#include <unordered_map>
int highestFrequency(int a[], int n) {
    // Write your code here
    unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        if(map.count(a[i])>0){
            int count = map.at(a[i])+1;
            map[a[i]]= count;
        }else{
            map[a[i]]=1;
        }
    }
    int maxfreqlement= a[0];
    int maxfrequency=map.at(a[0]);
    for(int i=1;i<n;i++){
        if(map.at(a[i])>maxfrequency){
            maxfrequency=map.at(a[i]);
            maxfreqlement =a[i];
        }
    }
    return maxfreqlement;
    
}