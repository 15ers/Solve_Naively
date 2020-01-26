#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
	unordered_map <string, int> hash;
	for (auto &x : clothes) {
		if (hash.find(x[1]) == hash.end())
			hash[x[1]] = 1;
		else
			++hash[x[1]];
	}
	int answer = 1;
	for (auto &x : hash) {
		answer *= (x.second + 1);
	}

	return answer - 1;
}