#include <bits/stdc++.h>
using namespace std;

struct act{
    int s,e;
};
class compare{
    public:
    bool operator()(act a, act b){
        return a.e>b.e;
    }
};



int main() {
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

       act a[n];
       map<act,int,compare()> activities;

        int s,e;
        for(int i=0; i<n; i++){
            cin>>a[i].s>>a[i].e;
             activities.insert(make_pair(a[i],i));
        }


        for(auto it=activities.begin(); it!=activities.end(); it++){
            cout<<it->first.s<<" "<<it->first.e<<" "<<it->second<<endl;
        }


    }
}
