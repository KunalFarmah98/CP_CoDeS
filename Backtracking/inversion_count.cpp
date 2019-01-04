#include<iostream>
using namespace std;

int ans=0;
int merge(int a[], int s, int mid, int e){

	int l[mid-s+1];
	int r[e-mid];

	for(int i=0; i<mid-s+1; i++){
		l[i]=a[s+i];
	}

	for(int j=0;j<e-mid; j++){
		r[j]=a[mid+j+1];
	}

	int i = 0;
	int j = 0;
	int k= s;

	while(i<mid-s+1 && j<e-mid){
		if(l[i]>r[j]){
			ans+=mid-k+1;
			a[k]=r[j];
			++k;++j;
		}

	else{
			a[k]=l[i];
			++k;++i;
		}

}

while(i<mid-s+1){
		a[k]=l[i];
		++k;++i;
	}

	while(j<e-mid){
		a[k]=r[j];
		++k;++j;
	}
         return ans;
}

int merge_sort(int a[], int s, int e){

	if(s>=e)
		return 0;    // there is no inversion count in one element array

	int mid = (s+e)/2;
	//return merge_sort(a,s,mid)+merge_sort(a,mid+1,e)+merge(a,s,mid,e);

	int leftAns = merge_sort(a,s,mid);
	int rightAns = merge_sort(a,mid+1,e);
	int crossAns = merge(a,s,mid,e);

	return leftAns+rightAns+crossAns;
}

int inversion_count(int a[],int n){
	return merge_sort(a,0,n-1);
}



int main(){
	int n;
	cin>>n;
	int a[n];

	//int temp[n];
	for(int i=0; i<n; i++)
		cin>>a[i];

	cout<<inversion_count(a,n)<<endl;

}