#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;

int main(){
	int n;
	scanf("%d",&n);
	vector<P> arr(n);
	priority_queue<int,vector<int>,greater<int> > room;  
	
	for(int i=0;i<n;i++) scanf("%d %d",&arr[i].first,&arr[i].second);
	sort(arr.begin(),arr.end());
	room.push(arr[0].second);
	for(int i=1;i<n;i++){
		if(room.top()<=arr[i].first)	room.pop();
		room.push(arr[i].second);
	}
	printf("%d\n",room.size());
	
	return 0;
}
