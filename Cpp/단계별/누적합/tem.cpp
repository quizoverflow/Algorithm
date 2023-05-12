#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
#define ull unsigned long long

ull num [1000001] = {0,};

int main(){
    TIMME
    int n,m,i;
    ull tem;
    cin >> n >> m;
    int same_remain[1000] = {0,};
    for(i = 1; i<= n; ++i){
        cin >> tem;
        num[i] = num[i-1] + tem;
    }
    for(i=1; i <= n; ++i) num[i] %= m;
    for(i=1; i<=n; ++i) same_remain[num[i]]++;
    ull ans = same_remain[0];
    for(i=0; i <m; ++i){
        tem = same_remain[i];
        if(tem!= 0) ans += tem * (tem - 1) / 2;
    }
    cout<<ans;
    return 0;
}