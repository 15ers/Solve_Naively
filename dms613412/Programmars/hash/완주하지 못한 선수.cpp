#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	map <string, int> p;

	for (auto &i : completion) {
		if (p.find(i) == p.end())
			p[i] = 1;
		else
			++p[i];
	}


	for (auto &j : participant) {
		if (p.find(j) == p.end() || p[j] == 0)
			return j;
		else
			--p[j];
	}

	string answer = "";
	return answer;
}