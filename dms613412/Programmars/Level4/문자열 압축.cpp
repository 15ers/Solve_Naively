#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {
	int answer = INT_MAX;
	int size = s.size();
	if (size == 1)return 1;
	for (int i = size / 2; i > 0; --i) {

		string target = s.substr(0, i);
		string tmp = "";
		int num = 1;
		bool ispossible = true;
		int j = i;
		for (; j + i <= size; j += i) {
			if (target == s.substr(j, i)) {
				++num;
			}
			else {
				if (num == 1) {
					tmp += target;
				}
				else {
					tmp += to_string(num) + target;
				}
				target = s.substr(j, i);
				num = 1;
			}

		}

		if (num == 1) {
			tmp += target;
		}
		else {
			tmp += to_string(num) + target;
		}
		j -= i;
		if (j + i < size) {
			tmp += s.substr(j + i);
		}

		int x = tmp.size();
		answer = min(answer, x);
		//cout<<tmp<<endl;

	}
	return answer;
}