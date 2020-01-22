/*
//내림차순 정렬
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>  
using namespace std;

int visited[10000] = { 0, };
vector<string> answer, tmp;
int size;

void dfs(int num, string word, vector<vector<string>> &tickets) {
	tmp.push_back(word);

	if (num == size) {
		answer = tmp;
		tmp.pop_back();
		return;
	}

	for (int i = 0; i < size; ++i) {
		if (visited[i])continue;
		if (word == tickets[i][0]) {
			visited[i] = 1;
			dfs(num + 1, tickets[i][1], tickets);
			visited[i] = 0;
		}
	}
	tmp.pop_back();
}

bool comp(vector<string> a, vector<string> b) {
	if (a[0].compare(b[0]) < 0) {
		return false;
	}
	else if (a[0].compare(b[0]) > 0) {
		return true;
	}
	else {
		if (a[1].compare(b[1]) < 0) {
			return false;
		}
		else if (a[1].compare(b[1]) > 0) {
			return true;
		}
	}
	return true;
}

vector<string> solution(vector<vector<string>> tickets) {
	sort(tickets.begin(), tickets.end(), comp);
	size = tickets.size();
	dfs(0, "ICN", tickets);
	return answer;
}
*/

//오름차순 정렬 -> 첫 경로 찾으면 dfs문 종료
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>  
using namespace std;

int visited[10000] = { 0, };
vector<string> answer, tmp;
int size;

bool dfs(int num, string word, vector<vector<string>> &tickets) {
	tmp.push_back(word);

	if (num == size) {
		answer = tmp;
		tmp.pop_back();
		return true;
	}

	for (int i = 0; i < size; ++i) {
		if (visited[i])continue;
		if (word == tickets[i][0]) {
			visited[i] = 1;
			if (dfs(num + 1, tickets[i][1], tickets))return true;
			visited[i] = 0;
		}
	}
	tmp.pop_back();
	return false;
}

vector<string> solution(vector<vector<string>> tickets) {
	sort(tickets.begin(), tickets.end());
	size = tickets.size();
	dfs(0, "ICN", tickets);
	return answer;
}