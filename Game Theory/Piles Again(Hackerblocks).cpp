//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;



// here n coins in pile i means there are n piles of i coins each
// hence if n is odd, the ans will be i and if n is even ans will be 0 after xoring

//int winner(int a[], int n){

// int ans=0;
// 	for(int i=0; i<n; i++){
//             if(a[i]%2!=0)
//             	ans=ans^i;
          
// 	}

// 	return ans;
// }
int main(){
	
ll t;
cin>>t;

while(t--){
	ll n;
	cin>>n;

	ll ans =0;
	for(ll i=0; i<=n-1; i++){
		ll x;
	cin>>x;

	if(x&1)
		ans=ans^i;

}

    if(ans==0)
    	cout<<"Second"<<endl;
    else
    	cout<<"First"<<endl;
}


	return 0;
}