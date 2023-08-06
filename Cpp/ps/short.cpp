/*PS template*/
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

int dp[100001];

int main(){
    FASTIO
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) dp[i] = i;

    for(int i = 1; i <= n; ++i){
        int max_j = sqrt(i);
        for(int j = 1; j <= max_j; ++j){
            dp[i] = min(dp[i],dp[i-j*j]+1);
        }
    }
    
    cout<<dp[n];

    return 0;
}