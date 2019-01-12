#include<iostream>
using namespace std;

typedef long long ll;
ll mod = 1000000007;

// O(n*n)

ll alpha_score(int a[],int n){

	ll sum[n+1]={0};
	

	for(int i=1; i<n; i++){
		ll s=0;
		int val = a[i];
		for(int j=0; j<n; j++){
			if(a[j]<val){
				s+=a[j];
				s&=mod;
			}
		}
		sum[i]=s;
	}

	ll ans=0;

	for(int i=0; i<=n; i++){
		ans+=sum[i];
		ans%=mod;


	}

	return ans%mod;

}


// O(nlogn)


unsigned long int mergeArrays(unsigned long long int *a, unsigned long long int *left, unsigned long long int *right, int lsize, int rsize, unsigned long long int &total)
{
    int i, j, k;
    i=j=k=0;
    while(i<lsize && j<rsize)
    {
        if(left[i] <= right[j])
        {
            a[k] =  left[i];
            i++;
            k++;

        }
        else
        {
            total = total - left[i];
            a[k] = right[j];
            k++;
            j++;

        }
    }
    while(i<lsize)
    {
        a[k] = left[i];
        k++;
        i++;
    }
    while(j<rsize)
    {
        a[k] = right[j];
        j++;
        k++;
    }
    return total;
}



unsigned long long int mergesort(unsigned long long int *a, int n, unsigned long long int &total)
{

    if(n>1)
    {
        int mid = n/2;
        unsigned long long int left[mid];
        unsigned long long int right[n-mid];
        for(int i=0;i<mid;i++)
        {
            left[i] = a[i];
        }

        for(int i=mid;i<n;i++)
            right[i-mid] = a[i];
        total = mergesort(left, mid, total);
        total = mergesort(right, n-mid, total);
        total = mergeArrays(a, left, right, mid, n-mid, total );
    }
    return total;
}

int main()
{

       
}



int main(){
	int n;
	cin>>n;

	// int a[n];

	// for(int i=0; i<n; i++)
	// 	cin>>a[i];


        unsigned long long int a[n];
        unsigned long long int cumulative[n] = {0};
        unsigned long long int total = 0;
        bool reverseSorted = true;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(i>0)
            {
                if(a[i] > a[i-1])
                    reverseSorted = false;
                cumulative[i] = cumulative[i-1] + a[i-1];
                total += cumulative[i];
            }

        }
        if(reverseSorted)
        {
            cout<<"0";
            return 0;
        }
        //cout<<total<<endl;
        mergesort(a, n, total);
        cout<<(total)%1000000007<<endl;


	//cout<<alpha_score(a,n)<<endl;
}


