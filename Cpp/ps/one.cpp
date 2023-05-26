#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef ONLINE_JUDGE
#define dbg(x,y) ((void)0)
#else
#define dbg(x,y) std::cout << "[Debug] " << x << " : "<< y <<"\n"
#endif 
using namespace std;


int main(){
#ifndef ONLINE_JUDGE
    cout<<"[DEBUG] debug enabled!\n";
#endif
    TIMME
    int n,p,t;
    int table[2][16];
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> t >> p;
        table[0][i] = t;
        table[1][i] = p;
    }
    vector<int> dp(n+1,0);
    int day = 1;
    if(table[0][n] == 1) dp[n] = table[1][n];
    for(int i = n-1; i >= 1; --i){
        day++;
        if(day < table[0][i]){
            dp[i] = dp[i+1];
        }
        else{
            dp[i] = max(dp[i+table[0][i]] + table[1][i] , dp[i+1]);
        }
    }
    cout<<dp[1];
    return 0;
}