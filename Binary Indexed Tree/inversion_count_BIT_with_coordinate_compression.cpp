 #include <iostream>
using namespace std;

// THIS IS A CATEGORY OF POINT UPDATE AND RANGE QUERY
// Updating the BIT index calue by one automatically increases the inversion count of that element

// NOTE:
// THIS METHOD WILL FAIL IN CASE OF NEGATIVE NUMBERS
// IF RANGE IS LARGE, IT TAKES MORE AUXILIARY SPACE AS BIT ARRAY NEEDS TO HAVE EACH ELEMENT 
// AS INDEX

int BIT[10000] = {0};

void update(int index, int n, int inc){
    // updating the required index and then only updating where that range exists (next power of 2 index)
    // given by i+(i&-i)
    // also setting the max as the new max 
    while(index<=n){
        BIT[index]+=inc;
        index+=(index&(-index));
    }
}

void build(int a[], int n){
    // building is similar to updating all indices of a 0 initialised BIT 
    //with inc equal to the original array
    for(int i=1; i<=n; i++){
    update(i,n,a[i]);
     }
}

int query(int i){
    int ans=0;
    // going back from one index to the next index with the last set bit removed till 0
    while(i>0){
        ans+=BIT[i];
        i-=(i&(-i));
    }

    return ans;
}

int main() {
     int n;
    cin>>n;

    set<int> arrayset;

    int a[n];
    int arr[i];

    // using coordinate compression to make sure it doesn't fail in cases of negative
    // values and takes less space.

    for(int i=0; i<n; i++){
        cin>>a[i];
        arrayset.insert(a[i]);
    }

    map<int,int> indexmapping;

    int i=1;
    auto it = arrayset.begin();
    for(; it!=arrayset.end(); it++,i++){

        indexmapping.insert(make_pair(*it,i));
    }

    for(int i=0;i<n;i++){
        // auto val = indexmapping[a[i]];
        // cout<<val->first<<" ";
        int val = indexmapping.find(a[i])->second;
        arr[i]=val;
    }


     // this logic acts similar to maintaining a cumulative count array for the given array but
     // in O(log n) as BIT takes log n for a query
   
   int ans=0;
   for(int i=n; i>=1; i--){
    // when we reach an element , we increase its frequency by 1
    // to check the elements that are smaller than n from after that index i.e the case of inversion count,
    // we simply query at the value at element - 1, which will have the freqency
    // of the elements smaller than it
    ans+=query(arr[i]-1);
    // Updating the BIT with an increment of 1 will take care of the logic of inversion count
    // as it will automatically update the frequency stored in higher indices which will act as
    // count of elements greater then it.
    update(arr[i],n,1);  // this increases the frequency of that element
   }

   cout<<ans;

    return 0;
}



