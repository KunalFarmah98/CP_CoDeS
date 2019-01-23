
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;


int main(){

    long long t;
    cin>>t;

    while(t--){
        long long n;
        cin>>n;

        string name;
        long long pref;
        long long cnt[n+1]={0};
        for(int i=0; i<n; i++){
            cin>>name;
            cin>>pref;
            cnt[pref]++;
        }

        long long ans=0;
        long long pos=1;
        for(int i=1; i<=n; i++){
             // start giving them ranks
            while(cnt[i]){
                // adding the badness
                ans+=abs(i-pos);
                cnt[i]--;
                pos++;
            }
        }

        cout<<ans<<endl;
    }




    return 0;
}