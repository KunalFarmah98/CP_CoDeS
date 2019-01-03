#include <iostream>
using namespace std;

// finding factorial with modulo

long long factmodp(int r, int p){
    long long fact=1;
    for(int i= r; i>=1; --i){
        fact*=i;
        fact%=p;
    }

    return fact % p;
}

long long power(long long x, long long y, long long p)
{
    long long res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}



// calculating inverse modulo of r

long long calcinvmodp(int r, long long p){

    long long a = factmodp(r,p);
    return (power(a,p-2,p));


}

long long viratncr(int n, int r, long long p){

long long  numerator=1;

// multiplying till r if r is greater or else till n-r
        for(int i=n; i>max(r,n-r); i--){
            numerator*=i;
            numerator%=p;
        }

// neeche wale ka mod p liya
    long long  denominator  = calcinvmodp(min(r,n-r),p);


    return (numerator % p)*(denominator % p);

}





int main() {

  int n,r;
  cin>>n>>r;

  cout<< viratncr(n,r,1000000007)<<endl;
}
