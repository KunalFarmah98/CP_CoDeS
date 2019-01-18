
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    set<int> arrayset;

    int a[n];

    for(int i=0; i<n; i++){
        cin>>a[i];
        arrayset.insert(a[i]);
    }

    map<int,int> indexmapping;

    int i=1;
    auto it = arrayset.begin();
    for(; it!=arrayset.end(); it++,i++){

        indexmapping.insert(make_pair(*it,i));
    }

    for(int i=0;i<n;i++){
        // auto val = indexmapping[a[i]];
        // cout<<val->first<<" ";
        int val = indexmapping.find(a[i])->second;
        cout<<val<<" ";
    }





    return 0;
}