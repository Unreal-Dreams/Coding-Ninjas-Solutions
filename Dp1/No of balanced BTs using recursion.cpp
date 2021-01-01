include<cmath>
int balancedBTs(int n) {
    // Write your code here
    if(n==0){
		return 1;
    }
    if(n==1){
        return 1;
    }
    long x=balancedBTs(n-1);
    long y=balancedBTs(n-2);
    int mod=(int)(pow(10,9))+7;
    int temp1=(x*x)%mod;
    int temp2=(2*x*y)%mod;
	int ans= (temp1+temp2)%mod;
    return ans;
}