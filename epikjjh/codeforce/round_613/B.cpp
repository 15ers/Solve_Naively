#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	vector<int> arr;
	while(t--){
		int n;
		scanf("%d",&n);
		arr.resize(n);
		long long s=0;
		bool flag = true;
		for(int i=0;i<n;i++)	scanf("%d",&arr[i]);
		for(auto &i: arr){
			s += i;
			if(s<=0){
				flag = false;
				break;
			}
		}
		s=0;
		for(int i=0;i<n;i++){
			s += arr[i];
			if(s<=0){
				flag = false;
				break;
			}
		}
		s=0;
		for(int i=n-1;i>=0;i--){
			s += arr[i];
			if(s<=0){
				flag = false;
				break;
			}
		}
		if(flag)	printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}