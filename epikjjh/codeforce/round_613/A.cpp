#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,l_c=0,r_c=0;
	string c;
	
	cin >> n;
	cin >> c;
	for(int i=0;i<c.size();i++){
		if(c[i]=='L')	l_c++;
		else	r_c++;
	}
	cout << l_c+r_c+1 << endl;
	return 0;
}