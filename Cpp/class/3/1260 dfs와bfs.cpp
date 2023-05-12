#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int n,m,v;
vector<vector<int>> tree(1001);
queue<int> qu;
bool visited[1001] ={false};
bool visited_bfs[1001] ={false};
void dfs(int num){
    int i,tem;
    visited[num] = true;
    cout << num <<" ";
    for( i = 0; i < tree[num].size(); ++i){
        tem = tree[num][i];
        if(!visited[tem]){
            dfs(tem);
        }
    }
}
void bfs(int num){
    int i, tem,t;
    qu.push(num);
    visited_bfs[num] = true;
    while(!qu.empty()){
        tem = qu.front();
        cout<<tem<<" ";
        qu.pop();
        for(i = 0; i < tree[tem].size(); ++i){
            t = tree[tem][i];
            if(!visited_bfs[t]){
                qu.push(t);
                visited_bfs[t] = true;
            }
        }
    }
}



int main(){
    TIMME
    int i,fn,sn;
    cin >> n >> m>> v;
    for (i = 0 ; i < m; ++i){
        cin >> fn >> sn;
        tree[fn].push_back(sn);
        tree[sn].push_back(fn);
    }
    for(i = 0; i <=n; ++i){
        sort(tree[i].begin(),tree[i].end());
    }
    dfs(v);
    cout<<"\n";
    bfs(v);


    
    return 0;
}