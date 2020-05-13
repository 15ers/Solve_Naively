#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    scanf("%d",&n);
    vector<int> cards(n);
    for(int &p: cards)  scanf("%d",&p);
    scanf("%d",&m);
    vector<int> targets(m);
    for(int &p: targets)    scanf("%d",&p);
    sort(cards.begin(),cards.end());
    for(int target: targets){
        int cnt=0;
        int low = lower_bound(cards.begin(),cards.end(),target) - cards.begin();
        int high = upper_bound(cards.begin(),cards.end(),target) - cards.begin();
        printf("%d ",high-low);
    }
    printf("\n");

    return 0;
}
