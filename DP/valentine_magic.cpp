
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

 ll n,m;
  ll chocolates[5001], candies[5001];

ll memo[5001][5001];

ll valentines_magic(ll i, ll j){
	
	if(i==n)  // all boys are paired
		return 0;

	if(j==m)  // we rejected all girls, wtf bruh
		return INT_MAX;


	if (memo[i][j]!=-1) 
		return memo[i][j];

	ll op1 = abs(chocolates[i]-candies[j]) + valentines_magic(i+1,j+1);  // we paired ith boy with jth girl
	 																	// so check for i+1 and j+1 and add
	ll op2  = valentines_magic(i,j+1); // we didn't pair then, so try other pairs

	

	return memo[i][j] = min(op1,op2);  // we need min ans
}


// wrong approach gready doesn't work here

// int valentines_magic(int n, int m, int chocolates[], int candies[]){

// 	int sum=0;
// 	int minval = INT_MAX;

// 	for(int i=0; i<n; i++){
// 		for(int j=0; j<m; j++){
// 			int ans = abs(chocolates[i]-candies[j]);
// 			minval = min(minval,ans);
// 		}
// 		sum+=minval;
// 	}

// 	return sum;
// }

int main(){
	
  	memset(memo,-1, sizeof(memo));
   cin>>n>>m;

 
   for(int i=0; i<n; i++) cin>>chocolates[i];
   	for(int i=0; i<m; i++) cin>>candies[i];

   		 sort(chocolates,chocolates+n);
         sort(candies,candies+m);

   		cout<<valentines_magic(0,0)<<endl;


	return 0;
}