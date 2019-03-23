
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
ll memo[1001][1001];

ll O_n_knapsack(ll a[], ll wt[], ll n, ll cap, ll i){

    if(i==n)
    	return 0;

    if(memo[i][cap]!=-1)
    	return memo[i][cap];

    ll a1=0,a2=0,a3=0;

    if(cap>=wt[i])
    a1 = a[i]+O_n_knapsack(a,wt,n,cap-wt[i],i+1) ; // pickup and go forward

    if(cap>=wt[i])
    a2 = a[i]+O_n_knapsack(a,wt,n,cap-wt[i],i);	 // pickup again

    a3 = O_n_knapsack(a,wt,n,cap,i+1); // leave


    return memo[i][cap] = max(a1,max(a2,a3));
}

int main(){
	

    memset(memo,-1,sizeof(memo));
    ll n,cap;
    cin>>n>>cap;

    ll wt[n],a[n];

      for(int i=0; i<n; i++){
        cin>>wt[i];
    }

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

  
    	cout<<O_n_knapsack(a,wt,n,cap,0);




	return 0;
}