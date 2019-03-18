
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

int memo[100];

int maxProfit(int price[], int total_length){
	if(total_length==0)
		return 0;
   
   if(memo[total_length]!=-1)
   	return memo[total_length];

   int best= 0;

// for each initital cut, calculate cost of other cuts
   for(int len=1; len<=total_length; len++){
   	    int ans = price[len] + maxProfit(price,total_length-len);
   	    best = max(best,ans);
   }

   return memo[total_length] = best;

}


int maxProfit_bottumUp(int price[], int total_length){

	int dp[100] = {};

int best = 0;
// starting form length 1, make cuts form 1 to len and find best profit
	for(int len =1; len<=total_length; ++len){
		
		for(int cut =1; cut<=len; ++cut){

			best = max(best,price[cut] + dp[len-cut]);
            
			dp[len] = best;
		}
	}

	return dp[total_length];
}

int main(){
	   
	memset(memo,-1,sizeof(memo));

   int n;
   cin>>n;


   // for(int i=0; i<=n; i++)
   // 	memo[i]=-1;

   int price[n];
   for(int i=1 ;i<=n; i++)
   	cin>>price[i];

   cout<<maxProfit_bottumUp(price,n);


	return 0;
}
