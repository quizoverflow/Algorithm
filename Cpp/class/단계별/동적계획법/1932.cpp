#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    TIMME
    int n,i,j,ans;
    int dp[500][500];
    cin >> n;
    cin >> dp[0][0];
    for(i =1; i<n; ++i){
        vector<int> num;
        for(j = 0; j <= i; ++j){
            int tem;
            cin >> tem;
            num.push_back(tem);
        }
        dp[i][0] = dp[i-1][0] + num[0];
        dp[i][i] = dp[i-1][i-1] + num[i]; 
        for(j = 1; j < i; ++j){
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + num[j];
        }
    }
    ans = dp[n-1][0];
    for(i = 0; i < n; ++i){
        ans = max(dp[n-1][i],ans);
    }
    cout <<ans;
    
    return 0;
}