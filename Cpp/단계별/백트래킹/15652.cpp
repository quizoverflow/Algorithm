#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int n,m;
int ans_arr[9];
void dfs(int count_m){
    int i;
    if(count_m == m){
        for(i = 0; i < m; ++i){
            cout << ans_arr[i] << " ";
        }
        cout <<"\n";
        return;
    }
    for(i = 1; i <= n; ++i){
        if(ans_arr[count_m - 1] <= i){
            ans_arr[count_m] = i;
            dfs(count_m + 1);
        }
        
    }
}
int main(){
    TIMME
    cin >> n >> m;
    dfs(0);
    
    return 0;
}