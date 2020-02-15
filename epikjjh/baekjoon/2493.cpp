#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n),ret(n);
	stack<pair<int,int>> st;
	for(int &p: v)	cin >> p;
	for(int i=n-1;i>=0;i--){
		if(st.empty())	st.push({v[i],i});
		else{
			do{
				if(st.top().first<=v[i]){
					ret[st.top().second] = i+1;
					st.pop();
				}
				else break;
			}while(!st.empty());
			st.push({v[i],i});
		}
	}
	for(int &p: ret)	cout << p << " ";
	cout << endl;
	
	return 0;
}