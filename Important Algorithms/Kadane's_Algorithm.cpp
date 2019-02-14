
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;


int maxSubArraySum(int a[], int n){

// we keep track of the current max sum and the actual maximum sum
    int curr_max = a[0];
    int max_sum = a[0];

    for(int i=1; i<n; i++){
    	// the current max sum is eihter the new element itself or the sum of the current max ( pehle wala)
    	   // and the new element
    	curr_max = max (a[i], curr_max+a[i]);

// updating the actual max sum
    	if(curr_max>max_sum)
    		max_sum=curr_max;

    }


    return max_sum;

}

int main(){
	
	int n;
	cin>>n;
	int a[n];

	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	cout<<maxSubArraySum(a,n)<<endl;



	return 0;
}