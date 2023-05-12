#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    TIMME
    int i,t,tem;
    cin>>t;
    long long dp[41][41];
    dp[0][1] = 0;
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[0][0] = 1;
    dp[1][0] = 0;
    dp[2][0] = 1;
    for(i = 3; i<=40; ++i){
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
        dp[i][0] = dp[i-1][1];
    }
    for(i = 0; i < t; ++i){
        cin >>tem;
        cout<<dp[tem][0]<<" "<<dp[tem][1]<<"\n";
    }
    return 0;
}