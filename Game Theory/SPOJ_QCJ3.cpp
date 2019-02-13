//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;



// here n coins in pile i means there are n piles of i coins each
// hence if n is odd, the ans will be i and if n is even ans will be 0 after xoring
int winner(int a[], int n){

int ans=0;
	for(int i=0; i<n; i++){
            if(a[i]%2!=0)
            	ans=ans^i;
          
	}

	return ans;
}
int main(){
	
int t;
cin>>t;

while(t--){
	int n;
	cin>>n;

	int ans =0;
	for(int i=1; i<=n; i++){
		int x;
	cin>>x;
	if(x&1)
		ans=ans^i;
}

    if(ans==0)
    	cout<<"Hanks Wins"<<endl;
    else
    	cout<<"Tom Wins"<<endl;
}


	return 0;
}