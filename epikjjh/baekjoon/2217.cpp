#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	vector<int> rope(n);
	for(int i=0;i<n;i++)	cin >> rope[i];
	sort(rope.begin(),rope.end(),greater<int>());
	int max_weight = rope[0], min_tolerable = rope[0];
	for(int i=1;i<n;i++){
		int tmp = min(min_tolerable,rope[i]);
		if(tmp*(i+1)>max_weight){
			max_weight = tmp*(i+1);
			min_tolerable = min(min_tolerable,rope[i]);
		}
	}
	cout << max_weight << endl;
	
	return 0;
}