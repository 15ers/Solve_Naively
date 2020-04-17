
#include <string>
#include <vector>
#include <map>

using namespace std;

map <long long, long long> m;
long long find(long long x) {
	if (!m[x])return x;
	m[x] = find(m[x]);
	return find(m[x]);
}

vector<long long> solution(long long k, vector<long long> room_number) {

	vector<long long> answer;
	for (auto &x : room_number) {
		if (!m[x]) {
			answer.push_back(x);
			m[x] = find(x + 1);
		}
		else {
			long long tmp = find(m[x]);
			answer.push_back(tmp);
			m[tmp] = find(tmp + 1);
		}
	}

	return answer;
}