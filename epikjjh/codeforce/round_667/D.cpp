#include <bits/stdc++.h>

using namespace std;

int nums[18];
int len=0;

int bitcount(long long tar){
    int ret=0;
    int i=0;
    while(tar){
        ret += tar%10;
        nums[i++] = tar%10;
        tar /= 10;
    }
    len = i;
    return ret;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long n,s;
        scanf("%lld %lld", &n,&s);
        int bits=bitcount(n);
        int num=0;
        bool flag=true;
        while(bits>s){
            bits -= nums[num];
            num++;
            if(flag){
                bits++;
                flag = false;
            }
        }
        if(!num)    printf("0\n");
        else{
            long long std_num=1;
            for(int i=0;i<num;i++)  std_num *= 10;
            long long tar_num=nums[num-1];
            for(int i=1;i<=num-1;i++)  tar_num = tar_num*10+nums[num-1-i];
            printf("%lld\n",std_num-tar_num);
        }
    }

    return 0;
}
