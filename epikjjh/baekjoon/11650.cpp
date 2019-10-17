#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a,b;
	scanf("%d",&n);
	vector<pair<int,int> > arr(n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		arr[i] = make_pair(a,b);
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++)	printf("%d %d\n",arr[i].first,arr[i].second);
	
	return 0;
}