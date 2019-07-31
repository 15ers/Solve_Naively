#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main(){
	int t;
	priority_queue<int, vector<int>, greater<int> > min_heap;
	priority_queue<int, vector<int>, less<int> > max_heap;
	
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		if(min_heap.size()==max_heap.size()-1)
			min_heap.push(n);
		else
			max_heap.push(n);
		if(!max_heap.empty()&&!min_heap.empty()){
			if(max_heap.top()>min_heap.top()){
				int tmp_max = max_heap.top();
				int tmp_min = min_heap.top();
				max_heap.pop();
				min_heap.pop();
				max_heap.push(tmp_min);
				min_heap.push(tmp_max);
			}
		}
		printf("%d\n",max_heap.top());
	}
	return 0;
}