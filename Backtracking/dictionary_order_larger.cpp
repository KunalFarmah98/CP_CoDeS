#include <bits/stdc++.h>
#include <sstream>
using namespace std;
string ans[10000];
int ind=0;

void PermutationLexo(string s,string check, int be,int en){

    if(be>en){
        // in base case, if the generated string is greater than our input string, then only take it as ans
            if(s>check){
                ans[ind]=s;
                ind++;
            }
        //cout<<s<<endl;
        //return;
    }
    for(int i=be;i<=en;i++){
        // each element is swapped with the current first element
       swap(s[i],s[be]);
       // cout<<s<<endl;
        PermutationLexo(s,check,be+1,en);
      //  swap(s[i],s[be]);
        //swap(s[i],s[be]);
        //PermutationLexo(s,be+1,en);//BACKTRACKING
    }



}




int main()
{
   // int n;cin>>n;
    //PrintLexo(n,0);
    //sort(s,s+ind);
    //for(int i=0;i<ind;i++){
      //  cout<<s[i]<<" ";
    //}
    string s;
    cin>>s;
    PermutationLexo(s,s,0,s.size()-1);
    for(int i=0;i<ind;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}

