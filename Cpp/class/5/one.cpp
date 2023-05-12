#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int dp[1000001] = {0};
int main(){
    TIMME
    int i, j, n,ans,tmp,pre;
    cin>> n;
    int *num = new int[n];
    for(i = 0; i <n; ++i){
        cin >> tmp;
        num[i] = tmp;
        pre = 0;
        for(j = 0; j <i; ++j){
            if(tmp > num[j] && pre < dp[num[j]]) pre = dp[num[j]];
        }
        dp[tmp] = ++pre;
    }
    cout<<*max_element(dp,dp+1000001);
    return 0;
}