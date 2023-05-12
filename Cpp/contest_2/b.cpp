#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef ONLINE_JUDGE
#define dbg(x,y) ((void)0)
#else
#define dbg(x,y) std::cout << "[Debug] " << x << " : "<< y <<"\n"
#endif 
using namespace std;
#define big 1000000007

int main(){
#ifndef ONLINE_JUDGE
    cout<<"[DEBUG] debug enabled!\n";
#endif
    TIMME
    int n;
    cin >> n;
    int dp[51];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i <= 50; ++i){
        dp[i] = (dp[i-2] + dp[i-1] + 1) % big ;
    }
    cout<<dp[n];


    return 0;
}