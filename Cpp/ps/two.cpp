#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

void run_case(){
    int n;
    cin >> n;
    vector<vector<int>> sticker(2,vector<int>(n));
    for(int i = 0; i < n; ++i){
        cin >> sticker[0][i];
    }
    for(int i = 0; i < n; ++i){
        cin >> sticker[1][i];
    }
    if(n == 1){
        cout << max(sticker[0][0],sticker[1][0]) <<"\n";
        return;
    }
    else if(n == 2){
        cout << max(sticker[0][0] + sticker[1][1], sticker[0][1] + sticker[1][0]) <<"\n";
        return;
    }
    vector<vector<int>> table(2,vector<int>(n));
    table[0][0] = sticker[0][0];
    table[1][0] = sticker[1][0];
    table[0][1] = sticker[1][0] + sticker[0][1];
    table[1][1] = sticker[0][0] + sticker[1][1];
    for(int i = 2; i < n; ++i){
        //i열째 윗칸선택
        int a = sticker[0][i] + table[1][i-1];
        int b = sticker[0][i] + table[1][i-2];
        table[0][i] = max(a,b);

        //i열째 아랫칸 선택
        a = sticker[1][i] + table[0][i-1];
        b = sticker[1][i] + table[0][i-2];
        table[1][i] = max(a,b);
    }

    cout<<max(table[0][n-1],table[1][n-1])<<"\n";
}

int main(){
    FASTIO

    int testcase;
    cin >> testcase;

    while(testcase--){
        run_case();
    }

    return 0;
}