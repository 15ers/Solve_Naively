#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	deque<int> arr;
	int n,tmp;
	string s;
	cin >> n;
	while(n--){
		cin >> s;
		if(s=="push_back"){
			cin >> tmp;
			arr.push_back(tmp);
		}
		else if(s=="push_front"){
			cin >> tmp;
			arr.push_front(tmp);
		}
		else if(s=="pop_front"){
			if(!arr.empty()){
				cout << arr.front() << endl;
				arr.pop_front();
			}
			else	cout << -1 << endl;
		}
		else if(s=="pop_back"){
			if(!arr.empty()){
				cout << arr.back() << endl;
				arr.pop_back();
			}
			else 	cout << -1 << endl;
		}
		else if(s=="size")	cout << arr.size() << endl;
		else if(s=="empty"){
			if(arr.empty())	cout << 1 << endl;
			else	 cout << 0 << endl;
		}
		else if(s=="front"){
			if(!arr.empty())	cout << arr.front() << endl;
			else	cout << -1 << endl;
		}
		else if(s=="back"){
			if(!arr.empty())	cout << arr.back() << endl;
			else	cout << -1 << endl;
		}
	}
	
	return 0;
}