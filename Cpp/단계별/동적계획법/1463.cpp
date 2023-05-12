#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int dp[1000001];

int main(){
    TIMME
    int n;
    cin>>n;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    int num ;
    for(num = 4; num <=n; ++num){
        vector<int> target;
        target.push_back(dp[num-1] + 1);
        if(num % 2 ==0){
            target.push_back(dp[num/2] + 1);
        }
        if(num % 3 ==0){
            target.push_back(dp[num/3] + 1);
        }
        dp[num] = *min_element(target.begin(),target.end());
    }
    cout<<dp[n];

    return 0;
}