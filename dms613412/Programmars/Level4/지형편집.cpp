#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


long long solution(vector<vector<int> > land, int P, int Q)
{
	int size = land.size();
	int right = 0, left = 1000000001, mid;
	for (int i = 0; i < size; ++i) {
		right = max(right, *max_element(land[i].begin(), land[i].end()));
		left = min(left, *min_element(land[i].begin(), land[i].end()));
	}

	while (left <= right) {
		mid = (left + right) / 2;
		long long sum1 = 0, sum2 = 0;
		for (int y = 0; y < size; ++y) {
			for (int x = 0; x < size; ++x) {
				//mid
				if (land[y][x] < mid) {
					sum1 += (long long)(mid - land[y][x])*P;
				}
				else if (land[y][x] > mid) {
					sum1 += (long long)(land[y][x] - mid)*Q;
				}

				//mid+1
				if (land[y][x] < mid + 1) {
					sum2 += (long long)(mid + 1 - land[y][x])*P;
				}
				else if (land[y][x] > mid + 1) {
					sum2 += (long long)(land[y][x] - mid - 1)*Q;
				}
			}
		}
		if (left == right) return sum1;
		if (sum1 > sum2) left = mid + 1;
		else right = mid;
	}

	return -1;
}

