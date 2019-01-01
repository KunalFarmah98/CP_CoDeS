#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int rightmostbit(int res){

    int ans=0;
    int pos = 0;

    while(res) {

       if (res & 1) {
       ans = pos;
       break;
   }
       else{
           res<<1;
           pos++;
       }
   }

    return  ans;

}


int main() {


    priority_queue<int,vector<int>,greater<int> > min;

	int n;
	cin>>n;

	int a[n];

	for(int i=0; i<n; i++)
	cin>>a[i];


	int res = 0;


	for(int i=0; i<n; i++)
	res=res^a[i];


	int pos = rightmostbit(res);


	int mask =  1<<pos;


	int first=0;

	for(int i=0; i<n; i++){
	    if(a[i]&mask==1)
	    first=first^a[i];
	}


	int second = first^res;

    min.push(first);
    min.push(second);

    while(!min.empty()){
        cout<<min.top()<<" ";
        min.pop();
    }



}