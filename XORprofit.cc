#include<bits/stdc++.h>
using namespace std;


//void subsequence(string a, string subs[]){
//
//  int len = a.length();
//
//  for(int i=0; i<(1<<len); i++){
//
//    int no = i;
//    int pos=0;
//    while(no>0){
//      if((no&1)==1)
//        subs[i]= subs[i] + a[pos];
//      pos++;
//      no=no>>1;
//    }
//  }
//}
//
//
//int xorProfit(int x, int y){
//
//
//  string vals;
//  string subsets[]  = {""};
//  priority_queue<int>pq;
//
//  // int diff = abs(x-y);
//
//  for(int i=x; i<=y; i++){
//    stringstream ss;
//    ss<<i;
//    vals+=ss.str();
//  }
//
//
//  subsequence(vals,subsets);
//
//
//
//  // for(int i=1; i<=diff; i++){
//
//  // // generating all subsetsof the sequence
//
//  //   string sub = subsequence(vals,i,diff);
//  //   subsets[i]=sub;
//
//  // }
//
//  int len = sizeof(subsets)/sizeof(string);
//
//  for(int i=0; i<=len; i++){
//    if(subsets[i].length()==2){
//      int op1 = int(subsets[i][0]) - '0';
//      int op2=int(subsets[i][1]) - '0';
//
//      pq.push(op1^op2);
//    }
//  }
//
//
//  return pq.top();
//
//
//}


int main(){
  int x,y;
  cin>>x>>y;
  //cout<<xorProfit(x,y)<<endl;

  priority_queue<int>pq;

  for(int i=x; i<=y; i++){
    for(int j = i; j<=y; j++){
      pq.push(i^j);
    }
  }

  cout<<pq.top()<<endl;
}