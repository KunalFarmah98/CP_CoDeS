
#include<bits/stdc++.h> 
using namespace std; 

// A Function to calculate Mex of all the values in 
// that set. 
int calculateMex(unordered_set<int> Set) 
{ 
	int Mex = 0; 

	while (Set.find(Mex) != Set.end()) 
		Mex++; 

	return (Mex); 
} 

// A function to Compute Grundy Number of 'n' 
// Only this function varies according to the game 
int calculateGrundy(int n) 
{ 
	if (n == 0) 
		return (0); 
	if (n == 1) 
		return (0); 
	if (n == 2) 
		return (1); 
	if (n == 3) 
		return (2);
    if (n == 4)
        return 2;	
	if (n == 5)
		return 3;

	unordered_set<int> Set; // A Hash Table 

	//if(n>=2)
	Set.insert(calculateGrundy(n - 2)); 
   // if(n>=3)
	Set.insert(calculateGrundy(n - 3)); 
   // if(n>=5)
	Set.insert(calculateGrundy(n - 5)); 

	return (calculateMex(Set)); 
} 



void winner(int n){

  //  if (((calculateGrundy(n-2))^(calculateGrundy(n-3))^(calculateGrundy(n-5)))!=0)
	// in one pile, we just need to calculate grundy number
  if(calculateGrundy(n)!=0)
    	cout<<"First"<<endl;
    else cout <<"Second"<<endl;
}

// Driver program to test above functions 
int main() 
{ 

	int t;
	cin>>t;

	while(t--){
	int n;
	cin>>n;
	winner(n);
}
	return (0); 
} 
