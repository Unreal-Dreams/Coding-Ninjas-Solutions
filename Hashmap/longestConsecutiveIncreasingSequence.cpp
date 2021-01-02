#include <bits/stdc++.h>
#include <unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    unordered_map<int,bool> map;
    int maxcount=0,length=0,start=0,starter=0;
    bool k=true;
    for(int i=0;i<n;i++){
       map[arr[i]]=true;
    }
    for(int i=0;i<n;i++){
        if(map.at(arr[i])==true){
            int search= arr[i]+1;
             start=arr[i];
             length=0;
            map[arr[i]]=false;
            while(map.count(search)){
                map[search]=false;
                length++;
                search++;
            }
            search=arr[i]-1;
            while(map.count(search)){
                map[search]=false;
                start=search;
                length++;
                search--;
            }
            if(length>maxcount){
                maxcount= length;
                starter=start;
            }else if(arr[i]==start && length==maxcount && k && length!=0){
                maxcount= length;
                starter=start;
                k=false;
            }
        }
    }
    
    vector<int> v;
    v.push_back(starter);
    if(maxcount>0){
        v.push_back(starter+maxcount);
    }
    return v;
}