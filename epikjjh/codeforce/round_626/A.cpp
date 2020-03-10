#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		vector<int> arr(n);
		int even=0,odd=0,even_i,odd_i_1=-1,odd_i_2=-1;
		for(int i=0;i<n;i++){
			cin >> arr[i];
			if(arr[i]%2){
				odd++;
				if(odd_i_1<0)	odd_i_1 = i+1;
				else	odd_i_2 = i+1;
			}
			else{
				even++;
				even_i = i+1;
			}
		}
		if(even || odd>1){
			if(even){
				cout << 1 << endl;
				cout << even_i << endl;
			}
			else{
				cout << 2 << endl;
				cout << odd_i_1 << " " << odd_i_2 << endl;
			}
		}
		else	cout << -1 << endl;
	}
	
	return 0;
}
