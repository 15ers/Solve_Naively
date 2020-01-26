#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	vector<vector<int>> dic;
	string st;
	
	cin >> n;
	dic.resize(n,vector<int>(26,0));
	cin >> st;
	int s_l = st.size();
	for(int i=0;i<s_l;i++)	dic[0][st[i]-'A']++;
	int ret = 0;
	for(int i=1;i<n;i++){
		string tar;
		cin >> tar;
		int t_l = tar.size();
		int diff=0;
		for(int j=0;j<t_l;j++)	dic[i][tar[j]-'A']++;
		for(int j=0;j<26;j++)	diff += abs(dic[0][j]-dic[i][j]);
		if(diff<=2 && abs(s_l-t_l)<=1)	ret++;
	}
	cout << ret << endl;
	
	return 0;
}