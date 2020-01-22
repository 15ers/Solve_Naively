#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 51;
int size, wsize;
int visited[50] = { 0, };

void dfs(int num, string word, vector<string> &words, string &target) {
	if (word == target) { answer = min(answer, num); return; }
	if (num == wsize)return;

	for (int i = 0; i < wsize; ++i) {
		if (visited[i])continue;
		int count = 0;
		for (int j = 0; j < size; ++j) {
			if (word[j] != words[i][j])++count;
			if (count > 1)break;
		}
		if (count == 1) {
			visited[i] = 1;
			dfs(num + 1, words[i], words, target);
			visited[i] = 0;
		}
	}

}

int solution(string begin, string target, vector<string> words) {
	size = begin.size(); wsize = words.size();
	dfs(0, begin, words, target);

	if (answer == 51)return 0;
	return answer;
}