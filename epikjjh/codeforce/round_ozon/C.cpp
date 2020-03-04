#include <bits/stdc++.h>

using namespace std;

bool save[1001];
vector<int> v;

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	bool flag = false;
	for (int i=0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		int check=tmp%m;
		if(save[check]){
			cout << 0 << endl;
			flag = true;
		}
		else{
			save[check] = true;
			v.push_back(tmp);
		}
	}
	if(flag)	return 0;
	long long ret = 1;
	for (int i=0;i<v.size();i++){
		for (int j=i+1;j<v.size();j++){
			ret *= abs(v[i]-v[j]);
			ret %= m;
		}
	}	
	cout << ret << endl;
	return 0;
}