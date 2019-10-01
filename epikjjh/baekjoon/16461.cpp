#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MAX 146000
#define MIN 144000
#define STEP 20
#define INF 987654321

using namespace std;

int main(){
	int n;
	
	scanf("%d",&n);
	while(n--){
		double tmp_a,tmp_b,tmp_tar;
		int freq_a,freq_b,freq_tar,diff_a,diff_b,diff_max,diff_min;
		char freq_cur;
		
		scanf("%lf %lf %c %lf", &tmp_a,&tmp_b,&freq_cur,&tmp_tar);
		freq_a = int(tmp_a*1000);
		freq_b = int(tmp_b*1000);
		freq_tar = int(tmp_tar*1000);
		diff_a = abs(freq_a-freq_tar);
		diff_b = abs(freq_b-freq_tar);
		diff_max = abs(MAX-freq_tar);
		diff_min = abs(MIN-freq_tar);
		int num_a=INF, num_b=INF;
		if(diff_a%STEP==0 || diff_b%STEP==0 || diff_max%STEP==0 || diff_min%STEP==0){
			if(diff_a%STEP==0){
				int tmp = diff_a/STEP;
				num_a = num_a>tmp ? tmp : num_a;
			}
			if(diff_b%STEP==0){
				int tmp = diff_b/STEP;
				num_b = num_b>tmp ? tmp : num_b;
			}
			if(freq_a>freq_tar){
				if(diff_min%STEP==0){
					int tmp = (MAX-freq_a)/STEP + 1 + diff_min/STEP;
					num_a = num_a>tmp ? tmp : num_a;
				}
			}
			else{
				if(diff_max%STEP==0){
					int tmp = (freq_a-MIN)/STEP + 1 + diff_max/STEP;
					num_a = num_a>tmp ? tmp : num_a;
				}
			}
			if(freq_b>freq_tar){
				if(diff_min%STEP==0){
					int tmp = (MAX-freq_b)/STEP + 1 + diff_min/STEP;
					num_b = num_b>tmp ? tmp : num_b;
				}
			}
			else{
				if(diff_max%STEP==0){
					int tmp = (freq_b-MIN)/STEP + 1 + diff_max/STEP;
					num_b = num_b>tmp ? tmp : num_b;
				}
			}
			if(freq_cur=='A')
				num_b++;
			else
				num_a++;
			int ans = num_a>num_b ? num_b : num_a;
			if(ans>6)
				cout << "6" << endl;
			else cout << ans << endl;
		}
		else{
			cout << "6" << endl;
		}
	}
	return 0;
}