#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

	ll a[1000005],preSum[1000005]; // it is precomputed to for safety take n+5 as size

	int t;
	cin>>t;

	// this stores the frequncy of cummulative sum % n




	while(t>0){
		int n;
		cin>>n;


		ll sum = 0;

		memset(preSum,0,sizeof preSum);

		// acc to pegionhole atleast 1 (sum % n) will be 0 as we have N+1 possible results in
	   // cumulative sum but we take modulo with N with only N elements

		preSum[0]=1;


		for(int i=0; i<n; i++){
			cin>>a[i];

			// precomputing sum and its modulo with the input to use in the query
			sum+=a[i];
			sum%=n;
			// if sum is negative making it positive to get correct mod
			sum=(sum+n)%n;

			// update the frequency of modulo sum
			preSum[sum]++;
		}

    ll ans = 0;

		for(int i=0; i<n-1; i++){
            ll no = preSum[i];

			ans  += ((no)*(no-1))/2;                 // using k(C)2 =  k(k-1)/2

		}

		cout<<ans<<endl;

		--t;
	}
}