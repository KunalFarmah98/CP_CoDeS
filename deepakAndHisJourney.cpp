
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;


int min_index(int a[], int b,int e){
	int min_index=0;
	int min = INT_MAX;

	for(int i=b;i<e;i++){
		if(a[i]<min){
			min_index = i;
			min = a[i];
		}
	}

	return min_index;
}

int minCost(int n, int L[], int C[]){

	// he has to reach the first checkpoint
	int cost =0;

// finding the checkpoint with least cost to fill the tank
	int minCostIndex = min_index(C,0,n);

// find the min cost checkpoint in the way to reach the min checkpoint
	int minCostmidIndex = min_index(C,0,minCostIndex);

// reach that middle checkpoint from the first checkpoint
	for(int i=0;i<minCostmidIndex;i++){
		cost+=C[i]*L[i];
	}
// calculate the required amount of petrol to reach the min checkpoint
	int required = 0;
	for(int i=minCostmidIndex; i<minCostIndex; i++){
		required+=L[i];
	}
// fill the tank completely at the minimun cost middle checkpoint;
	cost+=required*C[minCostmidIndex];

	// calculate the required amount of petrol to reach the end from the min checkpoint
	required = 0;
	for(int i=minCostIndex; i<n; i++){
		required+=L[i];
	}

	cost+=required*C[minCostIndex];

	return cost;



}

int main(){

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		int L[n],C[n];



		for(int i=0; i<n; i++){
			cin>>C[i];
		}

		for(int i=0; i<n; i++){
			cin>>L[i];
		}


		cout<<minCost(n,L,C)<<endl;

	}



	return 0;
}