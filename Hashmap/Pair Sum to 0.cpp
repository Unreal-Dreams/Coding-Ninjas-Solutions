#include <unordered_map>
int pairSum(int *a, int n) {
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
    int result1=0;
    if(map.count(0)>0){
        int freq =map.at(0);
        result1 = (freq*(freq-1))/2;
    }
    int result=0;
    for(int i=0;i<n;i++){
        if(a[i]!=0 && map.count(-1*a[i])>0){
            int freq =map.at(a[i])*map.at(-1*a[i]);
            result+=freq;
            map.erase(-1*a[i]);
            map.erase(a[i]);
            
        }
    }
    return result+result1;
    
    
}