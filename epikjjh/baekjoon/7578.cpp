#include <bits/stdc++.h>

using namespace std;

const int SIZE=524288*2;

int num[1000001];

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
        if(l<=n_l && n_r<=r)    return tree[node];
        if(r<n_l || n_r<l)  return 0;
        int mid=(n_l+n_r)/2;
        return sum(node*2,l,r,n_l,mid)+sum(node*2+1,l,r,mid+1,n_r);
    }
    void update(int index, long long value){
        int st=leaf+index;
        long long diff=value-tree[st];
        while(st>0){
            tree[st] += diff;
            st /= 2;
        }
    }
};

int main(){
    int n,m;
    scanf("%d", &n);
    vector<int> arr(n);
    segTree st(n);
    for(int i=0;i<n;i++){
        scanf("%d", &m);
        num[m] = i;
    }
    for(int i=0;i<n;i++){
        scanf("%d", &m);
        arr[num[m]] = i;
    }
    long long ret=0;
    for(int i=0;i<n;i++){
        int ind=arr[i];
        ret += st.sum(ind+1,n-1);
        st.update(ind, 1);
    }
    printf("%lld\n", ret);
    return 0;
}
