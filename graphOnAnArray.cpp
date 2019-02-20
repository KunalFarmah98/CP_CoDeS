//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}


bool isequal(int a[], int n){
	for(int i = 1; i<n; i++){
		if(a[i]!=a[i-1]){
			return false;
		}
	}

	return true;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;

		int a[n];
		for(int i=0; i<n; i++){
			cin>>a[i];
		}

		list<int> ai;
		// copying all elements in a list ai
		for(int i=0; i<n; i++){
			ai.push_back(a[i]);
		}

		std::vector<int> num;
		list<int> li;

		int c=0;   // if count is 1, we break

		while(!ai.empty()){
			// we keep pushing elements in num which reperesents a connected component
			num.push_back(ai.front());
			ai.pop_front();

			for(int i=0; i<num.size(); i++){
				// checking gcd for all those not yet inserted in num
				while(!ai.empty()){
					int val = ai.front();
					ai.pop_front();

					if(gcd(val,num[i])==1){
						num.push_back(val);
					}

					else{
						li.push_back(val);
					}

				}

				ai=li;   // storing li in ai as we need to check for this now
				
				li.clear();
			}
				++c;  // now  there are more than 1 connected component
			
                num.clear();  // num only stores temporarily

                if(c>1){
                	break;
                }
			}
	

			if(c==1){
				cout<<"0"<<endl;
				for(int i=0; i<n; i++){
					cout<<a[i]<<" ";
				}
				cout<<endl;
			}

			else if(isequal(a,n)){
				if(a[0]==47){
					a[0]=2;
				}
				else{
					a[0]=47;
				}

				cout<<"1"<<endl;
				for(int i=0; i<n; i++){
					cout<<a[i]<<" ";
				}
				cout<<endl;
			}

			else{
				// replacing first number with a prime does the job
				a[0]=47;
				cout<<"1"<<endl;
				for(int i=0; i<n; i++){
					cout<<a[i]<<" ";
				}
				cout<<endl;
			}
		}

	return 0;	
	}




