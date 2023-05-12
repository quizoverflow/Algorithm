#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    TIMME
    int i, n;
    cin >> n;
    int *step = new int[n];
    for(i = 0; i < n; ++i){
         cin >> step[i];
    }
    vector<int> dp;
    dp.push_back(step[0]);
    dp.push_back(step[0] + step[1]);
    dp.push_back(max(step[0] + step[2], step[1] + step[2]));
    for(i=3; i<n; ++i){
        dp.push_back(max((dp[i-2] + step[i]), (dp[i-3] + step[i-1]) + step[i]));
    }
    cout<<dp[n-1];
    return 0;
}