
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,v;
    cin>>n>>v;

    int tank=0,cost=0;


    for(int i=1; i<n; i++){
        //int remcities = n-i;
        int gasReq = n-i;

        // tank-=1;
        int remTank = tank;


        int extra_req = gasReq - remTank;

        if(extra_req>0){
            if(extra_req>v){

                cost+=v*i;
                tank+=v;

            }
            else{
                cost+=extra_req*i;
                tank+=extra_req;
            }

// if tanks contents exeed v, we empty the extra amount
            if(tank>v){
                int extra = tank-v;
                tank -= extra;
                cost-=extra*i;
            }
        } else{
            break;
        }

        tank--;
    }

    cout<<cost<<endl;




    return 0;
}
