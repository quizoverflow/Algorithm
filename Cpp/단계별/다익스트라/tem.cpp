#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef ONLINE_JUDGE
#define dbg(x,y) ((void)0)
#else
#define dbg(x,y) std::cout << "[Debug] " << x << " : "<< y <<"\n"
#endif 
using namespace std;

#define INF 1e9
vector<pair<int,int>> graph[20001];
int dp[20001];
void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    fill(dp,dp+20001,INF);
    dp[start] = 0;
    pq.push({0,start});
    while(!pq.empty()){
        int dis = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(dp[now] < dis) continue;
        for(int i = 0; i < graph[now].size(); ++i){
            int cost = dis + graph[now][i].second;
            if(cost < dp[graph[now][i].first]){
                dp[graph[now][i].first] = cost;
                pq.push({-cost,graph[now][i].first});
            }
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
    cout<<"[DEBUG] debug enabled!\n";
#endif
    TIMME
    int v, e , s_node;
    int a, b, c;
    cin >> v >> e;
    cin >> s_node;
    for(int i = 0; i < e; ++i){
        cin >> a >> b >> c;
        graph[a].push_back({b,c}); //a,b each define node, c define expense
    }
    dijkstra(s_node);
    for(int i = 1; i <= v; ++i){
        if(dp[i] == INF) cout<<"INF"<<"\n";
        else cout<<dp[i]<<"\n";
    }
    return 0;
}