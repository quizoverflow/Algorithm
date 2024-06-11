/*PS template*/
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

int main(){
    FASTIO
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<char>> board(2*n,vector<char>(2*n));
        bool flag = true;
        for(int i = 0; i < 2*n; ++i){
            for(int j = 0; j < 2*n; ++j){
                if(i % 4  == 0 || i % 4 == 1){
                    if(j % 4  == 0 || j % 4 == 1){
                        board[i][j] = '#';
                    }
                    else{
                        board[i][j] = '.';
                    }
                }
                else{
                    if(j % 4  == 0 || j % 4 == 1){
                        board[i][j] = '.';
                    }
                    else board[i][j] = '#';
                }
            }
        }
        for(int i = 0; i < 2*n; ++i){
            for(int j = 0; j < 2*n; ++j){
                cout<<board[i][j];
            }
            cout<<"\n";
        }
    }

    return 0;
}