
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;


int max_profit(int a[], int n){


  int dp[1000][1000] = {};


  int year = n;

// setting up price for 5th year, i.e only 1 bottle, i.e diagonals
  for(int i=0; i<n; i++)
  	dp[i][i] = year*a[i];

  --year; // start for the next year


// for length 2 onwards, i.e n-1 th year
  for(int i=2; i<=n; i++){
  	// setting up sliding window for length = i

  	int start = 0;
  	int end = n-i;

  	while(start<=end){
  		// end of current window is start index + length - 1
  		int end_of_window = start + i - 1;

  		dp[start][end_of_window] = max(
  			a[start]*year + dp[start+1][end_of_window] , // selling first bottle and then asking for others
  			a[end_of_window]*year + dp[start][end_of_window-1] // selling others first and then send last
  			);

  		++start;

  	} 

  	--year;
  }

  for(int i=0 ;i<n; i++){
      for(int j=0; j<n; j++){
          cout<<setw(3)<<dp[i][j]<<" ";
      }
      cout<<endl;
  }

  return dp[0][n-1];


}

int main(){
   
   int n;
   cin>>n;

   int a[n];

   for(int i=0; i<n; i++)
   cin>>a[i];

   cout<<max_profit(a,n)<<endl;	



	return 0;
}