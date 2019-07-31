#include <iostream>
#include <cstdio>
#include <string>
#include <deque>
#include <sstream>

using namespace std;

int main(){
	int n;
	
	scanf("%d", &n);
	cin.ignore();
	while(n--){
		int num,tmp;
		string order,arr,arr_string="";
		deque<int> arr_int;
		char c;
		
		getline(cin, order);
		scanf("%d", &num);
		cin.ignore();
		getline(cin, arr);
		stringstream stream(arr);
		while(stream>>c){
			if(c==',')
				arr_string += " ";
			if(c!='['&&c!=']'&&c!=',')
				arr_string += c;
		}
		stringstream format(arr_string);
		while(format>>tmp){
			arr_int.push_back(tmp);
		}
		int front = 0, rear = 0;
		bool is_reverse = false;
		for(int i=0;i<order.size();i++){
			if(order[i]=='R'){
				is_reverse = !is_reverse;
			}
			else{
				if(is_reverse)
					rear++;
				else
					front++;
			}
		}
		if(front+rear<=num){
			printf("[");
			if(is_reverse){
				for(int i=arr_int.size()-rear-1;i>=front;i--){
					printf("%d",arr_int[i]);
					if(i!=front)
						printf(",");
				}
			}
			else{
				for(int i=front;i<arr_int.size()-rear;i++){
					printf("%d",arr_int[i]);
					if(i!=arr_int.size()-rear-1)
						printf(",");
				}
			}
			printf("]\n");
		}
		else
			cout << "error" << endl;
	}
	return 0;
}