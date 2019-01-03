#include <bits/stdc++.h>
using namespace std;

vector<int> count(int a[], int n){
    vector<int>c(n+1,0);
    for(int i=0; i<n; i++){
        ++c[a[i]];
    }

    return c;
}

int line(int x,int m, int c){
    return ((m*x)+c);
}

int main() {
   int n,m,c;

   cin>>n>>m>>c;

   int a[n];
   for(int i=0; i<n; i++)
   cin>>a[i];


// counting occurrences of each element
  vector<int> cnt =  count(a,n);


    sort(a,a+n);
    int num=0;

    for(int i=1; i<=n; i++){
        int y = line(a[i-1],m,c);
        //checking if the y coordinate exists int the array
        if( binary_search(a,a+n,y)!=-1)
        num = num+cnt[y];  //simply adding the number of occurences as we only need to count the pairs
        }

    cout<<num<<endl;
}
