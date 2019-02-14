#include <bits/stdc++.h>
using namespace std;


int binarySearch(long arr[], int l, int r, long x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}

class compare{
    public:
        bool operator()(pair<long,long> a, pair<long,long> b){

            // if((a.second-a.first)==(b.second-b.first))
            //     return a.first>b.first;
         return (abs(a.second-a.first)>abs(b.second-b.first));
    }
};

void pairofRoses(long a[], int n, int m){
    priority_queue<pair<long,long>, vector<pair<long,long> >, compare> p;

    for(int i=0; i<n; i++){
        long r1  = a[i];
        long r2 = m-a[i];
        int index = binarySearch(a,0,n,r2);
        if(index!=-1 && index!=i)
            p.push(make_pair(a[i],a[index]));
        }

        pair<long,long> pr = p.top();
        long r1 = pr.first;
        long r2 = pr.second;
        if(r1>r2)
                cout<<"Deepak should buy roses whose prices are "<<r2<<" and "<<r1<<"."<<endl;
                else
                 cout<<"Deepak should buy roses whose prices are "<<r1<<" and "<<r2<<"."<<endl;
    }


int main() {
    int t;
    cin>>t;

    long a[10000]={0};

    while(t--){
        int n;
        cin>>n;


        for(int i=0; i<n; i++){
        cin>>a[i];
        }

        int m;
        cin>>m;

        sort(a,a+n);

        pairofRoses(a,n,m);
        cout<<endl;
    }
}
