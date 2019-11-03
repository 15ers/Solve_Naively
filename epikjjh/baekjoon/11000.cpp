#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,ret=1;
	cin >> n;
	vector<pair<int, int> > arr(n);
	priority_queue<int,vector<int>,greater<int> > room;  
	
	for(int i=0;i<n;i++) cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(),arr.end());
	room.push(arr[0].second);
	for(int i=1;i<n;i++){
		if(room.top()<=arr[i].first)	room.pop();
		room.push(arr[i].second);
	}
	cout << room.size() << endl;
	
	return 0;
}