#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    TIMME
    int i, j, n,tem;
    cin >> n;
    vector<int> dp(n+1);
    dp[1] = 1;
    for(i=2; i <=n; ++i){
        tem = 4;
        for(j = 1; j*j<=i; ++j){
            tem = min(tem, dp[i-j*j] + 1);
        }
        dp[i] = tem;
    }
    cout<<dp[n];

    return 0;
}