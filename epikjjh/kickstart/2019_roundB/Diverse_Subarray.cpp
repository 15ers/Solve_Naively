#include <iostream>
#include <cstdio>
#include <map>
#include <deque>
#include <math.h>

using namespace std;

class SegmentTree{
	private:
		int start, end, leaf;
		int *tree, *prefix;
	
	public:
		SegmentTree(int* arr, int n);
		int build_sum(int* arr, int node, int start, int end);
		int build_prefix(int node, int start, int end);
		void update(int index, int diff);
		void update_sum(int node, int start, int end, int index, int diff);
		void update_prefix(int node, int diff);
		int getter();
	
		~SegmentTree(){
			delete[] this->tree;
			delete[] this->prefix;
		}
};
SegmentTree::SegmentTree(int* arr, int n){
	int height = int(ceil(log2(double(n))));
	this->start = 0;
	this->end = n-1;
	this->tree = new int[int(pow(2,(height+1)))]();
	this->prefix = new int[int(pow(2,(height+1)))]();
	this->leaf = -1;
	build_sum(arr, 1, this->start, this->end);
	build_prefix(1, this->start, this->end);
}
int SegmentTree::build_sum(int* arr, int node, int start, int end){
	if(start != end){
		this->tree[node] = build_sum(arr, node*2, start, (start+end)/2) + build_sum(arr, node*2+1, (start+end)/2+1, end);
		return this->tree[node];
	}
	else{
		this->tree[node] = arr[start];
		return this->tree[node];
	}
}
int SegmentTree::build_prefix(int node, int start, int end){
	if(start != end){
		this->prefix[node] = max(build_prefix(node*2, start, (start+end)/2), this->tree[node*2]+build_prefix(node*2+1, (start+end)/2+1, end));
		return this->prefix[node];
	}
	else{
		this->prefix[node] = this->tree[node];
		return this->prefix[node];
	}
}
void SegmentTree::update(int index, int diff){
	update_sum(1, this->start, this->end, index, diff);
	update_prefix(this->leaf, diff);
}
void SegmentTree::update_sum(int node, int start, int end, int index, int diff){
	if(start<=index && index<=end){
		this->tree[node] += diff;
		if(start != end){
			update_sum(node*2, start, (start+end)/2, index, diff);
			update_sum(node*2+1, (start+end)/2+1, end, index, diff);
		}
		else{
			this->leaf = node;
		}
	}
}
void SegmentTree::update_prefix(int node, int diff){
	if(node > 0){
		if(node == this->leaf){
				this->prefix[node] += diff;
		}
		else{
			this->prefix[node] = max(this->prefix[node*2], this->tree[node*2]+this->prefix[node*2+1]);
		}
		update_prefix(node/2, diff);
	}
}
int SegmentTree::getter(){
	return this->prefix[1];
}

int main(){
	int test,ans,n,s;
	
	scanf("%d", &test);
	for(int i=1;i<=test;i++){
		int table[100000]={0,}, arr[100000]={0,};
		map<int,deque<int> > freq;
		
		scanf("%d%d",&n,&s);
		for(int j=0;j<n;j++){
			scanf("%d", table+j);
		}
		for(int j=0;j<n;j++){
			if(freq[table[j]].size()==0){
				freq[table[j]].push_back(1);
				arr[j] = 1;
			}
			else{
				freq[table[j]].push_back(j);
				if(freq[table[j]].size()==s+1){
					arr[j] = -s;
				}
				else if(freq[table[j]].size() > s+1){
					arr[j] = 0;
				}
				else{
					arr[j] = 1;
				}
			}
		}
		SegmentTree seg(arr, n);
		ans = seg.getter();
		for(int j=0;j<n;j++){
			int target = table[j];
			
			for(int k=0;k<freq[target].size();k++){
				int diff;
				
				if(k==0){
					diff = -1;
				}
				else if(k==s){
					diff = s+1;
				}
				else if(k==s+1){
					diff = -s;
				}
				else{
					diff = 0;
				}
				if(diff){
					seg.update(freq[target][k],diff);
				}
			}
			freq[target].erase(freq[target].begin());
			ans = max(ans, seg.getter());
		}
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}