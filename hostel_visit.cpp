#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll rocket(int x, int y){
    ll dist = abs(x*x) + abs(y*y);

    return dist;
}


int main() {
    int n,k;
    cin>>n>>k;

    int k1=k;

    int qtype; int x,y;

    priority_queue<ll> pq;

    int c=0;

    while(n--){

        cin>>qtype;
        if(qtype==1){
            cin>>x>>y;
            pq.push(rocket(x,y));
            ++c;

        }

        if(qtype==2) {

            ll temp[k];
            int i = 0;

            if (pq.size() == k)
                cout << pq.top() << endl;

            else {
                while (c-k1 > 0) {

                    temp[i] = pq.top();
                    pq.pop();
                    ++i;
                    k1++;
                }

                cout << pq.top() << endl;
                k1=k;
                --i;

                while (i >= 0) {
                    pq.push(temp[i]);
                    --i;
                }
            }
        }


    }
}
