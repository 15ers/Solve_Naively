#include <iostream>
#include <cstdio>
#include <deque>
#include <string>

using namespace std;

int main(){
	int n;
	deque<int> stack;
	
	cin >> n;
	
	while(n--){
		string stream;
		cin >> stream;
		if(stream=="push"){
			int target;
			cin >> target;
			stack.push_front(target);
		}
		else if(stream=="pop"){
			if(stack.empty())
				cout << -1 << endl;
			else{
				cout << stack[0] << endl;
				stack.pop_front();
			}
		}
		else if(stream=="size"){
			cout << stack.size() << endl;
		}
		else if(stream=="empty"){
			if(stack.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else{
			if(stack.empty())
				cout << -1 << endl;
			else
				cout << stack[0] << endl;
		}
	}
	
	return 0;
}