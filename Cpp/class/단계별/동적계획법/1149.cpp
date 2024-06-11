#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,i,zero,one,two,ans;
    int cost[1000][3];
    for(i=0; i< 3; ++i) cost[0][i] = 0;
    cin >> n;
    for(i = 1; i <= n; ++i){
        cin >> zero >> one >> two;
        cost[i][0] = min(cost[i-1][1] + zero, cost[i-1][2] + zero);
        cost[i][1] = min(cost[i-1][0] + one, cost[i-1][2] + one);
        cost[i][2] = min(cost[i-1][0] + two, cost[i-1][1] + two);
    }
    ans = cost[n][0];
    for(i = 0; i< 3; ++i) if(ans > cost[n][i]) ans = cost[n][i];
    cout << ans;

    return 0;
}