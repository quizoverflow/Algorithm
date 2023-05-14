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
    int n, a, b;
    cin >> n;
    vector<int> tree[100001];
    vector<int> parents(100001);
    for(int i = 1; i < n; ++i){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    queue<int> qu;
    vector<bool> visited(100001,false);
    visited[1] = true;
    qu.push(1);
    while(!qu.empty()){
        int now = qu.front();
        visited[now] = true;
        qu.pop();
        for(auto &a : tree[now]){
            if(!visited[a]){
                parents[a] = now;
                qu.push(a);
            }
        }
    }
    for(int i = 2; i <= n; ++i){
        cout<< parents[i] << "\n";
    }
    
    return 0;
}