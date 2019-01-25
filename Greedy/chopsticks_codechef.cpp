
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

int main(){
	
     int n,k;
     cin>>n>>k;

     priority_queue<int, vector<int> greater<int> > pq;

     for(int i0; i<n; i++){
     	int x;
     	cin>>x;
     	pq.push(x);
     }

     int c=0;
     while(!pq.empty()){
     	int ch1 = pq.top();
     	pq.pop();
     	int ch2 = pq.top();
     	pq.pop();
     	if(abs(ch1-ch2)<=k)
     		++c;
     }

     cout<<c<<endl;


	return 0;
}