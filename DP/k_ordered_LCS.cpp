
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll memo[10000][10000][10000];

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

		if(k>0)
			ans= 1+k_ordered_LCS(X,Y,n,m,i+1,j+1,k-1);
		else{
// 			ans = max(
// 				ans,
// 				max(k_ordered_LCS(X,Y,n,m,i,j+1,k), // matching full X with Y
// 					k_ordered_LCS(X,Y,n,m,i+1,j,k)) // matching full Y with X
// 				);
            ans =  max(ans,k_ordered_LCS(X,Y,n,m,i+1,j,k));
            ans = max(ans,k_ordered_LCS(X,Y,n,m,i,j+1,k));
		}
	}

	return memo[i][j][k]=ans;
}


/*
int k_ordered_LCS_BU(ll X[], ll Y[], ll n, ll m, ll k){

	ll dp[101][101];

	for(int i=0; i<n; i++){
		dp[0][i]=0;
	}

	for(int j=0; j<m; j++){
		dp[j][0]=0;
	}

ll ans = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(X[i-1]==Y[j-1]){
				ans = 1+dp[i-1][j-1];
			}
			else{
				if(k>0){
					ans = 1 + dp[i-1][j-1];
					--k;
				}
				else{
					ans = max(ans,max(dp[i][j-1],dp[i-1][j]));
				}
			}
			dp[i][j]=ans;
		}

		
	}


	return dp[n][m];

}*/



int main(){

ll n,m,k;
 cin>>n>>m>>k;

 ll a[n],b[m];

memset(memo,-1,sizeof(memo));

for(int i=0;i<n; i++){
    cin>>a[i];
}

for(int i=0; i<m; i++){
    cin>>b[i];
}

cout<<k_ordered_LCS(a,b,n,m,0,0,k)<<endl;
//cout<<k_ordered_LCS_BU(a,b,n,m,k)<<endl;



	return 0;
}