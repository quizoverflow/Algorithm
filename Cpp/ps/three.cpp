#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

int main(){
    FASTIO
    int64_t n;
    cin >> n;
    vector<int64_t> sol(n);
    for(int i = 0; i< n; ++i){
        cin >> sol[i];
    }
    //오름차순
    sort(sol.begin(),sol.end());

    int64_t sum = 1e14;
    int64_t ts;
    int64_t ans[3];
    int64_t s, e;
    for(int i = 0; i < n-2; ++i){
        s = i + 1;
        e = n-1;
        while(s < e){
            ts = sol[i] + sol[s] + sol[e];
            if(abs(ts) < abs(sum)){
                ans[0] = i;
                ans[1] = s;
                ans[2] = e;
                sum = ts;
            }
            if(ts < 0){
                s++;
            }
            else if(ts > 0){
                e--;
            }
            else{
                break;
            }
        }
    }
    for(auto &a : ans) cout << sol[a] << " ";

    return 0;
}