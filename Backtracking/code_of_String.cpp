#include <bits/stdc++.h>
using namespace std;

char codes[] ={'0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

vector<string>ans;

void codesofstring(char in[], char out[],int i, int j){

    //  vector<string> ans;

    if(in[i]=='\0'){
        out[j]='\0';
        ans.push_back(out);
        return;
    }

    int digit = in[i]-'0';
    out[j] = codes[digit];
    codesofstring(in,out,i+1,j+1);

    if(in[i+1]!='\0') {
        int sum_digit = digit*10 + (in[i + 1] - '0');
        if(sum_digit<=26) {
            out[j] = codes[sum_digit];
            codesofstring(in, out, i + 2, j + 1);
        }
    }



}


int main(){
    char in[100],out[100];
    cin>>in;

    codesofstring(in,out,0,0);

    cout<<"[ ";
    for(int i=0; i<(ans.size()-1);i++){
        cout<<ans[i]<<", ";
    }
    cout<<ans[ans.size()-1]<<" ]";
}