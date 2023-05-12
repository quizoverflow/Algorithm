#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int city[51][51] = {0};
int n,m,ans = 10000;
vector<int> ans_group;
vector<pair<int,int>> chick;
vector<pair<int,int>> house;
vector<pair<int,int>> del;
vector<bool> visited;

void dfs(int count,int ni){
    if(count == m){
        int res = 0;
        vector<pair<int,int>> ch;
        for(int i = 0; i < visited.size(); ++i){
            if(visited[i]) ch.push_back({chick[i].first,chick[i].second});
        }
        for(int i = 0; i < house.size(); ++i){
            int r = house[i].first;
            int c = house[i].second;
            int tmp, min_d = 100;
            for(int j = 0; j < ch.size(); ++j){
                tmp = abs(ch[j].first - r) + abs(ch[j].second - c);
                if(tmp < min_d) min_d = tmp;
            }
            res += min_d;
        }
        if(ans > res) ans = res;
        return;
    }
    for(int i = ni; i < chick.size(); ++i){
        if(!visited[i]){
            int r = chick[i].first;
            int c = chick[i].second;    
            city[r][c] = 2;
            visited[i] = true;
            dfs(count + 1,i+1);
            visited[i] = false;
            city[r][c] = 0;

        }
    }
}
int main(){
    TIMME
    cin >> n >> m;
    for(int i =1 ; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> city[i][j];
            if(city[i][j] == 2){
                chick.push_back({i,j});
                city[i][j] = 0;
                visited.push_back(false);
            }
            else if(city[i][j] == 1) house.push_back({i,j});
        }
    }
    dfs(0,0);
    cout<<ans;
    return 0;
}