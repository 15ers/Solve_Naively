#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int age;
	char name[101];
	scanf("%d",&n);
	map<int,vector<string> > arr;
	for(int i=0;i<n;i++){
		scanf("%d %s",&age,name);
		arr[age].push_back(name);
	}
	for(map<int,vector<string> >::iterator it=arr.begin();it!=arr.end();it++){
		for(int i=0;i<(it->second).size();i++)	printf("%d %s\n",it->first,(it->second)[i].c_str());
	}
	
	return 0;
}