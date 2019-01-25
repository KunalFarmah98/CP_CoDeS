#include <bits/stdc++.h>
using namespace std;

struct act{
    int s,e;
};
class compare{
    public:
    bool operator()(act a, act b){
        if(a.e==b.e){
            return a.s<b.s;
        }
        return a.e<b.e;
    }
};



int main() {
    int t;
    cin>>t;

    while(t--){
        int count=0;
        int n;
        cin>>n;

       act a[n];
       map<act,int,compare> activities;          // making a map mapping the activities as id to their initial index
       // which will sort the activities acc to their end times while keeping their index intact

        for(int i=0; i<n; i++){
            cin>>a[i].s>>a[i].e;
             activities.insert(make_pair(a[i],i));
        }



        auto initial = activities.begin();
        act taken = initial->first;          // always take the first activity of the map
     
        count++;
      
        for(auto it=(activities.begin()); it!=activities.end(); it++){
     

           if(it->first.s >= taken.e){    // if the current next est ctivity doesn't overlap the taken , we add it to our ans
             
            count++;
              taken=it->first;        // and taken becomes the current act
              
           }
        }
        cout<<count<<endl;


    }
}
