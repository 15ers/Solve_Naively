#include <bits/stdc++.h>

using namespace std;

const int SIZE=524288*2;
typedef pair<int,int> P;

struct segTree{
    int size,leaf; 
    long long tree[SIZE];
    
    segTree(int n): size(n){
        leaf = 1;
        while(leaf<size)    leaf *= 2;
        memset(tree,0,sizeof(tree));
    }
    long long sum(int l, int r){
        return sum(1,l,r,0,leaf-1);
    }
    long long sum(int node, int l, int r, int n_l, int n_r){
        if(l<=n_l&&n_r<=r)  return tree[node];
        else if(r<n_l || n_r<l) return 0;
        int mid=(n_l+n_r)/2;
        return sum(node*2,l,r,n_l,mid)+sum(node*2+1,l,r,mid+1,n_r);
    }
    void update(int index, int val){
        int ind=leaf+index;
        while(ind>0){
            tree[ind] += val;
            ind /= 2;
        }
    }
};

bool cmp(P &left, P &right){
    if(left.second<right.second)    return true;
    else    return false;
}

int main(){
    int n;
    scanf("%d",&n);
    vector<P> arr(n);
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d", &tmp);
        arr[i] = {i,tmp};
    }
    sort(arr.begin(),arr.end(),cmp);
    segTree st(n);
    vector<int> ret(n);
    for(auto &p: arr){
        int ind=p.first;
        int ans=ind-st.sum(0,ind-1)+1;
        ret[ind] = ans;
        st.update(ind,1);
    }
    for(int &ans: ret)    printf("%d\n",ans);

    return 0;
}
