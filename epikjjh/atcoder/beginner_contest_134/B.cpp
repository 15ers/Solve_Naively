#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	int n,d;
	double ans;
	
	cin >> n >> d;
	ans = n/double((2*d+1));
	cout << int(ceil(ans)) << endl;
	
	return 0;
}