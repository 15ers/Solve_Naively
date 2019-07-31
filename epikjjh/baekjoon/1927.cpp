#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main(){
	int n;
	priority_queue<int, vector<int>, greater<int> > min_heap;
	
	scanf("%d", &n);
	while(n--){
		int tmp;
		scanf("%d", &tmp);
		if(tmp)
			min_heap.push(tmp);
		else{
			if(!min_heap.empty()){
				printf("%d\n",min_heap.top());
				min_heap.pop();
			}
			else
				printf("0\n");
		}
	}
	return 0;
}