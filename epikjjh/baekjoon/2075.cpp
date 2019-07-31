#include <iostream>
#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
	int n,tmp;
	
	scanf("%d",&n);
	deque<int> arr;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&tmp);
			arr.push_back(tmp);
		}
		if(arr.size()>n){
			sort(arr.begin(),arr.end());
			arr.erase(arr.begin(),arr.begin()+n);
		}
	}
	cout << arr.front() << endl;
	
	return 0;
}