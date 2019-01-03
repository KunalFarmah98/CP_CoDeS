// C++ program to calculate all multiples 
// of integer 'k' in array[] 
#include <bits/stdc++.h> 
using namespace std; 
  
// ans is global pointer so that both countSieve() 
// and countMultiples() can access it. 
int* ans = NULL; 
  
// Function to pre-calculate all multiples of 
// array elements 

/*
 IT USES THE LOGIC OF SEIVE IN WHICH WE USE MULTIPLES TO PRE COMPUTE A RESULT
*/

void countSieve(int arr[], int n) 
{ 
    int MAX = *max_element(arr, arr + n); 
  
    int cnt[MAX + 1]; 
  
    // ans is global pointer so that query function 
    // can access it. 
    ans = new int[MAX + 1]; 
  
    // Initialize both arrays as 0. 
    memset(cnt, 0, sizeof(cnt)); 
    memset(ans, 0, (MAX + 1) * sizeof(int)); 
  
   // maintaining a count array for the array arr[]
    for (int i = 0; i < n; ++i) 
        ++cnt[arr[i]]; 
  
    //counting the multiples of each number starting form 1 upto MAX 
    //using the count array and storing the final count of multiples of i at arr[i]

    for (int i = 1; i <= MAX; ++i) 
        // for each number from 1 to MAX
        for (int j = i; j <= MAX; j += i) 
            // count the number of multiples of i
            // so we increment by i
            ans[i] += cnt[j]; 
    return; 
} 
  
int countMultiples(int k) 
{ 
    // return pre-calculated result 
    return ans[k]; 
} 


int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    countSieve(a,n);

    int q;
    cin>>q;

    while(q>0){
        int k;
        cin>>k;

        cout<<countMultiples(k)<<endl;

        --q;
    }
}