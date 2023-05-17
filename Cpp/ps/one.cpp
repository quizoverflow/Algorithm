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
    
    int n , m;
    cin >> n >> m;
    vector<int> board(100,0);
    vector<bool> is_tel(100,false);
    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        board[x] = y;
        is_tel[x] =true;
    }
    for(int i = 0; i< m; ++i){
        int u, v;
        cin >> u >>v;
        board[u] = v;
        is_tel[u] =true;
    }
    vector<int> visited(100,false);
    queue<pair<int,int>> qu;
    qu.push({0,0});
    while(!qu.empty()){
        int now = qu.front().first;
        int cnt = qu.front().second;
        qu.pop();
        if(now == 99){
            cout<<cnt;
            break;
        }
        for(int i = 1; i <= 6; ++i){
            int next = now + i;
            bool flag = false;
            if(is_tel[next]){
                flag = true;
                next = board[next];
            }
            if(next >= 100) continue;
            if(!visited[next]){
                qu.push({next,cnt + 1});
                if(flag) continue;
                visited[next] = true;
            }
        }

    }
    return 0;
}