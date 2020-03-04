#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int result = 40001;
int map[21][21];


void count(int y, int x, int d1, int d2) {
	int arr[5] = { 0, };

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {		
			if (y <= i && i <= y + d1 && x - i + y <= j && j <= x)
				arr[4] += map[i][j];
			else if(y<i && i<=y+d2 && x<j && j<=x+i-y)
				arr[4] += map[i][j];
			else if(y+d1<i && i<=y+d1+d2 && x-y-2*d1+i<=j && j<= x-d1+d2)
				arr[4] += map[i][j];
			else if(y+d2<i && i<y+d1+d2 && x+d2-d1<j && j<=x+y+2*d2-i)
				arr[4] += map[i][j];
			else if (i < y + d1 && j <= x) {				
				arr[0] += map[i][j];
			}else if (i <= y+ d2 && x<j) {
				arr[1] += map[i][j];
			}else if (y+d1<=i && j<x-d1+d2) {
				arr[2] += map[i][j];
			}else if (y+d2<i && x-d1+d2<=j) {
				arr[3] += map[i][j];
			}
			
		}
	}

	int tmp = *max_element(arr, arr + 5) - *min_element(arr, arr + 5);
	
	result = min(result, tmp);

}

int main(void) {
	
	scanf("%d", &N);
	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x <= N; ++x) {
			scanf("%d", &map[y][x]);
		}
	}

	for (int y = 1; y < N-1; ++y) {
		for (int x = 2; x < N ; ++x) {
			for (int d1 = 1; d1 < x; ++d1) {
				for (int d2 = 1; d2 <= N - x; ++d2) {
					if (d1 + d2 > N - y)continue;					
					count(y, x, d1, d2);
				}
			}
		}
	}
	printf("%d\n", result);
	return 0;
}











