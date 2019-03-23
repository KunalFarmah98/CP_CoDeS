
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

ll memo[101][101];


// ll eggDrop(ll n, ll k) 
// { 
//     // If there are no floors, then no trials needed. OR if there is 
//     // one floor, one trial needed. 
//     if (k == 1 || k == 0) 
//         return k; 
  
//     // We need k trials for one egg and k floors 
//     if (n == 1) 
//         return k; 

//     if(memo[n][k]!=-1)
//     	return memo[n][k];
  
//     ll final_ans = INT_MAX, x, worst_ans; 
  
//     // Consider all droppings from 1st floor to kth floor and 
//     // return the minimum of these values plus 1. 
//     for (x = 1; x <= k; x++) 
//     { 
//         worst_ans = 1 + max(eggDrop(n-1, x-1), // if egg breaks we are left with 1 less egg adn 1 less floor down
//         eggDrop(n, k-x)  // if egg doesn't break, we r left with same eggs and k-x floors up
//         ); 

//         final_ans=min(final_ans,worst_ans);
//     } 
  
//     return memo[n][k] = final_ans ; 
// } 

/* Function to get minimum number of trials needed in worst 
  case with n eggs and k floors */

int eggDrop(int n, int k) 
{ 
    /* A 2D table where entery eggFloor[i][j] will represent minimum 
       number of trials needed for i eggs and j floors. */
    int eggFloor[n+1][k+1]; 
    int res; 
    int i, j, x; 
  
    // We need one trial for one floor and 0 trials for 0 floors 
    for (i = 1; i <= n; i++) 
    { 
        eggFloor[i][1] = 1;   // wherever floors = 1
        eggFloor[i][0] = 0;   // wherever floors = 0
    } 
  
    // We always need j trials for one egg and j floors. 
    for (j = 1; j <= k; j++)   // base case, k trials for n eggs and k floors
        eggFloor[1][j] = j; 
  
// for all eggs and for all floors
    for (i = 2; i <= n; i++) 
    { 
        for (j = 2; j <= k; j++) 
        { 
            eggFloor[i][j] = INT_MAX; 

            for (x = 1; x <= j; x++) 
            { 
                res = 1 + max(eggFloor[i-1][x-1], eggFloor[i][j-x]);   // breaks and not breaks
                 eggFloor[i][j] = min(eggFloor[i][j],res);
            } 
        } 
    } 
  
    // eggFloor[n][k] holds the result 
    return eggFloor[n][k]; 
} 

int main(){
	
	memset(memo,-1,sizeof(memo));

   ll floors,eggs;
   cin>>eggs>>floors;

   cout<<eggDrop(eggs,floors)<<endl;


	return 0;
}