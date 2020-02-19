#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int solution(string s)
{
	int answer = 1;
	/*reverse 함수용
	string str1=s;
	string str2 = s;
	string tmp_str1 = "";
	string tmp_str2 = "";
	reverse(str2.begin(),str2.end());
	*/
	int n = s.size();

	for (int size = n; size > 1; --size) {
		for (int i = 0; i <= n - size; ++i) {
			/*reverse함수용
			tmp_str1 = str1.substr(i,size);
			tmp_str2 = str2.substr(n-size-i,size);
			if(tmp_str1==tmp_str2)return size;
			*/
			bool isTrue = true;
			int index = 0;
			for (int j = i; j < size / 2 + i; ++j)
				if (s[j] != s[i + size - 1 - index++]) { isTrue = false; break; }
			if (isTrue) { return size; }
		}
	}

	return answer;
}