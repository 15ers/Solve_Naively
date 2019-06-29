#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	int arr[100000], n, sum;
	bool check[1000000] = {0,};
	
	cin >> n;
	for(int i=0;i<n;i++){
		double tmp;
		
		scanf("%lf", &tmp);
		if(tmp == floor(tmp)){
			check[i] = 1;
		}
		arr[i] = int(floor(tmp));
	}
	for(int i=0;i<n;i++){
		sum += arr[i];
	}
	for(int i=0;i<n;i++){
		if(sum == 0){
			break;
		}
		else{
			if(!check[i]){
				arr[i] += 1;
				sum += 1;
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("%d\n", arr[i]);
	}
	
	return 0;
}