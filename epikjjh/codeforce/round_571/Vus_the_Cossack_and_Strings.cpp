#include <iostream>
#include <string>

using namespace std;

int main(){
	string a, b;
	int len_a, len_b, cnt_a=0, cnt_b=0, ans=0;
	int prefix[1000000] = {0,};
	
	cin >> a;
	cin >> b;
	
	for(int i=0;i<b.length();i++){
		if(b[i]=='1'){
			cnt_b++;
		}
	}
	for(int i=0;i<a.length();i++){
		if(i!=0){
			prefix[i] += prefix[i-1];
		}
		if(a[i]=='1'){
			prefix[i] += 1;
		}
		if(i>=b.length()-1){
			cnt_a = (i != b.length()-1) ? prefix[i] - prefix[i-b.length()] : prefix[i];
			if((cnt_a+cnt_b)%2 ==0){
				ans++;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}