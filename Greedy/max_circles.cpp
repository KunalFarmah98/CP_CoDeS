#include <bits/stdc++.h>
using namespace std;
struct circle{
    long long s,e;
};

class compare{
public:
    bool operator()(circle a, circle b){
        return a.e<b.e;
    }
};
int main() {
    long long n;
    cin>>n;

    vector<circle> v(n);
    long long c,r;

    for(int i=0; i<n; i++){
        cin>>c>>r;
        v[i].s=c-r;
        v[i].e=c+r;
    }

    sort(v.begin(), v.end(),compare());

    int removed=0;
    circle taken = v[0];
    for(auto  it =v.begin()+1; it!=v.end(); it++){
        circle curr = *it;
        //taken = curr;
        //circle prev = *(it-1);
        if (curr.s<taken.e){   // if starting of next is smaller than ending of current, we will count it and skip it (equivalent to removal)
            //v.erase(it);
            //++it;
            ++removed;
        }
        else{
            taken = curr;
        }
    }

    cout<<removed<<endl;
}
