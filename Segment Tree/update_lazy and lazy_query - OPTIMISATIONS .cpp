#include <iostream>
#include<climits>
using namespace std;

// SEGMENT TREE FOR MIN BASED RANGE QUERIES


int lazy[1000]={0};

void buildTree(int *a,int s,int e,int *tree,int index){

    // if only one elemet is there, it is the required element
    if(s==e){
        tree[index] = a[s];
        return ;
    }
    
    //Rec case
    int mid = (s+e)/2;
    // building the left tree
    buildTree(a,s,mid,tree,2*index);
    //building the right tree
    buildTree(a,mid+1,e,tree,2*index+1);
    // putting min of left and right subtree in the root
    tree[index] = min(tree[2*index],tree[2*index+1]);
    
    return;
}

int query(int *tree,int ss,int se,int qs,int qe,int index){

    //Complete Overlap
    // if we found the query range directly, simply returns its ans in that index
    if(ss>=qs && se<=qe){
        return tree[index];
    }
    
    //No Overlap
    if(qe<ss || qs>se){
        return INT_MAX;
    }
    
    //Partial Overlap - Call both sides and update the current ans 
    int mid = (ss+se)/2;
    int leftAns = query(tree,ss,mid,qs,qe,2*index);
    int rightAns  = query(tree,mid+1,se,qs,qe,2*index+1);
    // we return the min ans of left and right for the root node
    return min(leftAns,rightAns);
    
}




void updateNode(int *tree,int ss,int se,int i,int increment,int index){

    //Out of bounds - No Overlap
    if(i>se||i<ss){
        return;
    }
    
    //Leaf Node 
    // Leaf node is always updated if we reach there as it will be the element to update 
    if(ss==se){
        tree[index] += increment;
        return;
    }
    
    // if there is a partial overlap, i.e we need to check further for the element
    //Left and Right - Call 
    int mid = (ss+se)/2;
    updateNode(tree,ss,mid,i,increment,2*index);
    updateNode(tree,mid+1,se,i,increment,2*index+1);
    // on going back from leaf to root, we update the value with the min of the updated values
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
}

void updateRange(int *tree,int ss,int se,int l,int r,int inc,int index){
    //Out of bounds 
    if(l>se || r<ss){
        return;
    }
    
    // Leaf Node 
    // every leaf node between the range is updated when we reach it
    if(ss==se){
        tree[index] += inc;
        return;
    }
    // if there is a partial overlap of the range to be updated
    // i.e we need to check further for the element
    // Left and Right  Call Otherwise 
    int mid = (ss+se)/2;
    
    updateRange(tree,ss,mid,l,r,inc,2*index);
    updateRange(tree,mid+1,se,l,r,inc,2*index+1);
    
    tree[index] = min(tree[2*index],tree[2*index+1]);
    return;
    
}



int queryLazy(int *tree,int ss,int se,int qs,int qe,int index){
    // First step - resolve the Lazy value
    // if the current node had a lazy update pending, resolve it first and pass the lazy
    // value to its children ( if any )
    if(lazy[index]!=0){
        tree[index] += lazy[index];
        if(ss!=se){
            lazy[2*index+1]  += lazy[index];
            lazy[2*index] += lazy[index];
        }
        lazy[index] = 0;
    }
    
    
    //No Overlap 
    if(ss>qe || se<qs){
        return INT_MAX;
    }
    
    // Complete Overlap 
    // directly return the value, as lazy value is already resolved beforehand, before this
    // base case hits
    if(ss>=qs && se<=qe){
        
        return tree[index];
    }
    
    
    //Partial same as before
    int mid = (ss+se)/2;
    int left = queryLazy(tree,ss,mid,qs,qe,2*index);
    int right = queryLazy(tree,mid+1,se,qs,qe,2*index+1);
    
    return min(left,right);
    
    
}

void updateRangeLazy(int *tree,int ss,int se,int l,int r,int inc,int index){
    //First Step - Never we go down if you have lazy value at node, first resolve it 
    
    if(lazy[index]!=0){
        
        tree[index] += lazy[index];
        
        //if not a leaf node , pass on the lazy value to the children
        if(ss!=se){
            lazy[2*index] += lazy[index];
            lazy[2*index+1] += lazy[index];
        }
        // make the lazy value as 0 for the current node that is updated now
        lazy[index] = 0;

        // notice that we don't return after this as we merely resolve the lazy update
        // before the base case (complete overlap) hits
    }
    
    // Out of Bounds 
    if(ss>r || l > se){
        return;
    }
    // Complete Overlap- Beeche Raste Mei hi Return krna 
    if(ss>=l && se<=r){
        // update the overlap
        tree[index] += inc;
        
        // Pass the update value to children (pending update) 
        if(ss!=se){
            lazy[2*index] +=  inc;
            lazy[2*index+1] += inc;
        }
        // return, no more work to do (YHA TIME BCHA!!)
    return;
    }
    
    //Call on Left and Right 
    // partial overlap is same as before
    int mid = (ss+se)/2;
    updateRangeLazy(tree,ss,mid,l,r,inc,2*index);
    updateRangeLazy(tree,mid+1,se,l,r,inc,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
    
    return;
    
}


int main() {

    int a[] = {1,3,2,-5,6,4};
    int n = sizeof(a)/sizeof(int);
    
    int *tree = new int[4*n+1];
    
    buildTree(a,0,n-1,tree,1);
    
    //Let print the tree
    for(int i=1;i<=13;i++){
        cout<<tree[i]<<" ";
    }
    
    
    
    //updateNode(tree,0,n-1,2,10,1);
    //updateNode(tree,0,n-1,3,15,1);
   // updateRange(tree,0,n-1,2,4,10,1);
     updateRangeLazy(tree,0,n-1,2,3,10,1);
    
    int no_of_q = 6;
    
    while(no_of_q--){
        int l,r;
        cin>>l>>r;
       // cout<< query(tree,0,n-1,l,r,1)<<endl;
        cout<< queryLazy(tree,0,n-1,l,r,1)<<endl;
    }
    
    
    return 0;
}
