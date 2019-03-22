
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


ll MOD = 1000003;
ll n,x;
ll dp[105][3][105];


ll  diw_puzl(ll i, ll prev, ll cnt){

// if we reach last element
	if(i==n){
		// if we have got ans as k, we have found 1 way to do it
		if(cnt==x){
			return 1;
		}
		
			return 0;
	}

	
    

    if(dp[i][prev][cnt]!=-1)
    	return dp[i][prev][cnt];

    ll ans = 0;
	
	// if we place 1 in i
	
	if(prev==1){
		// if prev element was 1, the contribution increases by 1
       ans =  ans+diw_puzl(i+1,1,cnt+1);
       
       // i also becomes prev for i+1
	}
	else{
		// if prev was 0, contribution remains same
		ans = ans+diw_puzl(i+1,1,cnt);
		
    }

    ans%=MOD;

    // if we place 0
    // contribution remains same no matter what prev was

     ans = ans + diw_puzl(i+1,0,cnt);
     ans%=MOD;

     return dp[i][prev][cnt] = ans;



}

int main(){
	
   ll t;
   cin>>t;

   while(t--){

   	memset(dp,-1,sizeof(dp));
  
   	cin>>n>>x;

   	// we return sum of both cases 
   	// when we put 1 + when we put 0 as we are free to assume any configuration

   	cout<<(( diw_puzl(1,0,0) + diw_puzl(1,1,0 ))%MOD)<<endl;
   }


	return 0;
}
