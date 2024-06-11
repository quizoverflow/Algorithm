#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

#define INF 1e9
int n;
struct INFO{
    int start,end,cost;
};

void input_case(vector<INFO> &g){
    int m , w;
    int s, e, t;
    cin >> n >> m >> w;
    for(int i = 0; i < m; ++i){
        cin >> s >> e >> t;
        g.push_back({s,e,t});
        g.push_back({e,s,t});
    }
    for(int i = 0; i < w; ++i){
        cin >> s >> e >> t;
        g.push_back({s,e,-t});
    }
}

bool BellmanFord(vector<INFO> &g){
    int dist[501];
    fill(dist,dist+501,INF);
    dist[1] = 0;

    for(int i = 0; i < n-1; ++i){
        for(auto &edge : g){
            if(dist[edge.end] > dist[edge.start] + edge.cost){
                dist[edge.end] = dist[edge.start] + edge.cost;
            }
        }
    }
    for(int i = 0; i < n-1; ++i){
        for(auto &edge : g){
            if(dist[edge.end] > dist[edge.start] + edge.cost){
                return true;
            }
        }
    }
    return false;
}

void run_case(){
    vector<INFO> graph;
    input_case(graph);
    if(BellmanFord(graph) == true) cout <<"YES\n";
    else cout<<"NO\n";
}

int main(){
    FASTIO

    int testcase;
    cin >> testcase;

    while(testcase--){
        run_case();
    }

    return 0;
}