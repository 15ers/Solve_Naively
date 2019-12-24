#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		map<string,int> arr;
		string a,b;
		while(n--){
			cin >> a >> b;
			if(arr.find(b)!=arr.end())	arr[b]++;
			else	arr[b] = 1;
		}
		int ret = 1;
		for(map<string,int>::iterator it=arr.begin();it!=arr.end();it++)	ret *= it->second+1;
		cout << ret-1 << endl;
	}
	
	return 0;
}