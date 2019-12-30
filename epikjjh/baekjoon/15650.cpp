#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> arr;
vector<int> is_select(9);

void pprint(int cnt, int cur){
	if(cnt==m){
		for(int i=0;i<arr.size();i++)	printf("%d ",arr[i]);
		printf("\n");
		return;
	}
	for(int i=cur+1;i<=n;i++){
		arr.push_back(i);
		pprint(cnt+1,i);
		arr.pop_back();
	}
}

int main(){
	scanf("%d %d", &n,&m);
	pprint(0,0);
	
	return 0;
}