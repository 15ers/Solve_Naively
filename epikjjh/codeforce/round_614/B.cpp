#include <bits/stdc++.h>

using namespace std;

const int MAX=100000;

int main(){
	int n;
	double arr[MAX+1];
	arr[1] = 1.0;
	arr[2] = 1.5;
	scanf("%d",&n);
	for(int i=3;i<=n;i++)	arr[i] = 1/(double)i+arr[i-1];
	printf("%lf\n",arr[n]);
	return 0;
}