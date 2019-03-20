
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007;

ll dp[1001][1001];


ll robot_paths(ll n, ll m){

// we start from 0,0
// if first cell is blocked, ques is over
  if(dp[0][0]==-1)
  	return 0;

  // setting base case for first row
  for(int i=0; i<m; i++){
  	// if a cell is blocked, no need to check for further cells as all are 0
  	if(dp[0][i]==-1)
  		break;
  	dp[0][i]=1;
  }

   // setting base case for first column
  for(int i=0; i<n; i++){
  	// if a cell is blocked, no need to check for further cells as all are 0
  	if(dp[i][0]==-1)
  		break;
  	dp[i][0]=1;
  }

  for(int i=1; i<n; i++){
  	for(int j=1; j<m; j++){

// if current cell is blocked, move on mothafucka
  		if(dp[i][j]==-1)
  			continue;

  		// if top cell is not blocked, we can reach from top by going down
 		if(dp[i-1][j]!=-1)
  		dp[i][j] = dp[i-1][j]%MOD;

		// if left cell is not blocked, we can reach form left by goinhg right
  	    if(dp[i][j-1]!=-1)
  	    	dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
  	}


  }

  // for(int i=0; i<n; i++){
  //     for(int j=0; j<n; j++){
  //         cout<<setw(3)<<dp[i][j]<<" ";
  //     }
  //     cout<<endl;
  // }

  // if final cell was blocked, hm to chutiya he na bc

  if(dp[n-1][m-1]==-1)
  	return 0;
  else
  	return dp[n-1][m-1];

}

int main(){
	
  int n,m,k;
  cin>>n>>m>>k;

  memset(dp,0,sizeof(dp));

  for(int i=0; i<k; i++){
  	int x,y;
  	cin>>x>>y;
  	// marking blocked cells with -1;
      // indexing is from 0,0 in the function so -1
  	dp[x-1][y-1]=-1;
  }

  cout<<robot_paths(n,m)<<endl;


	return 0;
}