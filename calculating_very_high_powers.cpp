#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
ll mod = 1000000007;


/*
WE TAKE MOD AT EACH STEP FOLLOWING THE PORPERTIES OF MOD TO PREVENT INTEGER OVERFLOW AT EVERY STEP
*/

ll STOI(string a, ll m){

ll ans=0;
	for(int i=0; i<a.size();i++){                      // 157 % 10
		                                              // 1 % 10 = 1
		                                             // (1*10) + 5
		                                            // 15 % 10 = 5
												   // (5*10) + 7
		                                          // 57 % 10 = 7 = ans
		ans =  (ans*10)%m + (a[i]-'0');
		ans= ans%m;
	}

	return ans;

}

ll power(ll x, ll y, ll m){


	// base case
	if(y==0)
		return 1;

	//recursive steps

	ll smallpower = power(x,y/2,m);
	smallpower = smallpower%m;

   //squaring the power as we halved it before          // (x*x) kiya he yha
	smallpower = (smallpower*smallpower)%m;

    // if smallpower 'x' is odd, make it x(x*x)    // x*x is done already in above line
	// eg x^5 = x(x^2)^2

	if(smallpower&1)
         return (x*smallpower)%m;

         // if smallpower 'x' is even, keep it (x*x)     // x*x is done already in above line
         //eg x^4 = (x^2)^2

	else
		return (smallpower%m);
}


int main(){

	string a,b;
	cin>>a>>b;

	ll x = STOI(a,mod);
	ll y = STOI(b,mod);

	ll ans = power(x,y,mod);

	cout<<ans<<endl;
}