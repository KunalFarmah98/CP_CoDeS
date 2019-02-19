#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll rocket(ll x, ll y){
    ll dist = abs(x*x) + abs(y*y);

    return dist;
}


int main() {
    ll n,k;
    cin>>n>>k;

    ll k1=k;

    ll qtype; ll x,y;

    priority_queue<ll> pq;

    ll c=0;

    while(n--){

        cin>>qtype;
        if(qtype==1){
            cin>>x>>y;
        
            if(pq.size()==k){
                // a value greater than the root can never be the kth nearest
                if(rocket(x,y)>pq.top())
                    continue;
                    // if we get a value less than the top, then that would be the
                    // candidate for the kth nearest, so we can remove the top value
                else{
                    pq.pop();
                    pq.push(rocket(x,y));
                }
            }
            else if(pq.size()<k){
            pq.push(rocket(x,y));
            }
            ++c;


        }

        if(qtype==2) {

        
                cout << pq.top() << endl;

       
        }


    }
}
