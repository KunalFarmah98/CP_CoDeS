#include <bits/stdc++.h>
using namespace std;

//PRIME SIEVE & OPTIMISATIONS


std::vector<bool> primeSieve(int n){

    std::vector<bool> p(n+1,false);

    p[0] = p[1] = 0;
    p[2] = 1;

    //Let us Mark all Odd Numbers as Prime(Initialisations)
    for(int i=3;i<=n;i+=2){
        p[i] = 1;
    }

    //Sieve Login to mark non prime numbers as 0
    //1. Optimsation : Iterate only over odd Numbers
    for(int i=3;i<=sqrt(n);i+=2){

        if(p[i]){
            //Mark all the multiples of that number as not prime.
            //2. Optimisation Take a jump of 2i starting from i*i
            for(int j=i*i;j<=n;j+=2*i){
                p[j] = 0;
            }
        }

    }
    return p;
}





int main(){


    vector<bool> p = primeSieve(1E8);
    int x;
    cin>>x;

    vector<int> primes;
    primes.push_back(2);

int c = 1;
   for(int i=3; i<1E8; i++){
       if(p[i]){
       primes.push_back(i);
       ++c;
       }
   }
   
  // if(x-1<c)
   cout<<primes[x-1]<<endl;
   
  // else
   
//   cout<<primes[c]<<endl;
    


}
