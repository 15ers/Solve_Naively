#include <bits/stdc++.h>

using namespace std;

const int SIZE=131072*2;

struct segTree{
   int size,leaf;
   int tree[SIZE];

   segTree(int n): size(n){    
       leaf=1;
       while(leaf<size) leaf *= 2;
       memset(tree,0,sizeof(tree));
   }
   void build_node(){
       for(int i=leaf-1;i>0;i--)    tree[i] = tree[i*2] * tree[i*2+1];
   }
   int mul(int l, int r){
       return mul(1,l,r,0,leaf-1);
   }
   int mul(int node, int l, int r, int n_l, int n_r){
       if(l<=n_l && n_r<=r) return tree[node];
       if(r<n_l || n_r<l)   return 1;
       int mid = (n_l+n_r)/2;
       return mul(node*2,l,r,n_l,mid) * mul(node*2+1,l,r,mid+1,n_r);
   }
   void update(int index, int val){
       index += leaf;
       if(tree[index]*val<=0){
           if(tree[index]>0 && val<0)   tree[index] = -1;
           else if(tree[index]>0 && val==0) tree[index] = 0;
           else if(tree[index]<0 && val>0)  tree[index] = 1;
           else if(tree[index]<0 && val==0) tree[index] = 0;
           else if(tree[index]==0 && val>0) tree[index] = 1;
           else if(tree[index]==0 && val<0) tree[index] = -1;
           index /= 2;
           while(index>0){
               tree[index] = tree[index*2] * tree[index*2+1];
               index /= 2;
           }
       }
   }
};

int main(){
    int n,k;
    while(scanf("%d %d",&n,&k)!=EOF){
        segTree st(n);
        for(int i=0;i<n;i++){
            int tmp;
            scanf("%d", &tmp);
            if(tmp>0)   st.tree[st.leaf+i] = 1;
            else if(tmp<0)  st.tree[st.leaf+i] = -1;
            else    st.tree[st.leaf+i] = 0;
        }
        st.build_node();
        for(int i=0;i<k;i++){
            char o;
            int l,m;
            getchar();
            scanf("%c", &o);
            scanf("%d %d",&l,&m);
            if(o=='C')  st.update(l-1,m);
            else{
                int ret=st.mul(l-1,m-1);
                if(ret>0)   printf("+");
                else if(ret<0)  printf("-");
                else    printf("0");
            }
        }
        printf("\n");
    }
    return 0;
}
