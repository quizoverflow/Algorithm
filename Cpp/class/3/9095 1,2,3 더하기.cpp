#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    TIMME
    int i, t, n;
    int dp[11];
    dp[1]= 1;
    dp[2]= 2;
    dp[3]= 4;
    for(i=4; i <=10; ++i) dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    cin>>t;
    for(i=0; i <t; ++i){
        cin >>n;
        cout<<dp[n]<<"\n";
    }
    
    return 0;
}