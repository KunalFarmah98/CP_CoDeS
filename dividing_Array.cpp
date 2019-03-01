/*DIVIDING ARRAY
You are given an array, A, of n elements. You have to remove exactly n/2 elements from array A, and add it to another array B(initially empty). After these operations, you can rearrange the elements of both the arrays in any order. We define, difference between these two arrays as :

∑ i = 1 N / 2 a b s ( A i − B i )
Find the maximum and minimum values of differences of these two arrays.

Input Format:
First Line contains number of test cases, T. For each test case, first line contains a single integer, n (n is even). Next line contains n integers, denoting the elements f array, A.

Constraints:
1<=T<=10 1<=n<=10^5 |Ai|<=10^9

Output Format
For each test case, print the minimum and maximum value of differences between two arrays.

Sample Input
1
4
12 -3 10 0
Sample Output
5 25*/




#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        ll a[n];
        for (ll i = 0; i < n; i++) {
            cin >> a[i];

        }

        sort(a, a + n);

        ll maxb[n / 2] = {0};
        ll k = 0;
        for (ll i = n-1; i >=n/2; i--) {
            maxb[k] = a[i];
            ++k;
            if(k==n/2)
                break;
        }

        // max difference if when min element is subtracted from maximum second min from second max and so on
        // maxdiff = Sum_from_0_to_n/2(A[i+n/2]-A[i])

        sort(maxb,maxb+n/2,greater<int>());

        // for (int i = 0; i < n / 2; i++)
        //     cout << maxb[i] << " ";

        ll maxdif = 0;
        ll j = 0;
        for (ll i = 0; i < n / 2; i++) {
            maxdif += abs(a[i] - maxb[j]);
            ++j;
        }


        // min diffence is alternating difference, i.e min and max ,second min and second max clubbed together in b
        // to be subtracted from remaining in a

        // min diff = Sum_from_0_to_n/2(A[2*i+1]-A[2*i]);

        ll mindiff=0;

        for(int i=0; i<n/2; i++){
            mindiff+=abs(a[2*i+1]-a[2*i]);
        }


        cout << mindiff << " " << maxdif << endl;
    }
}
