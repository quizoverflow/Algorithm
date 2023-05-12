#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool board[3072][6143] = {false};
int main(){
    TIMME
    int n;
    cin >> n;
    int k = log2(n/3);
    int col_size = 5 * pow(2,k) + pow(2,k) - 1;
    board[0][col_size/2] = true;
    board[1][col_size/2 - 1] = true;
    board[1][col_size/2 + 1] = true;
    for(int i = 0; i < 5; ++i) board[2][col_size/2 - 2 + i] = true;

    for(int count = 0; count < k; ++count){
        int tmp = 3 * pow(2,count);
        for(int i = 0; i < tmp; ++i){
            for(int j = 0; j < col_size; ++j){
                if(board[i][j]){
                    board[i + tmp][j - tmp] = true;
                    board[i + tmp][j + tmp] = true;
                }
            }
        }  
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < col_size; ++j){
            if(board[i][j]) cout<<"*";
            else cout<<" ";
        }
        cout<<"\n";
    }

    
    return 0;
}