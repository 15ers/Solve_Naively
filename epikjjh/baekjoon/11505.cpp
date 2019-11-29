#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1048576*2;
const long long MOD = 1000000007;

struct segTree{
	int size,leaf;
	int tree[SIZE];
	segTree(int n): size(n){
		leaf = 1;
		while(size>leaf)	leaf *= 2;
		fill(tree,tree+SIZE,1);
	}
	void build_node(){
		for(int i=leaf-1;i>0;i--)	tree[i] = 1LL*tree[i*2]*tree[i*2+1]%MOD;
	}
	int mul(int l, int r){
		return mul(1,l,r,0,leaf-1);
	}
	int mul(int node, int l, int r, int n_l, int n_r){
		if(l<=n_l && n_r<=r)	return tree[node];
		if(r<n_l || n_r<l)	return 1;
		int mid = (n_l+n_r)/2;
		return 1LL*mul(node*2,l,r,n_l,mid)*mul(node*2+1,l,r,mid+1,n_r)%MOD;
	}
	void update(int index, int val){
		index += leaf;
		tree[index] = val;
		index /= 2;
		while(index>0){
			tree[index] = 1LL*tree[index*2]*tree[index*2+1]%MOD;
			index /= 2;
		}
	}
};

int main(){
	int n,m,k,a,b,c;
	scanf("%d %d %d",&n,&m,&k);
	segTree st(n);
	for(int i=0;i<n;i++)	scanf("%d", &st.tree[st.leaf+i]);
	st.build_node();
	for(int i=0;i<m+k;i++){
		scanf("%d %d %d",&a,&b,&c);
		if(a&1)	st.update(b-1,c);
		else	printf("%d\n",st.mul(b-1,c-1));
	}
	
	return 0;
}