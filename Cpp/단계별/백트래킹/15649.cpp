#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool visited[9] = {false};
int ans_arr[9]={};
int n, m;
void dfs(int tem){
    if(tem == m){
        for (int i = 0; i < m; ++i){
            cout<<ans_arr[i] << " ";
        }
        cout<<"\n";
        return;
    }
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            visited[i] = true;
            ans_arr[tem] = i;
            dfs(tem + 1);
            visited[i] = false;
        }
    }
    
}

int main(){
    TIMME
    cin >> n >> m;

    dfs(0);

    return 0;
    
}