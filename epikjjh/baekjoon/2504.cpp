#include <bits/stdc++.h>

using namespace std;

int depth[30];

int main(){
	bool flag=true;
	stack<int> st;
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]==')' || s[i]==']'){
			if(!st.empty() && (st.top()=='('||st.top()=='[')){
				if(s[i]==')' && st.top()=='('){
					st.pop();
					int d = st.size();
					if(depth[d+1]){
						depth[d] += depth[d+1]*2;
						depth[d+1] = 0;
					}
					else	depth[d] += 2;
				}
				else if(s[i]==']' && st.top()=='['){
					st.pop();
					int d = st.size();
					if(depth[d+1]){
						depth[d] += depth[d+1]*3;
						depth[d+1] = 0;
					}
					else	depth[d] += 3;
				}
				else{
					flag = false;
					break;
				}
			}
			else{
				flag = false;
				break;
			}
		}
		else	st.push(s[i]);
	}
	if(!st.empty())	flag = false;
	if(flag)	cout << depth[0] << endl;
	else	cout << 0 << endl;
	
	return 0;
}