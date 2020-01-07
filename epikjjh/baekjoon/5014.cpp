#include <bits/stdc++.h>

using namespace std;

int main(){
	int f,s,g,u,d;
	bool visited[1000001] = {0};
	queue<int> q;
	
	cin >> f >> s >> g >> u >> d;
	q.push(s);
	visited[s] = true;
	int ret = 0;
	bool flag = false;
	while(!q.empty()){
		int s = q.size();
		for(int i=0;i<s;i++){
			int cur = q.front();
			q.pop();
			if(cur==g){
				cout << ret << endl;
				flag = true;
				break;
			}
			int nxt_up = cur+u;
			int nxt_down = cur-d;
			if(1<=nxt_up&&nxt_up<=f &&!visited[nxt_up]){
				visited[nxt_up] = true;
				q.push(nxt_up);
			}
			if(1<=nxt_down&&nxt_down<=f &&!visited[nxt_down]){
				visited[nxt_down] = true;
				q.push(nxt_down);
			}
		}
		if(flag)	break;
		ret++;
	}
	if(!visited[g])	cout << "use the stairs" << endl;

	return 0;
}