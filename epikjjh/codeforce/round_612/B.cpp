#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	
	scanf("%d %d",&n,&k);
	map<string,int> dic;
	vector<string> arr(n);
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		dic.insert(make_pair(s,i));
		arr[i] = s;
	}
	int ret=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			string tmp="";
			for(int l=0;l<k;l++){
				if(arr[i][l]==arr[j][l])	tmp += arr[i][l];
				else{
					if(arr[i][l]=='S')	tmp += (arr[j][l]=='E') ? "T" : "E";
					else if(arr[i][l]=='E')	tmp += (arr[j][l]=='S') ? "T" : "S";
					else	tmp += (arr[j][l]=='S') ? "E" : "S";
				}
			}
			auto p = dic.find(tmp);
			if(p!=dic.end() && p->second>j)	ret++;
		}
	}
	cout << ret << endl;
	
	return 0;
}