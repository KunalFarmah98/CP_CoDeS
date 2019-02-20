#include <bits/stdc++.h>
using namespace std;

void calc_median(priority_queue<int, vector<int>, greater<int> > pq, int n){

    int val1,val2;

    if(n==1) {
        cout << pq.top() << " ";
        //return;
    }

    else if(n==2) {
        val1 = pq.top();
        pq.pop();
        val2 = pq.top();

        cout << (val1 + val2) / 2 << " ";

        pq.push(val1);

        //return;
    }

    else {

        if (n % 2 != 0) {
            int index = (n+1) / 2;
            int k = 0;
            int temp[index];
            while (index > 1) {

                temp[k] = pq.top();
                pq.pop();
                ++k;
                --index;
            }

            cout << pq.top() << " ";
            // putting back the values
            while (k--) {
                pq.push(temp[k]);
            }
        } else {
            int i1 = (n+1) / 2;
            int i2 = i1 + 1;

            int k = 0;
            int temp[i1];
            while (i1 > 1) {
                temp[k] = pq.top();
                pq.pop();
                ++k;
                --i1;
            }

            int val1 = pq.top();
            pq.pop();
            int val2 = pq.top();
            cout << (val1 + val2) / 2 << " ";
 // putting back the values
            pq.push(val1);
            while (k--) {
                pq.push(temp[k]);
            }
        }
    }
    //return;

}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        priority_queue<int, vector<int>, greater<int> > pq;
        int s=0;

        int median[n+1];

        for(int i=1; i<=n; i++){
            int val;
            cin>>val;
            pq.push(val);

            calc_median(pq,i);
        }


        cout<<endl;
    }
}
