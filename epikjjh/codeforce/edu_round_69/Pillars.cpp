#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

int main(){
	int n, max_index, max_rad=0, left, right;
	bool check=true;
	
	cin >> n;
	deque<int> arr(n);
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		if(max_rad<arr[i]){
			max_rad = arr[i];
			max_index = i;
		}
	}
	left = max_index - 1;
	right = max_index + 1;
	max_rad--;
	while(max_rad && check){
		if(0<=left && arr[left]==max_rad){
			left--;
			max_rad--;
		}
		else if(right<n && arr[right]==max_rad){
			right++;
			max_rad--;
		}
		else{
			check = false;
		}
	}
	if(check){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	return 0;
}