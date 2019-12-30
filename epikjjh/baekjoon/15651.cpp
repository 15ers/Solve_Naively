#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> arr;

void pprint(int cnt){
	if(cnt==m){
		for(int i=0;i<arr.size();i++)	printf("%d ",arr[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++){
		arr.push_back(i);
		pprint(cnt+1);
		arr.pop_back();
	}
}

int main(){
	scanf("%d %d",&n,&m);
	pprint(0);
	
	return 0;
}