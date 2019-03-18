
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

int dp[10000];
int reduce(int n){
    
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    dp[3]=1;

    for(int i=4; i<=n; i++){
       int a1=INT_MAX;
       int a2=INT_MAX;
       int a3=INT_MAX;

    	if(i%3==0)
    		a1=1+dp[i/3];

    	if(i%2==0)
    		a2=1+dp[i/2];

    	a3=1+dp[i-1];
    	dp[i] = min(a1,min(a2,a3));
    }

    return dp[n];
}

int reduce_memoized(int n){

	if(n<=3)
		return 1;

	int q1=INT_MAX;
	int q2=INT_MAX;
	int q3=INT_MAX;

	if(n%3==0){
		q1=1+reduce(n/3);
	}

	if(n%2==0)
		q2 = 1+ reduce(n/2);

	q3 = 1+ reduce(n-1);

	return dp[n] = min(q1,min(q2,q3));



}

int main(){
	
	int n;
	cin>>n;

	//memset(dp,sizeof(dp),-1);
    for(int i=0; i<1000; i++)
    dp[i]=-1;

	cout<<reduce_memoized(n)<<endl;
	return 0;
}