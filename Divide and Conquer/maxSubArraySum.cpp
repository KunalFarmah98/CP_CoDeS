// A Divide and Conquer based program for maximum subarray sum problem 
#include<bits/stdc++.h>
using namespace std;
  
  typedef long long ll;
  
// Find the maximum possible sum in arr[] auch that arr[m] is part of it 
ll maxCrossingSum(ll arr[], ll l, ll m, ll h) 
{ 
    // Include elements on left of mid. 
    ll sum = 0; 
    ll left_sum = -999999999; 
    for (ll i = m; i >= l; i--) 
    { 
        sum = sum + arr[i]; 
        if (sum > left_sum) 
          left_sum = sum; 
    } 
  
    // Include elements on right of mid 
    sum = 0; 
    ll right_sum = -99999999; 
    for (ll i = m+1; i <= h; i++) 
    { 
        sum = sum + arr[i]; 
        if (sum > right_sum) 
          right_sum = sum; 
    } 
  
    // Return sum of elements on left and right of mid 
    return left_sum + right_sum; 
} 
  
// Returns sum of maxium sum subarray in aa[l..h] 
ll maxSubArraySum(ll arr[], ll l, ll h) 
{ 

   if (l == h) 
     return arr[l]; 

   ll m = (l + h)/2; 
  
   /* Return maximum of following three possible cases 
      a) Maximum subarray sum in left half 
      b) Maximum subarray sum in right half 
      c) Maximum subarray sum such that the subarray crosses the midpoint */
   return max(maxSubArraySum(arr, l, m), 
              max(maxSubArraySum(arr, m+1, h), 
              maxCrossingSum(arr, l, m, h))); 
} 


int main(){
    ll t;
    cin>>t;

    while(t--){

        ll n;
        cin>>n;
        ll a[n];

        for(ll i=0; i<n; i++){
            cin>>a[i];
        }

        cout<<maxSubArraySum(a,0,n-1)<<endl;
    }
}