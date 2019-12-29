#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m,ret=0;
	cin >> n >> m;
	deque<int> arr(m),st;
	for(int i=1;i<=n;i++)	st.push_back(i);
	for(int i=0;i<m;i++){
		int tmp,id;
		cin >> tmp;
		for(int i=0;i<st.size();i++){
			if(st[i]==tmp){
				id = i;
				break;
			}
		}
		if(id<st.size()-id){
			ret += id;
			while(id--){
				int r = st[0];
				for(int i=1;i<st.size();i++)	st[i-1] = st[i];
				st[st.size()-1] = r;
			}
			st.pop_front();
		}
		else{
			id = st.size()-id;
			ret += id;
			while(id--){
				int l = st[st.size()-1];
				for(int i=st.size()-1;i>0;i--)	st[i] = st[i-1];
				st[0] = l;
			}
			st.pop_front();
		}
	}
	cout << ret << endl;
	
	return 0;
}