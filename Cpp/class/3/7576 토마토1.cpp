#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int n,m;
vector<vector<int>> box(1001,vector<int>(1001));
queue<pair<int,int>> qu;
int arr_x[4]={1,0,-1,0};
int arr_y[4] ={0,1,0,-1};

int main(){
    TIMME
    int i, j;
    cin >> m >> n;
    for(i = 0; i < n; ++i){
        for(j = 0; j <m; ++j){
            cin >> box[i][j];
            if(box[i][j] == 1) qu.push({i,j});
        }
    }
    int x,y,new_x,new_y;
    while(!qu.empty()){
        x = qu.front().first;
        y = qu.front().second;
        qu.pop();
        for(i = 0; i <4; ++i){
            new_x = x + arr_x[i];
            new_y = y + arr_y[i];
            if(new_x >= 0 && new_x < n && new_y >=0 &&new_y <m){
                if(box[new_x][new_y] == 0){
                    box[new_x][new_y] = box[x][y] + 1;
                    qu.push({new_x,new_y});
                }             
            }
        }
    }
    int ans = box[0][0];
    for(i=0; i<n;++i){
        for(j = 0; j<m; ++j){
            if(ans < box[i][j]) ans = box[i][j];
            if(box[i][j] == 0){
                cout<< -1;
                return 0;
            }
        }
    }
    cout<<ans - 1;
    return 0;
}