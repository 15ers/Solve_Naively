#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;
vector<int> tmp;
vector<pair<int,int>> ret;

bool seq(){
	ret.resize(2,make_pair(1,1));
	for(int t=0;t<2;t++){
		int s=-1,e=-1;
		for(int i=0;i<n;i++){
			if(arr[i]!=i+1){
				s=i;
				for(int j=i+1;j<n;j++){
					if(arr[j]==i+1){
						e=j;
						break;
					}
				}
				break;
			}
		}
		if(s<0 || e<0)	break;
		ret[t].first = s+1;
		ret[t].second = e+1;
		for(int i=0;i<=(e-s)/2;i++)	swap(arr[s+i],arr[e-i]);
	}
	for(int i=0;i<n;i++)	if(arr[i]!=i+1)	return false;
	return true;
}
bool rev(){
	copy(tmp.begin(),tmp.end(),arr.begin());
	ret.resize(2,make_pair(1,1));
	for(int t=0;t<2;t++){
		int s=-1,e=-1;
		for(int i=n-1;i>=0;i--){
			if(arr[i]!=i+1){
				e=i;
				for(int j=i-1;j>=0;j--){
					if(arr[j]==i+1){
						s=j;
						break;
					}
				}
				break;
			}
		}
		if(s<0 || e<0)	break;
		ret[t].first = s+1;
		ret[t].second = e+1;
		for(int i=0;i<=(e-s)/2;i++)	swap(arr[s+i],arr[e-i]);
	}
	for(int i=0;i<n;i++)	if(arr[i]!=i+1)	return false;
	return true;
}

int main(){
	cin >> n;
	arr.resize(n);
	tmp.resize(n);
	for(int i=0;i<n;i++)	cin >> arr[i];
	copy(arr.begin(),arr.end(),tmp.begin());
	if(seq())	for(auto &p: ret)	cout << p.first << " " << p.second << endl;
	else if(rev())	for(auto &p: ret)	cout << p.first << " " << p.second << endl;
	return 0;
}