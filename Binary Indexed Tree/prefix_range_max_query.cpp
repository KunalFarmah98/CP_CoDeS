#include <iostream>
using namespace std;

// BIT CAN ONLY ANSWER PREFIX MAX QUERIES BECAUSE OF ITS STRUCTURE, 
// AND WE CAN'T DO LIKE MAX(3,6) WE CAN ONLY FROM 1 TILL I

// PREFIX MAX QUERY

int BIT[10000] = {0};

void update(int index, int n, int val){
    // updating the required index and then only updating where that range exists (next power of 2 index)
    // given by i+(i&-i)
    // also setting the max as the new max 
    while(index<=n){
        BIT[index]=max(BIT[index],val);
        index+=(index&(-index));
    }
}

void build(int a[], int n){
    // building is similar to updating all indices of a 0 initialised BIT 
    //with inc equal to the original array
    for(int i=1; i<=n; i++){
    update(i,n,a[i]);
     }
}

int query(int i){
    int ans=0;
    // going back from one index to the next index with the last set bit removed till 0
    while(i>0){
        ans = max(ans,BIT[i]);
        i-=(i&(-i));
    }

    return ans;
}

// this won't work here!!

/*// for both inclusive, range l,r is diffference of range r and l-1
int rangequery(int l, int r){
    return query(r)-query(l-1);
}*/

int main() {
    int n;
    cin>>n;

    int a[n+1];

    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    build(a,n);

    // alternate for building BIT
    /*for(int i=1; i<=n; i++){
        cin>>a[i];
        update(i,n,a[i]);
    }*/

     //update(3,n,10);

    int q;
    cin>>q;

    while(q--){
        int x;
        cin>>x;
        cout<<query(x)<<endl;
    }

    return 0;
}
