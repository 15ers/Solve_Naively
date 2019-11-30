#include <bits/stdc++.h>

using namespace std;
const int SIZE = 1048576*2;

struct segTree{
	int size,leaf;
	long long tree[SIZE];
	segTree(int n): size(n){
		leaf = 1;
		while(leaf<size)	leaf *= 2;
		memset(tree,0,sizeof(tree));
	}
	void update(int index, int val){
		index += leaf;
		while(index>0){
			tree[index] += val;
			index /= 2;
		}
	}
	long long sum(int l, int r){
		return sum(1,l,r,0,leaf-1);
	}
	long long sum(int node, int l, int r, int n_l, int n_r){
		if(l<=n_l && n_r<=r)	return tree[node];
		if(r<n_l || n_r<l)	return 0;
		int mid = (n_l+n_r)/2;
		return sum(node*2,l,r,n_l,mid)+sum(node*2+1,l,r,mid+1,n_r);
	}
};

int main(){
	int n,q,a,b,c;
	scanf("%d %d", &n, &q);
	segTree st(n);
	while(q--){
		scanf("%d %d %d", &a, &b, &c);
		if(a&1)	st.update(b-1,c);
		else	printf("%lld\n", st.sum(b-1,c-1));
	}
	
	return 0;
}