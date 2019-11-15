#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

double ret = INF;
int n;

bool check(vector<int> &visited){
	for(int i=0;i<2*n;i++)	if(!visited[i])	return false;
	return true;
}

void comb(vector<pair<int,int> > &arr, vector<int> &visited, double dist){
	if(check(visited)){
		ret = min(ret,dist);
		return;
	}
	int st_x,st_y,st_ind,tar_x,tar_y;
	for(int i=0;i<2*n;i++){
		if(visited[i])	continue;
		st_x = arr[i].first, st_y = arr[i].second;
		st_ind = i;
		break;
	}
	visited[st_ind] = 1;
	for(int i=0;i<2*n;i++){
		if(visited[i])	continue;
		tar_x = arr[i].first, tar_y = arr[i].second;
		visited[i] = 1;
		double dif_x = st_x-tar_x, dif_y = st_y-tar_y;
		comb(arr,visited,dist+sqrt(dif_x*dif_x+dif_y*dif_y));
		visited[i] = 0;
	}
	visited[st_ind] = 0;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cout << fixed;
	cout.precision(2);
	int t=1;
	cin >> n;
	while(n){
		vector<int> visited(2*n);
		vector<pair<int,int> > arr(2*n);
		string s;
		int x,y;
		for(int i=0;i<2*n;i++){
			cin >> s >> x >> y;
			arr[i].first = x;
			arr[i].second = y;
		}
		comb(arr,visited,0.0);
		cout << "Case " << t << ": " << ret << endl;
		ret = INF;
		cin >> n;
		t++;
	}
	
	return 0;
}