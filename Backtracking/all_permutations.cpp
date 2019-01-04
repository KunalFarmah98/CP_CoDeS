#include<iostream>
using namespace std;

void permute(char* in, int i){

// if there's nothing to permute, just print input string
	if(in[i]=='\0'){
		cout<<in<<" ";
		return;
	}

	// start j from i and iterate till the end of the input array and swap and call recusion

	for(int j=i; in[j]!='\0'; j++){
		swap(in[i],in[j]);
		permute(in,i+1);
		// backtracking and undoing the swap while going up
		swap(in[j],in[i]);
	}


}


int main(){
	char in[100] ;
	cin>>in;

	permute(in,0);
}