/*
//플로이드 와샬
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer =0;
	vector<vector<int> > graph(n+1,vector<int>(n+1,0));
	for(auto &x:results){
		graph[x[0]][x[1]]=1;
		graph[x[1]][x[0]]=-1;
	}

	for(int j=1; j<=n; ++j){ //i,j위치 주의**
							//i,j 위치가 바뀌면 이미 check한 node값이 update되는 경우가 있으므로 곤란

		for(int i=1; i<=n; ++i){
			if(graph[i][j]==0)continue;
			for(int k=1; k<=n;++k){
				if(graph[i][j] == graph[j][k])
					graph[i][k]=graph[i][j];
			   }
		}
	}

	for(int i=1; i<=n; ++i){
		int cnt = 0;
		for(int j=1; j<=n; ++j){
			if(i==j)continue;
			if(graph[i][j]!=0) ++cnt;
		}
		if(cnt == n-1)
			++answer;
	}

	return answer;
}
*/


//플로이드 와샬
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<bool> > graph(n + 1, vector<bool>(n + 1, false));
	for (auto &x : results) {
		graph[x[0]][x[1]] = true;
	}

	for (int j = 1; j <= n; ++j) {
		for (int i = 1; i <= n; ++i) {
			if (!graph[i][j])continue;
			for (int k = 1; k <= n; ++k) {
				if (graph[i][j] && graph[j][k])
					graph[i][k] = true;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		int cnt = 0;
		for (int j = 1; j <= n; ++j) {
			if (i == j)continue;
			if (graph[i][j] || graph[j][i]) ++cnt;
		}
		if (cnt == n - 1)
			++answer;
	}

	return answer;
}
