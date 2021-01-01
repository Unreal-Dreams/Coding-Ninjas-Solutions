#include <unordered_map>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    unordered_map<int,int> map;
    int maxlength=0;
    
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0){
            maxlength=i+1;
        }else if(map.count(sum)>0){
             int length=0;
            if(map.at(sum)==0){
               length=i-map.at(sum)+1; 
            }else{
                length= i-map.at(sum);
            } 
            if(length>maxlength){
                maxlength=length;
            }
        }else{
            map[sum]=i;
        }
    }
    return maxlength;
    
}