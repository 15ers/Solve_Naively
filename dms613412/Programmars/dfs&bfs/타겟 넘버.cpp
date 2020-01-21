#include <string>
#include <vector>

using namespace std;

int answer = 0, size;

void dfs(int sum, int index, int &target, vector<int> &numbers) {
	if (index == size) {
		if (sum == target)++answer;
		return;
	}

	dfs(sum + numbers[index], index + 1, target, numbers);
	dfs(sum - numbers[index], index + 1, target, numbers);
}


int solution(vector<int> numbers, int target) {
	size = numbers.size();
	dfs(0, 0, target, numbers);
	return answer;
}