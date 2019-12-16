#include <bits/stdc++.h>

using namespace std;

const int SIZE = 1048576;

struct segTree{
	int leaf;
	int tree[SIZE*2];
	
	segTree(){
		leaf = SIZE;
		memset(tree,0,sizeof(tree));
	}
	void update(int index, int value){
		index += leaf;
		tree[index] += value;
		index /= 2;
		while(index>0){
			tree[index] = tree[index*2]+tree[index*2+1];
			index /= 2;
		}
	}
	int find(int num){
		return find(1,0,leaf-1,num);
	}
	int find(int node, int start, int end, int num){
		if(start==end)	return start;
		
		int mid = (start+end)/2;
		if(tree[node*2]>=num)	return find(node*2,start,mid,num);
		else	return find(node*2+1,mid+1,end,num-tree[node*2]);
	}
	
};

int main(){
	int n,a,b,c;
	segTree st;
	
	scanf("%d", &n);
	while(n--){
		scanf("%d", &a);
		if(a>>1){
			scanf("%d %d", &b, &c);
			st.update(b-1,c);
		}
		else{
			scanf("%d", &b);
			int ind = st.find(b);
			printf("%d\n",ind+1);
			st.update(ind,-1);
		}
	}
	
	return 0;
}