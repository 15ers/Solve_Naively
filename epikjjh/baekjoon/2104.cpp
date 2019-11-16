#include <bits/stdc++.h>

using namespace std;

int arr[100000] = {0};

long long max_score(int s, int e){
	if(s+1==e)	return (long long)arr[s]*arr[s];
	int mid = (s+e)/2;
	long long ret = max(max_score(s,mid),max_score(mid,e));
	
	int l = mid, r = mid;
	long long sum = arr[mid], min_val = arr[mid];
	while(s<l || r<e-1){
		if(r<e-1 && (l==s||arr[r+1]>arr[l-1])){
			sum += arr[++r];
			min_val = min(min_val,(long long)arr[r]);
		}
		else{
			sum += arr[--l];
			min_val = min(min_val,(long long)arr[l]);
		}
		ret = max(ret,sum*min_val);
	}
	
	return ret;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	for(int i=0;i<n;i++)	cin >> arr[i];
	cout << max_score(0,n) << endl;
	
	return 0;
}