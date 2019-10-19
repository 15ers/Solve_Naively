#include <bits/stdc++.h>

using namespace std;

int count(int* arr){
	int ret=0;
	for(int i=0;i<26;i++)	if(arr[i])	ret++;
	return ret;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,s=0,e=0,ml=0,cnt=0,arr[26]={0};
	string l;
	cin >> n;
	cin >> l;
	while(1){
		if(cnt<=n){	
			ml = max(ml,e-s);
			if(e==l.size())	break;
			else{
				arr[l[e++]-'a']++;
				cnt = count(arr);
			}
		}
		else{
			arr[l[s++]-'a']--;
			cnt = count(arr);
		}
	}
	cout << ml << endl;
	
	return 0;
}