
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int check(ll n, ll m, ll x, ll y,ll val){
       if(val*x<=m+(n-val)*y)
       	return true;

    //   else{
    //   	 int coupons_left = (val*x)%m;
    //   	 // if another student can buy y coupons to  make x left again and there is at  least
    //   	 // 1 more student left, then its true
    //   	 if(coupons_left+y>=x && n>val)
    //   	 return true;

       	else{
       	return false;
       }

    //   }


}

ll c=INT_MIN;

int coupons(ll n,ll m, ll x, ll y, ll beg, ll end){

     if(beg>end)
     	return c;

      	ll mid = (beg+end)/2;

      	// check if we can give scholarship to mid no of students, check for higher number
      	if(check(n,m,x,y,mid)){

              if(mid>c){
                  c=mid;
              }
      		return coupons(n,m,x,y,mid+1,end);

      	}

      	// else check for lower number

      	else{
      		return coupons(n,m,x,y,beg,mid-1);

      	}

}

int main(){

	ll n,m,x,y;
	cin>>n>>m>>x>>y;

    // if(m/x==n){
    // cout<<n<<endl;
    // return 0;
    // }

	cout<<coupons(n,m,x,y,0,n);



	return 0;
}