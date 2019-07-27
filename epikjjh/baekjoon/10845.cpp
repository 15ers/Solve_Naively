#include <iostream>
#include <cstdio>
#include <deque>
#include <string>

using namespace std;

int main(){
	int n;
	deque<int> queue;
	cin >> n;
	while(n--){
		string stream;
		
		cin >> stream;
		if(stream=="push"){
			int target;
			
			cin >> target;
			queue.push_back(target);
		}
		else if(stream=="pop"){
			if(queue.empty())
				cout << -1 << endl;
			else{
				cout << queue[0] << endl;
				queue.pop_front();
			}
		}
		else if(stream=="size"){
			cout << queue.size() << endl;
		}
		else if(stream=="empty"){
			if(queue.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if(stream=="front"){
			if(queue.empty())
				cout << -1 << endl;
			else
				cout << queue.front() << endl;
		}
		else{
			if(queue.empty())
				cout << -1 << endl;
			else
				cout << queue.back() << endl;
		}
	}

	return 0;
}