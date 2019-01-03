#include<iostream>
using namespace std;

typedef long long ll;

ll mod = 1E9+7;

ll power(ll x, ll y, ll m){


	// base case
	if(y==0)
		return 1;

	//recursive steps

	ll smallpower = power(x,y/2,m);
	smallpower = smallpower%m;

//squaring the power as we halved it before (x*x) kiya he yha
	smallpower = (smallpower*smallpower)%m;

   // if smallpower 'x' is odd, make it x(x*x)
	// eg x^5 = x(x^2)^2

	if(smallpower&1)
         return (x*smallpower)%m;

         // if smallpower 'x' is even, keep it (x*x)
         //eg x^4 = (x^2)^2

	else
		return (smallpower%m);
}


int main(){

	ll x,y;
	cin>>x>>y;

	cout<<power(x,y,mod)<<endl;
}