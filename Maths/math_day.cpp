#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll power(ll a, ll b, ll p){
	if(b==0)
		return 1;


	ll smallpow = power(a,b/2,p);
	smallpow%=p;
	
	smallpow*=smallpow;
	smallpow%=p;

	if(smallpow&1){
		smallpow = a*smallpow;
		return smallpow%p;
	}

	else
		return smallpow%p;
}

ll fact_pow(ll a, ll n, ll p ){

//ll ans =1;

	for(int i=2; i<=n; i++){
		//pr*=i;
		//pr%=p;
		a=power(a,i,p);
		a%=p;
	}

	return a%p;
}



int main(){

	int t;
	cin>>t;

	while(t--){
	ll a,n,p;
	cin>>a>>n>>p;

	cout<<fact_pow(a,n,p)<<endl;
}
}