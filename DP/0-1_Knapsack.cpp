
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll memo[1001][1001];

ll knapsack(ll a[],ll wt[], ll n, ll w, ll i){

	if(i==n)
		return 0;

	if(memo[i][w]!=-1)
		return memo[i][w];

	int profit=0;
	int profit1 = 0;
    int profit2 = 0;

	if(wt[i]<=w){
	profit1 = a[i] + knapsack(a,wt,n,(w-wt[i]),i+1); // if we take that item
	}

	profit2 = knapsack(a,wt,n,w,i+1);      // if we leave that item

	profit=max(profit1,profit2);

	return memo[i][w]=profit;

}

ll knapsack_bottomUp(ll a[], ll wt[], ll n, ll w){
	ll dp[1001][1001]={0};



	for(int i=1; i<=n; i++){  // ofr each item
		for(int cap=1; cap<=w;cap++){  // for each capacity left
        ll profit1=0,profit2=0;
			if(wt[i-1]<=cap){  // if wt is less than capacity, take it
				profit1 = a[i-1] + dp[i-1][cap - wt[i-1]];
			}
       // leave it
			profit2 = dp[i-1][cap];
			dp[i][cap] = max(profit1,profit2);
		}

		
	}

	return dp[n][w];
}


int main(){

	memset(memo,-1,sizeof(memo));
	ll n,w;
	cin>>n>>w;

	ll a[n];
	 ll wt[n];

     for(int i=0; i<n; i++){
		cin>>wt[i];
	}

	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	

	//cout<<knapsack(a,wt,n,w,0)<<endl;
	cout<<knapsack_bottomUp(a,wt,n,w)<<endl;



	return 0;
}