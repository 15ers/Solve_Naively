#include <bits/stdc++.h>
 
using namespace std;
 
int arrn[40001];
int arrm[40001];
int numn[40001];
int numm[40001];
 
int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++)	scanf("%d",&arrn[i]);
	for(int i=1;i<=m;i++)	scanf("%d",&arrm[i]);
	int cnt=0;
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(!arrn[i]){
			if(cnt)	q.push(cnt);
			cnt=0;
		}
		else	cnt++;
	}
	if(cnt)	q.push(cnt);
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		for(int i=cur;i>=1;i--)	numn[i] += cur-i+1;
	}
	cnt=0;
	for(int i=1;i<=m;i++){
		if(!arrm[i]){
			if(cnt)	q.push(cnt);
			cnt=0;
		}
		else	cnt++;
	}
	if(cnt)	q.push(cnt);
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		for(int i=cur;i>=1;i--)	numm[i] += cur-i+1;
	}
	long long ret=0;
	int mid = int(sqrt(k));
	for(int i=1;i<=mid;i++){
		if(i>40000 || k/i>40000)	continue;
		if(k%i==0){
			ret += 1LL*numn[i]*numm[k/i];
			if(i!=k/i)	ret += 1LL*numn[k/i]*numm[i];
		}
	}
	printf("%lld\n",ret);
	return 0;
}
