#include <cstdio>
#include <cstring>

int main(){
	int num, target;
	unsigned int s=0;
	char stream[5],ans;
	
	scanf("%d", &num);
	while(num--){
		scanf("%s %d", stream, &target);
		if(!strcmp(stream, "add")){
			s |= (1<<(target-1));
		}
		else if(!strcmp(stream, "all")){
			s = 1048575;
		}
		else if(!strcmp(stream, "remove")){
			s &= ~(1<<(target-1));
		}
		else if(!strcmp(stream, "check")){
			ans = (s & (1<<(target-1))) ? 1 : 0;
			printf("%d\n", ans);
		}
		else if(!strcmp(stream, "toggle")){
			s ^= (1<<(target-1));
		}
		else{
			s = 0;
		}
	}
	
	return 0;
}