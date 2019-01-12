#include <bits/stdc++.h>
using namespace std;

// Square Root Decomposition 
// Range Sum Query

int query(int *blocks,int *arr,int l,int r,int rn){
    
    int ans = 0;

    // if our L is not a boundary of a block, iterate till the next boundary index and keep on adding
    
    //Left Part 
    while(l<r && l!=0 && l%rn!=0){
        ans += arr[l];
        l++;
    }
    
    // if L is a boundary index, i.e some part of the ans of the range lies inside the blocks, just take 
    // ans of that block, and keep updating block index by adding root(n) to l as that changes the block
    
    //Middle Part
    while(l + rn<=r){
        int block_id = l/rn;
        ans += blocks[block_id];
        l += rn;
    }

    // if R is not a boundary of a block, iterate till the next boundary and add
    
    //Right Part 
    while(l<=r){
        ans += arr[l];
        l++;
    }
    return ans;
    
}

void update(int *blocks,int *arr,int i,int val,int rn){
    // simply find the block index of that element and update the sum by removing
    // the old value and adding the new value
    
    int block_id = i/rn;
    
    blocks[block_id] += (val - arr[i]);
    arr[i] = val;
}

int main() {
    
    int a[] = {1,3,5,2,7,6,3,1,4,8};
    int n = sizeof(a)/sizeof(int);
    
    int rn = sqrt(n);
    int *blocks = new int[rn+1]{0};
    
    // Build a Blocks Array
    int block_id = -1;
    for(int i=0;i<n;i++){
        // if we hit a multiple of root(n), we change the block and and start adding into the new block
        if(i%rn==0){
            block_id++;
        }
        // adding eleemts and getting ans for each block
        blocks[block_id] += a[i];
    }
    
    // Queries
    int l,r;
    cin>>l>>r;
    update(blocks,a,2,15,rn);
    cout<<query(blocks,a,l,r,rn);


}
