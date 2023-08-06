/*PS template*/
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

int board[1025][1025];
int dp[1025][1025];

int main(){
    FASTIO
    int n , m, tmp;
    cin >> n>> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j<= n; ++j){
            cin >> board[i][j];
        }
    }
    dp[1][1] = board[1][1];
    
    int x1, y1, x2 ,y2;
    for(int q = 0; q < m; ++q){
        cin >> x1 >> y1 >> x2 >> y2;

    }

    return 0;
}