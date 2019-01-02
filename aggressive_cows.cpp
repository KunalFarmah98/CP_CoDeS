#include<iostream>
#include<algorithm>
using namespace std;

bool ispossible(int a[], int n, int mid,int c){

    int cows=1;   // intialising no of cows by 1 as 1 cow can be placed
    int prev =a[0];  // the prev position of every element will be stored here,
    // as we start from 1, its prev will be at a[0]

    for(int i=1; i<n; i++){
        if(a[i]-prev>=mid){   // if there is a gap of mid bw curr and prev position, place a cow and
            // update prev with the current position for the next arrangement
            ++cows;
            prev=a[i]; // updating the prev
        }
        if(cows==c)
            return true;
    }

    return false;

}

int b_search(int a[], int s, int e, int n, int c){

    static int ans=-1;
    int mid = (s+e)/2;


    if(s>e){
        return ans;
    }


    if(ispossible(a,n,mid,c)){  // if we can place in the ans, try to search in its right and store the last ans
        ans=mid;
        b_search(a,mid+1,e,n,c);
    }
    else{ // if we can't place, go to the left side
        b_search(a,s,mid-1,n,c);
    }

    return ans;
}


int main(){
    // int t;
    // cin>>t;


    //while(t--){
    int n,c;
    cin>>n>>c;

    int a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    sort(a,a+n);

    cout<<b_search(a,a[0],a[n-1],n,c)<<endl;
    //}
}