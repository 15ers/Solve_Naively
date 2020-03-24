#include <bits/stdc++.h>

using namespace std;

struct info{
    int sum;
    int one;
    int two;
    int three;
    int idx;
};

bool cmp(info &left, info &right){
    if(left.sum==right.sum){
        if(left.three==right.three)   return left.two > right.two;
        else    return left.one > right.one;
    }
    else    return left.sum > right.sum;
}

int main(){
    int n;
    cin >> n;
    vector<info> arr(3);
    arr[0].idx = 1;
    arr[1].idx = 2;
    arr[2].idx = 3;
    while(n--){
        int tmp;
        for(int i=0;i<3;i++){
            cin >> tmp;
            arr[i].sum += tmp;
            if(tmp==3)  arr[i].three++;
            else if(tmp==2) arr[i].two++;
            else    arr[i].one++;
        }
    }
    sort(arr.begin(),arr.end(),cmp);
    if(arr[0].sum==arr[1].sum && arr[0].two==arr[1].two)    cout << 0 << " " << arr[0].sum << endl;
    else    cout << arr[0].idx << " " << arr[0].sum << endl;
    return 0;
}
