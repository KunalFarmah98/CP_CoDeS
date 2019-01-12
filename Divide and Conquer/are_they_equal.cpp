#include<iostream>
using namespace std;

bool are_they_same (string a, string b){

    bool ans1=false,ans2=false;

    int len1 = a.length();
    int len2 = b.length();

//    if(len1%2!=0)
//        return false;

// base case

    if(len1==1)
        return (a==b);

    if(len1%2==0){
    }

    // making 2 halves and recursively calling on them
    string a1 = a.substr(0,len1/2);
    string a2 = a.substr(len1/2,len1-len1/2);

    string b1 = b.substr(0,len2/2);
    string b2 = b.substr(len2/2,len2-len2/2);

    ans1 = are_they_same (a1,b1);

    if(ans1){
        ans2 = are_they_same (a2,b2);

        if(ans2)
            return true;

        else
            return false;
    }
        // if a1 and b1 are not equal, check if a1 and b2 are equal
    else{
        ans2 = are_they_same (a1,b2);
        if(ans2)
            // if a1 is same as b2, then check if a2 is same as b1
            return (ans2==are_they_same (a2,b1));
        else
            return false;
    }


}


int main(){

    int t;
    cin>>t;

    while(t--){
        string a,b;
        cin>>a>>b;

        // if not same length then bhk bc
        if(a.length()!=b.length()){
            cout<<"NO"<<endl;
            continue;
        }

// if they are equal they r equal
        if(a==b){
            cout<<"YES"<<endl;
            continue;
        }

// odd length not allowed
        if(a.length()%2!=0 || b.length()%2!=0){
            cout<<"NO"<<endl;
            continue;
        }

        bool ans = are_they_same (a,b);
        if(ans)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

}