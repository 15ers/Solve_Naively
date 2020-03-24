#include <bits/stdc++.h>

using namespace std;

bool visited[1000001];

int main(){
	int f,s,g,u,d;
    scanf("%d %d %d %d %d",&f,&s,&g,&u,&d);
	queue<int> q;
	q.push(s);
	visited[s] = true;
	int ret = 0;
	while(!q.empty()){
		int t = q.size();
		for(int i=0;i<t;i++){
			int c = q.front();
			q.pop();
			if(c==g){
                printf("%d\n",ret);
                return 0;
			}
			int nu = c+u;
			int nd = c-d;
			if(1<=nu&&nu<=f && !visited[nu]){
				visited[nu] = true;
				q.push(nu);
			}
			if(1<=nd&&nd<=f && !visited[nd]){
				visited[nd] = true;
				q.push(nd);
			}
		}
		ret++;
	}
    printf("use the stairs\n");

	return 0;
}
