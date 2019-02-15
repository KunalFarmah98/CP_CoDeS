
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

//std::vector<int> perfect_squares;
 int perfect_squares[]={1,4,27,256,3125,46656,823543};

 int dp[1000005];

std::vector<int> closest_perfectSquares_diff(int n){
    std::vector<int> psd;

    for(int i=0; perfect_squares[i]<=n; i++){
        int val = n-perfect_squares[i];
        if(val>=0)
            psd.push_back(val);
        else
            break;
    }

    return psd;
}



int calculateMex (unordered_set<int> Set)
{
    int Mex = 0;

    while (Set.find (Mex) != Set.end())
        Mex++;

    return (Mex);
}

int calculateGrundy(int n){


        if(n==0)
        return 0;

        if(n==1)
        return 1;

          if(dp[n]!=-1)
        return dp[n];



    unordered_set<int> set;

    std::vector<int> next_state = closest_perfectSquares_diff(n);

    for(int i=0; i<next_state.size(); i++){
        set.insert(calculateGrundy(next_state[i]));
    }

    return dp[n]=calculateMex(set);
}


int winner(int n, int a[]){

    int ans=0;
    for(int i=0; i<n; i++){

        ans = ans^calculateGrundy(a[i]);
    }

    return ans;


}



int main(){

    memset(dp,-1,sizeof(dp));

    int t;
    cin>>t;

    while(t--){
        int n,m;

        cin>>n;
        int ans=0;

       // int a[n];
        int x;
        for(int i=0; i<n; i++){
            cin>>x;
            ans = ans^calculateGrundy(x);
            //cin>>a[i];
        }

        //int ans = winner(n,a);

        if(ans!=0){
            cout<<"Little Chef"<<endl;
        }
        else
            cout<<"Head Chef"<<endl;

    }



    return 0;
}