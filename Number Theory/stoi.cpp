#include<bits/stdc++.h>
using namespace std;


long long mod = 1E9+7;

long long STOI(string a, long long m){

long long ans=0;
	for(int i=0; i<a.size();i++){
		ans =  (ans*10)%m + (a[i]-'0');
		ans= ans%m;
	}

	return ans;

}

int main(){

	string a = "9847283748327489237423987423897328";
	cout<<STOI(a,mod);
}