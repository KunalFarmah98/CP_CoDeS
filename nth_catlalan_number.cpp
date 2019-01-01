#include<iostream>
using namespace std;

typedef unsigned long long int ll;

ll catalan(int n){

	ll ans =1;

	//2n C n = 2n!/n!n!
	for(int i=2*n,j=1; i>=n+1,j<=n; i--,j++){
		ans = (ans*i)/j;
//		ans*=i;
//		ans/=j;
	}

	return ans/(n+1);
}


int main(){
	int n;
	cin>>n;

	cout<<catalan(n)<<endl;
}