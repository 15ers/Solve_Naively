#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<int>> adj(n+1);
	priority_queue<int> max_heap;
	priority_queue<int,vector<int>,greater<int>> min_heap;
	vector<int> indegree(n+1),ret_max(n+1),ret_min(n+1);
	for(int i=0;i<n;i++){
		char sign;
		cin >> sign;
		if(sign=='>'){
			adj[i].push_back(i+1);
			indegree[i+1]++;
		}
		else{
			adj[i+1].push_back(i);
			indegree[i]++;
		}
	}
	for(int i=0;i<=n;i++){
		if(!indegree[i]){
			max_heap.push(i);
			min_heap.push(i);
		}
	}
	vector<int> tmp(n+1);
	copy(indegree.begin(),indegree.end(),tmp.begin());
	int cnt=9;
	for(int i=0;i<=n;i++){
		int cur_min = min_heap.top();
		min_heap.pop();
		for(int nxt: adj[cur_min])	if(!(--indegree[nxt]))	min_heap.push(nxt);
		ret_max[cur_min] = cnt--;
	}
	cnt = n;
	copy(tmp.begin(),tmp.end(),indegree.begin());
	for(int i=0;i<=n;i++){
		int cur_max = max_heap.top();
		max_heap.pop();
		for(int nxt: adj[cur_max])	if(!(--indegree[nxt]))	max_heap.push(nxt);
		ret_min[cur_max] = cnt--;	
	}
	for(int i: ret_max)	cout << i;
	cout << endl;
	for(int i: ret_min)	cout << i;
	cout << endl;
	
	return 0;
}