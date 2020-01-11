#include <bits/stdc++.h>

using namespace std;

int main(){
	int t,n,m,q;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d %d %d",&n,&m,&q);
		vector<bool> bad(n+1);
		while(m--){
			int tmp;
			scanf("%d",&tmp);
			bad[tmp] = true;
		}
		vector<long long> ans(n+1,-1);
		long long total=0;
		while(q--){
			int tar;
			scanf("%d",&tar);
			if(ans[tar]!=-1){
				total += ans[tar];
				continue;
			}
			ans[tar] = 0;
			for(int j=tar;j<=n;j+=tar){
				if(!bad[j])	ans[tar]++;
			}
			total += ans[tar];
		}	
		printf("Case #%d: %lld\n",i,total);
	}

	return 0;
}