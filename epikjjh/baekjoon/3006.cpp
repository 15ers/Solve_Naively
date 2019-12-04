#include <bits/stdc++.h>

using namespace std;

const int SIZE = 262144;
struct segTree{
	int size,leaf;
	int tree[SIZE];
	
	segTree(int n): size(n){
		leaf = 1;
		while(leaf<size)	leaf *= 2;
		memset(tree,0,sizeof(tree));
		for(int i=0;i<n;i++)	tree[leaf+i] = 1;
		for(int i=leaf-1;i>0;i--)	tree[i] = tree[i*2]+tree[i*2+1];
	}
	void update(int index){
		index += leaf;
		tree[index] = 0;
		index /= 2;
		while(index>0){
			tree[index] = tree[index*2]+tree[index*2+1];
			index /= 2;
		}
	}
	int find(int l, int r){
		return find(1,l,r,0,leaf-1);
	}
	int find(int node, int l, int r, int n_l, int n_r){
		if(l<=n_l && n_r<=r)	return tree[node];
		if(r<n_l || n_r<l)	return 0;
		int mid = (n_l+n_r)/2;
		return find(node*2,l,r,n_l,mid)+find(node*2+1,l,r,mid+1,n_r);
	}
};

int main(){
	int n,tmp;
	scanf("%d",&n);
	segTree st(n);
	vector<pair<int,int> > arr(n);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		arr[i] = make_pair(tmp,i);
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++){
		if(i%2){
			printf("%d\n", st.find(arr[n-1-(i/2)].second,n-1)-1);
			st.update(arr[n-1-(i/2)].second);	
		}
		else{
			printf("%d\n", st.find(0,arr[i/2].second)-1);
			st.update(arr[i/2].second);
		}
	}

	return 0;
}