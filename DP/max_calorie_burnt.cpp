
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

/*int calorie(int mat[3][3], int m, int n){
  
    int dp1[101][101]={-1}; // top left to bottom right
    int dp2[101][101]={-1}; // top right to bottom left
    int dp3[101][101]={-1}; // bottom left to top right
    int dp4[101][101]={-1}; // bottom right to top left

    dp1[0][0] = mat[0][0];
    for(int i=1;i<m;i++){
    	for(int j=1; j<n ;j++){
    		dp1[i][j] = max(dp1[i-1][j],dp1[i][j-1])+mat[i-1][j-1];
    	}
    }

    dp2[0][n-1] = mat[0][n-1];
      for(int i=1;i<m;i++){
        for(int j=n-2; j>=0 ;j--){
    		dp2[i][j] = max(dp2[i-1][j],dp2[i][j+1])+mat[i-1][j-1];
    	}
    }

    dp3[m-1][0] = mat[m-1][0];
      for(int i=m-2;i>=0;i--){
    	for(int j=1; j<n ;j++){
    		dp3[i][j] = max(dp3[i+1][j],dp3[i][j-1])+mat[i-1][j-1];
    	}
    }

    dp4[m-1][n-1] = mat[m-1][n-1];
      for(int i=m-2;i>=0;i--){
    	for(int j=n-2; j>=0 ;j--){
    		dp4[i][j] = max(dp4[i+1][j],dp4[i][j+1])+mat[i-1][j-1];
    	}
    }

    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++)
    //     cout<<setw(3)<<dp1[i][j]<<" ";
    //     cout<<endl;
    // }

    //  for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++)
    //     cout<<setw(3)<<dp2[i][j]<<" ";
    //     cout<<endl;
    // }

    //  for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++)
    //     cout<<setw(3)<<dp3[i][j]<<" ";
    //     cout<<endl;
    // }

    //  for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++)
    //     cout<<setw(3)<<dp4[i][j]<<" ";
    //     cout<<endl;
    // }

    int ans=0;

    for(int i=1;i<m; i++){
    	for(int j=1;j<=n;j++){

    		int case1 = (dp1[i-1][j]+dp2[i][j-1]+dp3[i][j+1]+dp4[i+1][j]);
    		int case2 = (dp1[i][j-1]+dp2[i-1][j]+dp3[i+1][j]+dp4[i][j+1]);
    		ans = max(ans,max(case1,case2));
    			
    	}
    }

    return ans;


}*/

// calories == points

int findMaxPoints(int A[][M]) 
{ 
    // To store points collected by Person P1 
    // when he/she begins journy from start and 
    // from end. 
    int P1S[M+1][N+1], P1E[M+1][N+1]; 
    memset(P1S, 0, sizeof(P1S)); 
    memset(P1E, 0, sizeof(P1E)); 
  
    // To store points collected by Person P2 
    // when he/she begins journey from start and 
    // from end. 
    int P2S[M+1][N+1], P2E[M+1][N+1]; 
    memset(P2S, 0, sizeof(P2S)); 
    memset(P2E, 0, sizeof(P2E)); 

    // points collected = max of points collected from both 
    // directions + points collected at the current cell
  
    // Table for P1's journey from 
    // start to meeting cell 

    //dp1

    for (int i=1; i<=N; i++) 
        for (int j=1; j<=M; j++) 
            P1S[i][j] = max(P1S[i-1][j], 
                  P1S[i][j-1]) + A[i-1][j-1]; 
  
    // Table for P1's journey from 
    // end to meet cell 

    // dp4
        
    for (int i=N; i>=1; i--) 
        for (int j=M; j>=1; j--) 
            P1E[i][j] = max(P1E[i+1][j], 
                  P1E[i][j+1]) + A[i-1][j-1]; 
  
    // Table for P2's journey from start to meeting cell 

        // dp3

    for (int i=N; i>=1; i--) 
        for(int j=1; j<=M; j++) 
            P2S[i][j] = max(P2S[i+1][j], 
                  P2S[i][j-1]) + A[i-1][j-1]; 
  
    // Table for P2's journey from end to meeting cell 

        // dp2

    for (int i=1; i<=N; i++) 
        for (int j=M; j>=1; j--) 
            P2E[i][j] = max(P2E[i-1][j], 
                  P2E[i][j+1]) + A[i-1][j-1]; 
  
    // Now iterate over all meeting positions (i,j) 
    int ans = 0; 
    for (int i=2; i<N; i++) 
    { 
        for (int j=2; j<M; j++)  // as per notes, recurrence for the solution
        { 
            int op1 = P1S[i][j-1] + P1E[i][j+1] + 
                      P2S[i+1][j] + P2E[i-1][j]; 
            int op2 = P1S[i-1][j] + P1E[i+1][j] + 
                      P2S[i][j-1] + P2E[i][j+1]; 
            ans = max(ans, max(op1, op2)); 
        } 
    } 
    return ans; 
} 
  
// Driver code 
int main() 
{ 
    //input the calories burnt matrix 
    int A[][M] = {{100, 100, 100}, 
                  {100, 1, 100}, 
                  {100, 100, 100}}; 
    cout << "Max Points : " << findMaxPoints(A); 
    return 0; 
} 
