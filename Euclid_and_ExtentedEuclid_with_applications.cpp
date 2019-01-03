#include <iostream>
using namespace std;

int gcd(int a,int b){
    //Base case
    if(b==0){
        return a;
    }
    //Recursive Case
    return gcd(b,a%b);
}

int lcm(int a,int b){
    
    return a*b/gcd(a,b);
    
}

int x,y,GCD=0;
void extendedEuclid(int a, int b){

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
    int cX = y;
    int cY = x-(a/b)*y;

    //updating x and y
    x=cX;
    y=cY;
}


int multiplicativeModuloInverse(int a, int mod){


 if(gcd(a,mod)==1){
    extendedEuclid(a,mod);
    return (x+mod)%mod;
 }

}

int main() {

    cout<<gcd(10,15)<<endl;
    cout<<gcd(14,10)<<endl;
    
    cout<<lcm(10,15)<<endl;
    cout<<lcm(10,14)<<endl;

// solving 18X+30Y=6
// or 18X+30Y = GCD(18,30)

   extendedEuclid(18,30);
   cout<<x<<" , "<<y<<endl;

   cout<<multiplicativeModuloInverse(6,7)<<endl;
    

    return 0;
}
