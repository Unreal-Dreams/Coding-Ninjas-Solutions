#include <unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
    unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        if(map.count(arr[i])>0){
            int count1 = map.at(arr[i])+1;
            map[arr[i]]= count1;
        }else{
            map[arr[i]]=1;
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(map.count(arr[i]-k)>0 && k!=0){
            count+=map.at(arr[i]-k)*map.at(arr[i]);
            map.erase(arr[i]-k);
        }else if(map.count(arr[i]-k) && k==0){
            int freq=map.at(arr[i]);
            count+=(freq*(freq-1))/2;
             map.erase(arr[i]);
        }
    }
    return count;
    
}