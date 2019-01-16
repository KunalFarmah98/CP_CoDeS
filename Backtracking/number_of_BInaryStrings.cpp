#include<bits/stdc++.h>
using namespace std;

bool not_consexutive(int n){
	if(n==3){
		return false;
	}

	return (n<<1);


}

int main(){

	int t;
	cin>>t;

	while(t--){
		int n;
		int c=0;
		cin>>n;

		for(int i=0; i<(2<<n)-1; i++){
			if(not_consexutive(i))
				++c;
		}
		cout<<c;
	}
}