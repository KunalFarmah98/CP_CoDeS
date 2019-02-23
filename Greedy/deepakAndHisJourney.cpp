#include <iostream>
using namespace std;
typedef long long ll;
int main() {

    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        ll l[n],  c[n], mincost[n];

        for(int i=0 ;i<n; i++){

            cin>>c[i];
            //he has to fill up at first station
            if(i==0){
            mincost[i]=c[i];
            }

            // at each step taking the min of previous value and current value

            else{
                mincost[i] = min(c[i],mincost[i-1]);
            }
        }

         for(int i=0 ;i<n; i++){
             cin>>l[i];
         }

         ll cost=0;

         for(int i=0; i<n; i++){
             // calculating cost of filling up petrol at each min station
             cost += l[i]*mincost[i];
         }

         cout<<cost<<endl;
        
    }
    
}
