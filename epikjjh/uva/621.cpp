#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	string s;
	cin >> t;
	while(t--){
		cin >> s;
		vector<int> nums(s.size());
		if(s=="1"||s=="4"||s=="78"){
			cout << "+" << endl;
			continue;
		}
		for(int i=0;i<s.size();i++)	nums[i] = s[i]-'0';
		if(nums[s.size()-2]==3&&nums[s.size()-1]==5)	cout << "-" << endl;
		else if(nums[0]==9&&nums[s.size()-1]==4)	cout << "*" << endl;
		else	cout << "?" << endl;
	}
	
	return 0;
}