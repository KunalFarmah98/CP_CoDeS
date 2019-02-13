
//KUNAL FARMAH
//@kunalfarmh98@gmail.com

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> primes;

void remove(std::vector<ll> &v)
{
    auto end = v.end();
    for (auto it = v.begin(); it != end; ++it) {
        end = std::remove(it + 1, end, *it);
    }

    v.erase(end, v.end());
}

std::vector<bool> primeSieve(ll n){

    std::vector<bool> p(n+1,false);

    p[0] = p[1] = 0;
    p[2] = 1;

    //Let us Mark all Odd Numbers as Prime(Initialisations)
    for(ll i=3;i<=n;i+=2){
        p[i] = 1;
    }

    //Sieve Login to mark non prime numbers as 0
    //1. Optimsation : Iterate only over odd Numbers
    for(ll i=3;i<=sqrt(n);i+=2){

        if(p[i]){
            //Mark all the multiples of that number as not prime.
            //2. Optimisation Take a jump of 2i starting from i*i
            for(ll j=i*i;j<=n;j+=2*i){
                p[j] = 0;
            }
        }

    }
    return p;
}


vector<ll> prime_numbers(){
    std::vector<bool> p = primeSieve(1E6);
    std::vector<ll> primes;
    primes.push_back(2);

    for(ll i=3; i<1E6; i++){
        if(p[i]){
            primes.push_back(i);
        }
    }
    return primes;
}


unordered_set<ll> divisors(ll n){

    unordered_set<ll> div;
    div.insert(1);

    for (ll i = 0; primes[i]  <= sqrt(n) ; ++i)
    {
        if(n%primes[i]==0){
            ll num = n;
            div.insert(primes[i]);

            while(num){
                num/=primes[i];
                div.insert(num);
            }
        }
    }

    return div;
}

// std::vector<ll> divisors(ll n){

// 	std::vector<ll> div;
// 	div.push_back(1);

// 	if(n==1)
// 		return div;

// 	else {

// 		for (ll i = 2; i * i < n; i++) {
// 			if (n % i == 0) {
// 				div.push_back(i);
// 				if(i!=sqrt(n))
// 				div.push_back(n / i);
// 			}
// 		}


// 		return div;
// 	}
// }

ll calculateMex(unordered_set<ll> Set)
{
    ll Mex = 0;

    while (Set.find(Mex) != Set.end())
        Mex++;

    return (Mex);
}

ll calculateGrundy(ll n){

    // if there are 0 or 1 stones, first player will lose as
    //it can't be reduced A.T.Q

    if (n==0)
        return 0;

    if(n==1)
        return 0;

//    if(n==2)
//        return 0;

    unordered_set<ll> set;

// these are the substates
    unordered_set<ll> divisor = divisors(n);
    ll ans = 0;

    for (auto it = divisor.begin(); it!=divisor.end(); it++)
    {
        // calculating grundy numbers of all states and putting them in a set
        set.insert(calculateGrundy(*it));
    }


    return calculateMex(set);


}





ll winner(ll n,ll m){


 
    if (n%2==0)
        return 0;
    else
        return calculateGrundy(m);



}

int main(){

    primes = prime_numbers();

    ll t;
    cin>>t;

    while(t--){
        ll n,m;
        cin>>n>>m;

        ll ans = winner(n,m);
        if(ans!=0)
            cout<<1<<endl;
        else
            cout<<2<<endl;
    }


    return 0;
}