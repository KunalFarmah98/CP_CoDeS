#include <bits/stdc++.h>
using namespace std;

int maxdel(int a[],int n){
    int max = INT_MIN;
    for(int i=0; i<=n-1; i++){
        int diff = a[i+1]-a[i]-1;   // space between two rivers is 1 less than their coordinate distance
        if(diff>max)
        max=diff;
    }

    return max;
}
int main() {
    int n;
    cin>>n;
    
    int x[n+1];
    int y[n+1];
    x[0]=y[0]=0;
    for(int i=1; i<=n; i++){
        cin>>x[i]>>y[i];   // taking inputs of x and y coordinates
    }

    sort(x,x+n+1);
    sort(y,y+n+1);

   // the lasest area coresponds to the product of the largest space bw two consecutive vertical and horizontal rivers
    int max_delta_x=maxdel(x,n+1);
    int max_delta_y=maxdel(y,n+1);

        cout<<max_delta_x*max_delta_y;





    
}
