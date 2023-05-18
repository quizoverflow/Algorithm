#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[DMSG: " << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define INF 1e9

int V, E, u, v, w;
int M, x, S, y;
vector<pair<int,int>> graph[10001];
vector<bool> mac(10001,false);
vector<int> ans_mac(10001,-1);
vector<bool> star(10001,false);
vector<int> ans_star(10001,-1);
vector<int> dist_mac(10001,INF);
vector<int> dist_star(10001,INF);
vector<int> total(10001,0);

void dijkstra(vector<int> &ans, int limit,vector<int> &dist){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[0] = 0;
    pq.push({0,0});

    while(!pq.empty()){
        int now = pq.top().second;
        pq.pop();
        int ncost = 0;
        int next = 0;
        for(auto &a : graph[now]){
            next = a.second;
            ncost = dist[now] + a.first;
            if(ncost < dist[next]){
                dist[next] = ncost;
                pq.push({ncost,next});
            }
        }
    }
    for(int i = 1; i <= V; ++i){
        if(!mac[i] && !star[i] && dist[i] <= limit){
            ans[i] = dist[i];
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
    cout<<"[DEBUG] debug enabled!\n";
#endif
    TIMME
    
    cin >> V >> E;
    for(int i = 0 ; i< E ; ++i){
        cin >> u >> v >> w;
        graph[u].emplace_back(w,v);
        graph[v].emplace_back(w,u);
    }
    cin >> M >> x;
    int tmp;
    for(int i = 0; i < M; ++i){
        cin >> tmp;
        graph[0].emplace_back(0,tmp);
        mac[tmp] = true;
    }
    dijkstra(ans_mac,x,dist_mac);
    graph[0].erase(graph[0].begin(),graph[0].end());
    cin >> S >> y;
    for(int i = 0; i < S; ++i){
        cin >> tmp;
        graph[0].emplace_back(0,tmp);
        star[tmp] = true;
    }
    dijkstra(ans_star,y,dist_star);
    int final_ans = INF;
    bool flag = false;
    for(int i = 1; i <= V; ++i){
        if(!mac[i] && !star[i] && ans_mac[i] != -1 && ans_star[i] != -1){
            flag = true;
            tmp = ans_mac[i] + ans_star[i];
            if(tmp < final_ans) final_ans = tmp;
        }
    }
    if(flag) cout<< final_ans;
    else cout<< -1;
    

    return 0;
}




