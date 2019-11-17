#include <bits/stdc++.h>

using namespace std;

int ret=0;

void z_index(int r, int c, int t_r, int t_c, int s){
	if(t_r==r && t_c==c)	return;
	int d = pow(2,--s);
	for(int i=0;i<4;i++){
		int n_r = r+d*(i/2), n_c = c+d*(i%2);
		if((n_r<=t_r&&t_r<n_r+d) && (n_c<=t_c&&t_c<n_c+d)){
			z_index(n_r,n_c,t_r,t_c,s);
			return;
		}
		else	ret += d*d;
	}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,r,c;
	cin >> n >> r >> c;
	z_index(0,0,r,c,n);
	cout << ret << endl;

	return 0;
}