#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef ONLINE_JUDGE
#define dbg(x,y) ((void)0)
#else
#define dbg(x,y) std::cout << "[Debug] " << x << " : "<< y <<"\n"
#endif 
using namespace std;
vector<vector<int>> area;
queue<pair<int,int>> air;
queue<vector<pair<int,int>>> out; //external cheese
vector<vector<bool>> check(100,vector<bool>(100,false));
int dy[4] ={1,0,-1,0};
int dx[4] ={0,1,0,-1};
int n, m, ans = 0;
void d(){
    cout<<"\n== debug =="<<endl;
    for(int i = 0; i < n;++i){
        for(int j = 0; j< m; ++j){
            cout<<area[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void check_init(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            check[i][j] = false;
        }
    }
}
void air_change(int a, int b){ // external air = 3
    air.push({a,b});   
    while(!air.empty()){
        int y = air.front().first;
        int x = air.front().second;
        for(int i = 0; i < 4; ++i){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                if(area[ny][nx] == 0){
                    area[ny][nx] = 3;
                    air.push({ny,nx});
                }
                else if(area[ny][nx] == 1){
                    check[ny][nx] = true;
                }
            }
        }
        air.pop();
    }
}
void melt(){
    while(!out.empty()){
        vector<pair<int,int>> tmp = out.front();
        out.pop();
        vector<pair<int,int>> changed;
        for(int j = 0; j < tmp.size(); ++j){
            int y = tmp[j].first;
            int x = tmp[j].second;
            int flag = 0;
            for(int i = 0 ; i < 4; ++i){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                    if(area[ny][nx] == 3) flag++;
                }
            }
            if(flag >= 2){
                changed.push_back({y,x});
            }
        }
        check_init();
        for(int i = 0; i < changed.size(); ++i){
            area[changed[i].first][changed[i].second] = 3;
            air_change(changed[i].first,changed[i].second);
        }  
        vector<pair<int,int>> next;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(check[i][j]) next.push_back({i,j});
            }
        }
        if(!next.empty()){
            out.push(next);
        }
        if(next.size() == 0){
            cout << ans;
            return;
        }
        ans++;
    }
}

int main(){
#ifndef ONLINE_JUDGE
    cout<<"[DEBUG] debug enabled!\n";
#endif
    TIMME
    int tmp;
    vector<int> t;
    cin >> n >> m;
    for(int i = 0 ; i < n; ++i){
        t.clear();
        for(int j = 0; j < m; ++j){
            cin >> tmp;
            t.push_back(tmp);
        }
        area.push_back(t);
    }
    area[0][0] = 3;
    air_change(0,0);
    vector<pair<int,int>> tem;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(check[i][j]) tem.push_back({i,j});
        }
    }
    if(tem.size()!= 0) out.push(tem);
    melt();

    return 0;
}