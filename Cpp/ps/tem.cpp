#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef ONLINE_JUDGE
#define dbg(x,y) ((void)0)
#else
#define dbg(x,y) std::cout << "[Debug] " << x << " : "<< y <<"\n"
#endif 
using namespace std;
#define INF INT_MAX

int main(){
#ifndef ONLINE_JUDGE
    cout<<"[DEBUG] debug enabled!\n";
#endif
    TIMME   
    int n;
    double ans = 0;
    cin >> n;
    vector<pair<double,double>> star(n);
    for(auto &a : star) cin >> a.first >> a.second;
    priority_queue<pair<double,int>,vector<pair<double,int>>,greater<>> pq;
    vector<vector<double>> dis(n,vector<double>(n,INF));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i==j) continue;
            if(dis[j][i] != INF){
                dis[i][j] = dis[j][i];
                continue;
            }
            double xx = (star[i].first- star[j].first)*(star[i].first-star[j].first);
            double yy = (star[i].second - star[j].second) * (star[i].second - star[j].second);
            dis[i][j] = sqrt(xx+yy);
        }
    }
    pq.push({0,0});
    vector<bool> visited(n,false);
    vector<double> dist(n,INF);
    dist[0] = 0;
    while(!pq.empty()){
        double cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(visited[now]) continue;
        visited[now] = true;
        ans+=cost;
        for(int i = 0; i < n; ++i){
            if(!visited[i] && i != now && dis[now][i] < dist[i]){
                dist[i] = dis[now][i];
                pq.push({dist[i],i});
            }
        }
    }
    cout << ans;
    


    return 0;
}