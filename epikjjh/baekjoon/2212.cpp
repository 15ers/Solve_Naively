#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,k;
	cin >> n >> k;
	vector<int> sensor(n);
	for(int i=0;i<n;i++)	cin >> sensor[i];
	sort(sensor.begin(),sensor.end());
	vector<int> dist(n-1);
	for(int i=0;i<n-1;i++)	dist[i] = sensor[i+1]-sensor[i];
	sort(dist.begin(),dist.end(),greater<int>());
	long long ret = 0;
	for(int i=0;i<n-1;i++)	if(i>=k-1)	ret += dist[i];	
	cout << ret << endl;
	
	return 0;
}