#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights) {
	int size = heights.size();
	vector<int> answer(size, 0);
	for (int index = size - 1; index >= 0; --index) {
		int x = heights[index];
		for (int i = index - 1; i >= 0; --i) {
			if (x < heights[i]) {
				// cout<<x<<" "<<heights[i]<<endl;
				answer[index] = i + 1;
				break;
			}
		}
	}


	return answer;
}