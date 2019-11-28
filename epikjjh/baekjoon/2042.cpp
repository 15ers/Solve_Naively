#include <bits/stdc++.h>

using namespace std;

const int SIZE = 2097152;

struct segTree{
	long long tree[SIZE];
	int size,leaf_start;
	segTree(int n): size(n){
		leaf_start = 1;
		while(leaf_start<size)	leaf_start *= 2;
		memset(tree,0,sizeof(tree));
	}
	void build_node(){
		for(int i=leaf_start-1;i>0;i--)	tree[i] = tree[i*2]+tree[i*2+1];
	}
	long long sum(int l, int r){
		return sum(1,l,r,0,leaf_start-1);
	}
	long long sum(int node, int l, int r, int n_l, int n_r){
		if(l<=n_l && n_r<=r)	return tree[node];
		if(r<n_l || n_r<l)	return 0;
		int mid = (n_l+n_r)/2;
		return sum(node*2,l,r,n_l,mid)+sum(node*2+1,l,r,mid+1,n_r);
	}
	void update(int index, long long value){
		int st=leaf_start+index;
		long long diff = value-tree[st];
		while(st>0){
			tree[st] += diff;
			st /= 2;
		}
	}
};

int main(){
	int n,m,k,a,b;
	long long c;
	scanf("%d %d %d", &n, &m, &k);
	segTree st(n);
	for(int i=0;i<n;i++)	scanf("%lld",&st.tree[st.leaf_start+i]);
	st.build_node();
	for(int i=0;i<m+k;i++){
		scanf("%d %d %lld", &a, &b, &c);
		if(a==1)	st.update(b-1,c);
		else		printf("%lld\n",st.sum(b-1,c-1));
	}
	return 0;
}