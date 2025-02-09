/*
#BOJ 14442벽부수고이동하기2
#그래프탐색 #BFS
*/
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef PSJINU
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

int n,m,k;
vector<vector<int>> board;
pair<int,int> dir[4] = {{1,0},{0,1},{-1,0},{0,-1}};

class Info{
public:
    int x,y,kcnt,dist;
    Info(int y,int x, int kcnt,int dist){
        this->x = x;
        this->y = y;
        this->kcnt = kcnt;
        this->dist = dist;
    }
};


int main(){
    FASTIO

    cin >> n >> m >> k;

    board.assign(n,vector<int>(m,0));

    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        for(int j = 0; j < m; ++j){
            board[i][j] = s[j] - '0';
        }
    }

    Info start(0,0,k,1);
    queue<Info> qu;
    qu.push(start);
    vector<vector<vector<bool>>> visited(n,vector<vector<bool>>(m,vector<bool>(k+1,false)));
    visited[0][0][k] = true;

    while(!qu.empty()){
        Info curr = qu.front();
        qu.pop();

        if(curr.y == n-1 && curr.x == m-1){
            cout << curr.dist;
            return 0;
        }
        
        for(auto &d : dir){
            int ny = curr.y + d.first;
            int nx = curr.x + d.second;

            if(ny >= n || ny < 0 || nx < 0 || nx >= m) continue;
            if(visited[ny][nx][curr.kcnt]) continue;
            
            if(board[ny][nx] == 0 && visited[ny][nx][curr.kcnt] == false){
                qu.push(Info(ny,nx,curr.kcnt,curr.dist+1));
                visited[ny][nx][curr.kcnt] = true;
            }
            if(board[ny][nx] == 1 && curr.kcnt > 0){
                if(visited[ny][nx][curr.kcnt-1]) continue;
                qu.push(Info(ny,nx,curr.kcnt-1,curr.dist+1));
                visited[ny][nx][curr.kcnt-1] = true;
            }
        }
        }
    
    cout << -1;
    return 0;
}