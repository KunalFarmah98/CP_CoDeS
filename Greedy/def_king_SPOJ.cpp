#include <bits/stdc++.h>
using namespace std;

int maxval(int a[], int n){
    int max = INT_MIN;

    for(int i=1; i<n; i++){
        int diff = a[i]-a[i-1]-1;
        if(diff>max)
            max=diff;
    }

    return max;
}
int main() {
    int t;
    cin>>t;

    while(t--){
        int n;
        int x_max,y_max;
        cin>>x_max>>y_max>>n;

       // if there is no crossbow tower, entire area is undefended

        if(n==0){
        cout<<x_max*y_max<<endl;
        continue;
        }

        int x[n+2];
        int y[n+2];

        x[0]=y[0]=0;
        for(int i=1; i<=n; i++){
            cin>>x[i]>>y[i];
        }


        sort(x,x+n+1);
        sort(y,y+n+1);

    // adding the extreme values to the x and y array as they might contribute to the ans
        x[n+1]=x_max;
        y[n+1]=y_max;

        int max_delta_x = maxval(x,n+2);    // the max undefended area is simply the product of max difference bw consecuting verical
        int max_delta_y = maxval(y,n+2);    // and horizontal towers by logic

        cout<<max_delta_x*max_delta_y<<endl;

    }
}
