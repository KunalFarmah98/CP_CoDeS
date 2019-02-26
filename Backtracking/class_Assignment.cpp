
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

int c=0;
int d[44]={0};
void numbers(int n,int i){



	if(i==n){
		++c;
	return;
}



   d[i] = 1;
   numbers(n,i+1);
   d[i] = 0;
   //d[i-1]=0;

   if(d[i-1]!=2){
   d[i] = 2;
   numbers(n,i+1);
   d[i] = 0;
   //d[i-1]=0;
}
}


int main(){

	int t;
	cin>>t;

	int a=1,b=2;

	while(t--){
		int n;
		cin>>n;

		numbers(n+1,1);
		cout<<c<<endl;
	}



	return 0;
}