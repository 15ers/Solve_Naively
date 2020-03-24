#include <bits/stdc++.h>

using namespace std;

struct timetable{
    int start;
    int end;
};

bool cmp(timetable &left, timetable &right){
    if(left.start==right.start) return  left.end<right.end;
    else    return left.start<right.start;
}

int main(){
    int n;
    scanf("%d",&n);
    vector<timetable> arr(n);
    for(auto &p: arr){
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        p.start = 100*a+b;
        p.end = 100*c+d;
    }
    sort(arr.begin(),arr.end(),cmp);
    int idx=0,ret=0,tmp=0;
    for(int i=301;i<=1130;i=tmp){
        bool flag=false;
        for(int j=idx;j<n;j++){
            if(arr[j].start>i)    break;
            if(tmp<arr[j].end){
                tmp = arr[j].end;
                idx = j;
                flag = true;
            }
        }
        if(flag)    ret++;
        else{
            printf("0\n");
            return 0;
        }
    }
    printf("%d\n",ret);

    return 0;
}
