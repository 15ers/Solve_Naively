#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

double Answer;
int main(int argc, char** argv)
{
	int T, test_case;

	scanf("%d",&T);
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int radius, start, end, num, left, right, height;
		
		scanf("%d%d%d", &radius, &start, &end);
		scanf("%d", &num);
		
		double start_d = double(start);
		for(int i=0;i<num;i++){
			scanf("%d%d%d", &left, &right, &height);
			if(height>=radius){
				Answer += (left-radius)-start_d + 2*(height-radius) + (right-left) + M_PI*radius;
				start_d = right+radius;
			}
			else{
				double theta = acos(double(radius-height)/double(radius));
				double x = sqrt(double(height*(2*radius-height)));
				Answer += (left-x)-start_d + 2*radius*theta + (right-left);
				start_d = right + x;
			}
		}
		Answer += end-start_d;
		/////////////////////////////////////////////////////////////////////////////////////////////

		printf("Case #%d\n", test_case+1);
		printf("%f\n", Answer);
	}

	return 0;
}