#include <bits/stdc++.h>

using namespace std;

struct info{
	int num;
	int strike;
	int ball;
};

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int ret=0,n;
	cin >> n;
	info arr[100];
	for(int i=0;i<n;i++)	cin >> arr[i].num >> arr[i].strike >> arr[i].ball;
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			if(i==j)	continue;
			for(int k=1;k<=9;k++){
				if(i==k || j==k)	continue;
				int target[3] = {i,j,k};
				bool flag = true;
				for(int l=0;l<n;l++){
					int s=0,b=0;
					int query[3] = {arr[l].num/100,(arr[l].num/10)%10,arr[l].num%10};
					for(int m=0;m<3;m++){
						for(int n=0;n<3;n++){
							if(target[m]==query[n]){
								if(m==n)	s++;
								else	b++;
							}
						}
					}
					if(s==arr[l].strike && b==arr[l].ball)	continue;
					else{
						flag = false;
						break;
					}
				}
				if(flag)	ret++;
			}
		}
	}
	cout << ret << endl;
	
	return 0;
}