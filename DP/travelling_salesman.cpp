
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

int n = 4;
// mask to determine if all are visited, 11111....1
int visited_all = (1<<n)-1;

int memo[16][16];

 int tsp(int dist[][10], int mask, int pos){

// if we visited all adj cities, we return the cost fo going back to the starting city from the last city
   if(mask==visited_all)
   	return dist[pos][0];

   if(memo[mask][pos]!=-1)
   	return memo[mask][pos];

   int ans = INT_MAX;

  // visit all cities adj to the current city
   for(int city=0; city<n; city++){
      // mask for the visiting city
   	   int visited = (1<<city);
 	// check if the city is already visited, if not then visit it and add ans
   	   if((mask&visited)==0){
   	   	// cost = cost from going from begining to the current city 
   	   	//+ cost of visiting other cities down the tree

   	   	// the new mask is the old mask OR visited mask, to get the current mask
   	   	  int res = dist[pos][city] + tsp(dist, mask|visited , city);
   	   	  
   	   	  // we take min ans
   	   	  ans = min(ans,res);
   	   }
   }


   return memo[mask][pos] = ans;



 }




int main(){
   
   //cin>>n;

   int dist[10][10]={
   	{0,20,42,25},
   	{20,0,30,34},
   	{42,30,0,10},
   	{25,34,10,0}
   };

   //memset(memo,-1,sizeof(memo));
   for(int i=0; i<(1<<n); i++){
   	for(int j=0; j<n; j++)
   		memo[i][j]=-1;
   }

  // we take first city as the start point , hence its mask == 0000...1, i.e 1
      cout<<tsp(dist,1,0)<<endl;



	return 0;
}