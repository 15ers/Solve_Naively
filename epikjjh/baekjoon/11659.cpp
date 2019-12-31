#include <bits/stdc++.h>

using namespace std;

const int SIZE = 131072*2;

struct segTree{
	long long tree[SIZE];
	int leaf; 
	
	segTree(){
		leaf=SIZE/2;
		memset(tree,0,sizeof(tree));
	}
	
	void build_node(){
		for(int i=leaf-1;i>0;i--)	tree[i] = tree[i*2]+tree[i*2+1];
	}
	
	long long find(int l, int r){
		return find(1,0,leaf-1,l,r);
	}
	long long find(int node, int n_l, int n_r, int l, int r){
		if(l<=n_l && n_r<=r)	return tree[node];
		if(r<n_l || n_r<l)	return 0;
		int mid = (n_l+n_r)/2;
		return find(node*2,n_l,mid,l,r)+find(node*2+1,mid+1,n_r,l,r);
	}
};

int main(){
	int n,m,a,b;
	segTree st;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)	scanf("%lld", &st.tree[st.leaf+i]);
	st.build_node();
	for(int i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		printf("%lld\n", st.find(a-1,b-1));
	}
	
	return 0;
}