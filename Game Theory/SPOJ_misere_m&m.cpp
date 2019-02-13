
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;


void miser(int a[] ,int n){

    int f=1;

// checking if all piles are of size 1
    for(int i=0; i<n; i++){
        if(a[i]!=1){
        f=0;
        break;
        }
    }

// if all piles are size 1, then first player wins for even n and second wins for odd n
if(f==1 && n%2!=0){
cout<<"Brother"<<endl;
return;
}

else if(f==1 && n%2==0){
    cout<<"John"<<endl;
    return;
}

else{

int ans=0;
	
	for(int i=0; i<n; i++){
		ans = ans^a[i];
	}


	if(ans==0)
		cout<<"Brother"<<endl;
	else
		cout<<"John"<<endl;

}


}
int main(){
	
int t;
cin>>t;

while(t--){
	int n;
	cin>>n;

	int a[n];
	for(int i=0; i<n; i++){		
        cin>>a[i];
        }

	miser(a,n);

}


	return 0;
}