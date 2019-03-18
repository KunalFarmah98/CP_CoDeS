
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

int mindistance(int grid[][3], int m, int n){

   int dp[100][100] = {};

// first cell is same as grid
   dp[0][0] = grid[0][0];

   // setting up first row
       for(int c=1; c<n; c++){
          dp[0][c] = dp[0][c-1] + grid[0][c];
       }

       // setting up first column

       for(int r=1; r<m; r++){
       	dp[r][0] =dp[0][r-1] + grid[r][0];
       }

// cost of each cell is min of going rightward and downward
// + the cost of that cell in grid
  
     for(int r=1; r<m; r++){
     	for(int c=1; c<n; c++){
     		
     		dp[r][c] = min(
     			dp[r-1][c], // coming from top 
     			dp[r][c-1]) // coming from left ->
                + grid[r][c];
     	}
     }

     for(int r=0; r<m; r++){
     	for(int c=0; c<n; c++){
     		cout<<setw(3)<<dp[r][c]<<" ";
     	}
         cout<<endl;
     }

     return dp[m-1][n-1];
}

int main(){
	
    int grid[3][3] = {{1,2,3},
    				{4,8,2},
    				{1,5,3}};


    cout<<mindistance(grid,3,3)<<endl;				


	return 0;
}