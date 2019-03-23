
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
int n,k;

ld dist[50][50];

ld memo[2<<13][50];

vector<pair<int,int> > coordinates;
	vector<int> ingredients;

ld calc_distance(pair<int,int> a, pair<int,int> b){

	ld distance = 0;

	distance = ((a.first - b.first)*(a.first - b.first)) +
			((a.second - b.second)*(a.second - b.second));

	             return sqrt(distance);
}

ld shopTrip(int mask, int ind){

	// if we collected all ,return to the kitchen
	if(mask == (1<<k)-1)
		return dist[ind][0];

	if(memo[mask][ind]!=-1)
		return memo[mask][ind];

	memo[mask][ind] = INT_MAX;
	for(int i=0; i<=n; i++){
		if(mask|ingredients[i]!=mask){ // if we get something new for the next shop

		//visit that shop from ind and collect
 			memo[mask][ind] = min(memo[mask][ind], dist[ind][i] + shopTrip((mask|ingredients[i]), i));

		}
	}

	return memo[mask][ind];
}


int main(){
	int t;
	cin>>t;
	while(t--){

		memset(dist,0,sizeof(dist));
		memset(memo,-1,sizeof(memo));

		coordinates.clear();
		ingredients.clear();


		cin>>n>>k;

		coordinates.push_back(make_pair(0,0));

		for(int i = 0; i<n; i++){
			int x, y;
			cin>>x>>y;
			coordinates.push_back(make_pair(x,y));
		}


		int possible = 0;

		// taking ingredient string

       ingredients.push_back(0);
		for(int i = 0; i<n; i++){
			string S;
			cin>>S;

			reverse(S.begin(), S.end());  // reversing S so that bitmasking is easier
			int temp_mask=0;
			// converting S to an integer
			for(int j=0; j<S.size(); j++){
				// creating a mask and multiplying with the integer equivalent of the letter
				temp_mask |= (1<<j)*(S[j]-'0');
			}
			// making a list of all possible ingredients we can get by all shops
			possible |= temp_mask;
			ingredients.push_back(temp_mask);
		}


		int ALL = (1<<k) - 1;


 // if we can't get all ingredients, then simply skip the case
		if(possible!=ALL){
			cout<<-1<<endl;
			continue;
		}

		// calculating distance matrix

		// there are n+1 shops as we inclide kitchen in it
		for(int i=0; i<=n; i++){
			for(int j=0; j<=n; j++){
				dist[i][j] = calc_distance(coordinates[i],coordinates[j]);
			}
		}

		for(int i=0; i<(1<<k); i++){
			for(int j=0; j<=n; j++)
				memo[i][j]=-1;
		}

// initial mask =0 ,and we start from kitchen
		cout<<fixed<<setprecision(10)<<shopTrip(0,0)<<endl;   
	}



	return 0;
}