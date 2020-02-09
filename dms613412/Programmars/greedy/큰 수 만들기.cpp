#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	auto i = number.begin() - 1;
	int size = number.size() - k;
	for (int t = 0; t < size; ++t) {
		i = max_element(i + 1, number.end() - size + t + 1);
		answer += *i;
	}

	return answer;
}