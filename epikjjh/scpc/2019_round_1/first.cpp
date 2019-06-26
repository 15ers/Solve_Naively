#include <iostream>
#include <cstdio>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	int arr[1000001] = {0,};
	int prefix[1000001] = {0,};
	
	arr[2] = 1;
	prefix[2] = 1;
	
	for(int i=3;i<=1000000;i++){
		if(i%2==0){
			arr[i] = arr[i/2] + 1;
		}
		else{
			arr[i] = arr[(i+1)/2] + 2;
		}
		prefix[i] = arr[i] + prefix[i-1];
	}

	scanf("%d", &T);
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int n, m;
		scanf("%d%d",&n,&m);
		Answer = prefix[m]-prefix[n-1];
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		printf("Case #%d\n",test_case+1);
		printf("%d\n",Answer);
	}

	return 0;
}