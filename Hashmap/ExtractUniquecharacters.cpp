//Given a string S, you need to remove all the duplicates. That means, 
//the output string should contain each character only once. 
//The respective order of characters should remain same, as in the input string.


#include <unordered_map>
string uniqueChar(string str) {
	// Write your code here
    unordered_map<char,int> map;
    for(int i=0;i<str.length();i++){
        if(map.count(str[i])>0){
            int count = map.at(str[i])+1;
            map[str[i]]=count;
        }else{
            map[str[i]]=1;
        }
    }
    //unordered_map<char,int> ::iterator it =map.begin();
    string result="";
    for(int i=0;i<str.length();i++){
        if(map.count(str[i])>0){
            result+=str[i];
            map.erase(str[i]);
        }
    }
    
    return result;
    
}