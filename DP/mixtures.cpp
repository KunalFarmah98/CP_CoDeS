
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll memo[101][101];

ll csum(int a[], int s, int e){
    ll sum=0;
    for(int i=s; i<=e;i++){
        sum+=a[i];
        sum%=100;
    }
    return sum;
}




ll mixtures(int a[], int i ,int j){

    if(i>=j)   // if only 1 or no mixture is there
        return 0;


    if(memo[i][j]!=-1)
        return memo[i][j];

    ll ans=INT_MAX;

// consider division in all steps from beg to end
    for(int k=i; k<j; k++){

    	// ans is the sum of mixture from (i to k), mixture from (k+1 to j) and mixing both these mixtures
    	// we take min of all cases
        ans = min(ans,mixtures(a,i,k)+mixtures(a,k+1,j)+(csum(a,i,k)*csum(a,k+1,j)));
    }


    return memo[i][j]=ans;



}

int main(){

        int n;
     

        while((scanf("%d",&n))!=EOF){

            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++)
                memo[i][j]=-1;
            }
        int a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        cout<<mixtures(a,0,n-1)<<endl;
        }
 
    return 0;
}