
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cell_mitiosis(ll n,ll c1,ll c2,ll c3){

  ll dp[n+1];

  dp[0]=0;
  dp[1]=0;  // we have 1 cell so cost of making 1 cell is 0

  for(ll i=2; i<=n; i++){

    // we can reach an even cell by either doubling a smaller value or by incrementing a smaller value

    // decrementing a higher value will have more cost as it will include cost of either doubling 
    // or incrementing to get a higher number in the first place

  	if(i%2==0){
  		dp[i] = min((dp[i/2]+c1) , (dp[i-1]+c2));
  	}

  	// we can reach an odd cell by either incrementing or by doubling the value of (i+1)/2
  	// decrementing only takes place when we decrement (i+1)/2 else it will again not be feasable

  	else{
  		dp[i] = min((dp[i-1]+c2) , (dp[(i+1)/2] + c1 + c3));
  	}
  }

  return dp[n];



}


int main(){
	
  ll n;
  ll c1,c2,c3;

  cin>>n;
  cin>>c1>>c2>>c3;

  cout<<cell_mitiosis(n,c1,c2,c3)<<endl;


	return 0;
}