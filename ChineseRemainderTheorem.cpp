#include <iostream>
using namespace std;
long long x,y,GCD=0;

// variable for storing product
long long p=1;

long long gcd(long long a,long long b){
    //Base case
    if(b==0){
        return a;
    }
    //Recursive Case
    return gcd(b,a%b);
}


void extendedEuclid(long long a, long long b){

    // base case, weknow x=1and y=1 here
    if(b==0){
        x=1;
        y=0;
        GCD=a;
        return;
    }

// recursively calling the function to reach base case
    extendedEuclid(b,a%b);

// finding current X and Y in bottom up manner
    long long cX = y;
    long long cY = x-(a/b)*y;

    //updating x and y
    x=cX;
    y=cY;
}


long long multiplicativeModuloInverse(long long a, long long mod){


    if(gcd(a,mod)==1){
        extendedEuclid(a,mod);
        return (x+mod)%mod;
    }

}

void findpp(long long num[],int k, long long pp[]){


    for(int i=0; i<k; i++){
        pp[i] = p/num[i];
    }
}


long long CRT(long long num[], long long rem[], long long pp[],int k){

// making pp aray
    
    findpp(num,k,pp);

    long long inv[k];

// making inverse array
    for(int i=0; i<k; i++){
        inv[i] = multiplicativeModuloInverse(pp[i],num[i]);
    }

    long long ans = 0;
    for(int i=0; i<k; i++){
        ans+=rem[i]*pp[i]*inv[i];
    }

    return ans;

}


int main() {
    int k;
    cin>>k;

    long long num[k];
    long long rem[k];
    long long pp[k] = {1};

    for(int i=0; i<k; i++) {
        cin >> num[i];
    }

    for(int i=0; i<k; i++) {
        cin >> rem[i];
    }

    // finding product of all numbers

    for(int i=0; i<k; i++){

        p=p*num[i];

    }

    long long ans  = CRT(num,rem,pp,k)%p;
    cout<<ans<<endl;
}
