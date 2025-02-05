/*
#BOJ 31925너 재능있어
#DP
*/
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef PSJINU
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

int main(){
    FASTIO
    int N, M, k, tmp;
    vector<int> win,lose;
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> tmp;
        win.push_back(tmp);
    }
    cin >> M;
    for(int i = 0; i < M; ++i){
        cin >> tmp;
        lose.push_back(tmp);
    }
    cin >> k;

    vector<vector<int>> table(N+1,vector<int>(M+1,-1e9));

    //dp table 초기화
    //table[이긴횟수][진 횟수]
    
    table[0][0] = 0;

    //이기기만 하는 경우는 그냥 승리포인트 더한다
    for(int i = 1; i <= N; ++i){
        table[i][0] = table[i-1][0] + win[i-1];
    }

    //지는 경우
    //단위구간을 넘는 점수를 b라 했을 때, b가 0이면 (커트라인에 걸치면) 가장 크게 잃을 수 있으므로 무조건 lose point를 잃게 한다
    //b가 0이 아니라면 min(b,lose[i-1]) 을 잃게 한다.
    for(int i = 1; i <= M; ++i){
        int b = table[0][i-1] % k;
        if(table[0][i-1] < 0){
            b = k + b;
        }

        if(b == 0){
            table[0][i] = table[0][i-1] - lose[i-1];
        }
        else{
            table[0][i] = table[0][i-1] - min(b,lose[i-1]);
        }
    }

    //wp = 맨 마지막 게임에서 이긴 경우, lp = 맨 마지막 게임에서 진 경우에서의 최대점수
    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            int b = table[i][j-1] % k;
            if(table[i][j-1] < 0){
                b = k + b;
            }
            int wp = table[i-1][j] + win[i-1];

            int lp;
            //b가 0이라면 무조건 lose point를 잃는 것이 낫다.
            if(b == 0){
                lp = table[i][j-1] - lose[j-1];
            }
            else{
                lp = table[i][j-1] - min(b,lose[j-1]);
            }

            table[i][j] = max(lp,wp);
        }
    }

    cout << table[N][M];

    return 0;
}