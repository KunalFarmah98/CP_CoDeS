#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

// TLE wala code

/*void simple_enough(int n,int l,int r){

    if(n==0 || n==1) {
        ++i;
        if(i>=l && i<=r){
        if(n==1)
        ++c;
        }
       // ans.push_back(n);
        return;
    }

    simple_enough(n/2,l,r);
    simple_enough(n%2,l,r);
    simple_enough(n/2,l,r);


}*/



ll count_finalDigits(ll n)
{
    if(n==0 || n==1)
        return 1;
    else 
    // we r taking n/2 twice and then taking a mod
        return (count_finalDigits(n/2)*2)+1;
}
ll query(ll N,long long st,ll et,ll L,ll R)
{
    if(R<st || L>et || st>et)
    /// NO OVERLAP
        return 0;
    //cout<<st<<" "<<et<<" ";
    ll mid=(st+et)/2;
    ll ans=0;
    // if mid lies in the query of l...r
    // check if its value is 1 and count it
    // 0...mid -1 are due fo floor(n/2), mid is due to n%2, and mid+1....r is for floor(n/2)
    if(mid>=L && mid<=R && N%2==1)
        ans++;
        // check for left
    ans+=query(N/2,st,mid-1,L,R);
    //check for right
    ans+=query(N/2,mid+1,et,L,R);
    return ans;
}




int main(){
	ll n;
	ll l,r;
	cin>>n>>l>>r;

	 cout<<query(n,1,count_finalDigits(n),l,r);
	
}