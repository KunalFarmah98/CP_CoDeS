
//KUNAL FARMAH
//@kunalfarmh98@gmail.com
#include<bits/stdc++.h>
using namespace std;

int memo[101][101];
int LCS_TD(char X[100], char Y[100], int i, int j){

   if(X[i]=='\0' || Y[j]=='\0')
   	return 0;

   int ans=0;

   if(memo[i][j]!=-1)
   return memo[i][j];

   if(X[i]==Y[j]){
   	ans = 1+LCS_TD(X,Y,i+1,j+1);
   }

   else{
   	ans = max(LCS_TD(X,Y,i,j+1),LCS_TD(X,Y,i+1,j));
   }


   return memo[i][j]=ans;
   
}

int LCS(char X[100], char Y[100]){

	int m = strlen(X); //no of rows
	int n = strlen(Y); //no of columns

	int dp[101][101];

// setting first row = 0
	for(int i=0;i<n; i++){
		dp[0][i]=0;
	}
// setting first col = 0

	for(int i=0;i<m; i++){
		dp[i][0]=0;
	}

	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			int ans=0;

// we have added an extra column for empty string 
// in dp so string[i][j] is equal to dp[i-1][j-1] 

			if(X[i-1]==Y[j-1])  // for match we take 1 + diagonally previous
				ans = 1+dp[i-1][j-1];
			else // for no match, we take x whole with y-1 or y whole with x-1
				ans = max(dp[i-1][j],dp[i][j-1]);

			dp[i][j] = ans;
		}

		
	}

	return dp[m][n];
}


int main(){
 char s1[100],s2[100];
//memset(memo,-1,sizeof(memo));
cin>>s1>>s2;
cout<<LCS(s1,s2);
//cout<<LCS_TD(s1,s2,0,0)<<endl;



	return 0;
}