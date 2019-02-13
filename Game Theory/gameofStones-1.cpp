// CPP program to find winner of 
// the game of N stones 
#include <bits/stdc++.h>
using namespace std;

 int position[100] = {0};
// finds the winning and losing 
// states for the 200 stones. 
void findStates(int position[],int n) {
    // 0 means losing state 
    // 1 means winning state 
    position[0] = 0;
    position[1] = 0;
    position[2] = 1;
    position[3] = 1;
    position[4] = 1;
    position[5] = 1;


    // find states for other positions 
    for (int i = 6; i <= n; i++) {
        if (!position[i - 2] || !position[i - 3]
            || !position[i - 5])
            position[i] = 1;
        else
            position[i] = 0;
    }
}

    int main(){
        int t;
        cin>>t;

        while(t--){
            int n;
            cin>>n;

           
            findStates(position,n);

            if(position[n]==1){
                cout<<"First"<<endl;
            }
            else
                cout<<"Second"<<endl;
        }
    }