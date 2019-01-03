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
    for(int i=3;i<=n;i+=2){

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


void segmentedseive(long long a, long long b){

    vector<bool> p = primeSieve(10000);



    int range = b-a+1;

    bool prime[range];
    memset(prime,1, sizeof(prime));

    for(long long i = 2; i*i<=b;i++){      // going form 2 to root(b)

        for(long long j = a; j<=b; j++){

            if(p[i]){
                if(j==i)      // if overlapping is there ignore it
                    continue;

                if(j%i==0){         // if number is not prime then set its value to false with shifting
                                    // a ->0.........b->b-a
                                    // shifted by a to left
                    prime[j-a]=0;
                }
            }
        }

    }


    for(int i=a; i<=b; i++){
        if(prime[i-a])
            cout<<i<<endl;
    }


}


int main(){


    int t;

    long long a,b;

    cin>>t;

    while(t>0){
        cin>>a>>b;

        segmentedseive(a,b);
        cout<<endl;
        --t;
    }


}
