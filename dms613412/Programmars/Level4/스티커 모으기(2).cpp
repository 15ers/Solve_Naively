#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int N, B;

const char alpha[26] = {
	'A','B','C','D','E','F','G','H','I','J',
	'K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
};
int main() {
	scanf("%d %d", &N, &B);
	string answer = "";
	while (N > 0) {
		int tmp = N % B;
		if (tmp >= 10)
			answer += alpha[tmp - 10];
		else
			answer += to_string(tmp);
	}
	return 0;
}
