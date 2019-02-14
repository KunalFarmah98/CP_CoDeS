
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> primes;

ll dp[1000005];


ll calculateMex(unordered_set<ll> Set)
{
    ll Mex = 0;

    while (Set.find(Mex) != Set.end())
        Mex++;

    return (Mex);
}

// O(sqrt(n))
vector<ll>divisors(ll n)
{
    vector<ll>v;
    for(ll i=1;i*i<=n;i++)
    {
        if((n%i)==0) 
        {
           v.push_back(i);
           if((i*i)!=n && (i!=1))
            v.push_back(n/i);
        }
    }
    return v;
}


ll calculateGrundy(ll n)
{
   if(n==1) return 0;

// if ans is already present then use that
   if(dp[n]!=-1) 
    return dp[n]; 

   unordered_set<ll>set;

// this gives the different states of the game for the nth pile
   vector<ll>v=divisors(n);

   for(ll i=0;i<v.size();i++)
   {
      set.insert(calculateGrundy(v[i]));
   }
   return dp[n]=calculateMex(set);
}





ll winner(ll n,ll a[]){


    ll ans = 0;

    for (ll i = 0; i < n; ++i)
    {
    	ans = ans^calculateGrundy(a[i]);
    }

     return ans;



}

int main() {
    
    ll n,t,height;
    memset(dp,-1,sizeof(dp));
    cin>>t;
    while(t--) 
  {  
       cin>>n;   
       ll ans=0;
       for(ll i=0;i<n;i++)
       {
           cin>>height;
           ll grundy=calculateGrundy(height);
           ans=ans ^ grundy;
       }
       
       if(ans==0) 
        cout<<2<<endl;
       else 
        cout<<1<<endl;
  }
}

