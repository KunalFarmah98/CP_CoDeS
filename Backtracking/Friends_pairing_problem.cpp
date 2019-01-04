
#include <bits/stdc++.h> 
using namespace std; 
  
  // bottom up dp aproach

/*// Returns count of ways n people  
// can remain single or paired up. 
int countFriendsPairings(int n) 
{ 
    int dp[n + 1]; 
  
    // Filling dp[] in bottom-up manner using 
    // recursive formula explained above. 
    for (int i = 0; i <= n; i++) 
    { 
        if (i <= 2) 
        dp[i] = i; 
        else
        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2]; 
    } 
  
    return dp[n]; 
} */

ll dp[1000]; 
  
// Returns count of ways n people  
// can remain single or paired up. 
ll countFriendsPairings(ll n) 
{ 
    if(dp[n]!=-1) 
    return dp[n]; 
  
    if(n>2)  
    return dp[n] = countFriendsPairings(n-1)+  
                (n-1)*countFriendsPairings(n-2); 
    else
    return dp[n] = n; 
} 
  

int main(){

    memset(dp,-1,sizeof(dp)); 
    int t;
    cin>>t;
    
    while(t--){
    int n;
    cin>>n;
    
    cout<<countFriendsPairings(n)<<endl;
    }
}