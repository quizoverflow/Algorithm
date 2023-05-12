#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int n, m, answer = 0;
vector<vector<int>> com(101);
bool virus[101] ={false};
void dfs(int num){
    int i;
    virus[num] = true;
    answer++;
    for(i = 0; i < com[num].size(); ++i){
        if(!virus[com[num][i]]){
            dfs(com[num][i]);
        }
    }
}
int main(){
    TIMME
    int i,a,b;
    cin >> n >>m;
    for(i = 0; i < m; ++i){
        cin >> a>>b;
        com[a].push_back(b);
        com[b].push_back(a);
    }
    dfs(1);
    cout<<answer -1;
    return 0;
}