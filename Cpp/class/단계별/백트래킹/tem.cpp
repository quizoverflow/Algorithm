#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int cnt = 0;
int board[9][9];
int put[81][2];

bool check(int y, int x, int num){
    int i, j;
    for(i = 0; i < 9; ++i){
        if(num == board[i][x] || num == board[y][i]) return false;
    }
    int box_x = 3 * (x / 3);
    int box_y = 3 * (y / 3);
    for(i = box_x; i < box_x + 3; ++i){
        for(j = box_y; j < box_y + 3; ++j){
            if(num == board[j][i]) return false;
        }
    }
    return true;
}
void dfs(int n){
    if(n == cnt) return;
    int i;
    for(i = 1; i <=9; ++i){
        if(check(put[n][0],put[n][1],i)){
            board[put[n][0]][put[n][1]] = i;
            return dfs(n+1);
        }
        else{
            
        }
    }
}

int main(){
    TIMME
    int i,j,tem;
    for(i= 0; i<9; ++i){
        for(j = 0; j < 9; ++j){
            cin >> tem;
            if(tem == 0){
                put[cnt][0] = i;
                put[cnt][1] = j;
                cnt++;
            }
            board[i][j] = tem;
        }
    }
    dfs(0);
    for(i= 0; i<9; ++i){
        for(j = 0; j < 9; ++j){
            cout<< board[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}