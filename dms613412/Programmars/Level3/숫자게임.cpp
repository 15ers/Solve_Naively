#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int tmp = 0;
bool func(int x) {
	return (x > tmp);
}

int solution(vector<int> A, vector<int> B) {
	int answer = 0;
	int size = A.size();
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int index = 0;
	for (auto &X : A) {
		if (X < B[index]) { ++answer; ++index; }
		else {
			tmp = X;
			index = find_if(B.begin() + index, B.end(), func) - B.begin() + 1;
			if (index <= size)++answer;
		}
		if (index >= size)break;
	}

	return answer;
}