#include <iostream>
#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
	int n, largest, exception, largest_index;
	
	cin >> n;
	deque<int> arr(n);
	
	for(int i=0;i<n;i++)
		cin >> arr[i];
	deque<int> tmp(arr);
	sort(tmp.begin(), tmp.end());
	largest = tmp[n-1];
	exception = tmp[n-2];
	
	for(int i=0;i<n;i++){
		if(arr[i]==largest){
			largest_index = i;
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(i==largest_index){
			cout << exception << endl;
		}
		else{
			cout << largest << endl;
		}
	}
		
	
	return 0;
}