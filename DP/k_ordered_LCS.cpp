
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll memo[2005][2005][8];

ll k_ordered_LCS(ll X[], ll Y[], ll n, ll m, ll i, ll j, ll k){
	
	if(i==n || j==m)
		return 0;

	if(memo[i][j][k]!=-1)
		return memo[i][j][k];

	ll ans=0;

	if(X[i]==Y[j]){
		ans = 1 + k_ordered_LCS(X,Y,n,m,i+1,j+1,k);
	}

	else{

		if(k>0){
			ans= 1+k_ordered_LCS(X,Y,n,m,i+1,j+1,k-1);
		}
            ans =  max(ans,k_ordered_LCS(X,Y,n,m,i+1,j,k));
            ans = max(ans,k_ordered_LCS(X,Y,n,m,i,j+1,k));
	}

	return memo[i][j][k]=ans;
}

int main(){


memset(memo,-1,sizeof(memo));

ll n,m,k;
 cin>>n>>m>>k;

 ll a[n],b[m];



for(int i=0;i<n; i++){
    cin>>a[i];
}

for(int i=0; i<m; i++){
    cin>>b[i];
}

cout<<endl<<k_ordered_LCS(a,b,n,m,0,0,k)<<endl;
//cout<<k_ordered_LCS_BU(a,b,n,m,k)<<endl;



	return 0;
}
