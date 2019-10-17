#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a,b;
	scanf("%d",&n);
	vector<pair<int,int> > arr(n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		arr[i] = make_pair(b,a);
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++)	printf("%d %d\n",arr[i].second,arr[i].first);
	
	return 0;
}