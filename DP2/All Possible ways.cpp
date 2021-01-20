#include <bits/stdc++.h>
int getAllWaysHelper(int a, int b,int c) {
	// Write your code here
    if(pow(c,b)<a){
        return getAllWaysHelper(a,b,c+1)+getAllWaysHelper(a-pow(c,b),b,c+1);
    }else if(pow(c,b)==a){
        return 1;
    }else{
        return 0;
    }
}
int getAllWays(int a, int b) {
	// Write your code here
    return getAllWaysHelper(a,b,1);
}