#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int n, m, ans = 0;
int area[8][8]; //bfs 와 dfs 로 갖고 놀 연구소 상황 데이터
int origin[8][8];  //초기 연구소 상황 원본
vector<pair<int,int>> w; //벽의 위치 보관하는 벡터
vector<pair<int,int>> v;
queue<pair<int,int>> qu;  //바이러스의 위치 저장하는 큐, bfs에서 쓰임
int dc[4] = {1,0,-1,0}; //바이러스는 상하좌우로 퍼진다
int dr[4] = {0,1,0,-1};
void bfs(){  // 바이러스가 퍼진 상황을 만들어주는  bfs 함수
    int i;
    while(!qu.empty()){
        int row = qu.front().first;
        int col = qu.front().second;
        qu.pop();
        for(i = 0; i < 4; ++i){
            int nr = row + dr[i];
            int nc = col + dc[i];
            if(nr >= 0 && nc >= 0 && nr < n && nc < m){
                if(area[nr][nc] == 0){
                    qu.push(make_pair(nr,nc));
                    area[nr][nc] = 2;
                }
            }
        }
    }
}
void wall(int cnt){ 
    if(cnt == 3){  // 세울 벽을 3개 만들어 내면,
        for(int i = 0; i < 3; ++i){  // area에 벽을 세 개 세우고
            area[w[i].first][w[i].second] = 1;
            // 디버깅 용 cout<<"["<<w[i].first<<","<<w[i].second<<"] ";
        }
        bfs();  // bfs 로 바이러스를 끝까지 퍼뜨린다.
        int safe = 0; // 안전지대 개수 0으로 초기화
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(area[i][j] == 0) safe++; // 안전지대 개수 카운팅
            }
        }
        if(safe > ans) ans = safe; // 기존의 정답보다 크면 갱신
        for(int i = 0; i < n; ++i){  // 더럽혀진 area 데이터를 origin을 통해 복구
            for(int j = 0; j < m; ++j){
                area[i][j] = origin[i][j]; 
            }
        }
        for(int i = 0; i < v.size(); ++i){ // 큐가 비어버렸으므로 큐에 초기 바이러스 위치 삽입
            qu.push(v[i]);
        }
        return;
    }
    for(int i = 0; i < n; ++i){ // n개의 행과
        for(int j = 0; j < m; ++j){ //m개의 열로 이루어진 area에서
            bool flag = false;  // 이미 세운 벽과의 중첩을 피해주는 코드
            for(int k = 0; k < w.size(); ++k){
                if(i == w[k].first && j == w[k].second) flag = true; 
            }
            if(flag) continue;

            if(area[i][j] == 0){  // area값이 0이면, 벽을 세울 수 있으므로
                w.push_back(make_pair(i,j)); // 벽 벡터에 위치 입력
                wall(cnt + 1); // 재귀
                w.pop_back(); // 벽 데이터 pop
            }
        }
    }
}
int main(){
    TIMME
    int i,j,tmp;
    cin >> n >>m;
    for(i = 0; i < n; ++i){  // 초기 데이터 area와 origin 에 모두 저장
        for(j =0; j <m; ++j){
            cin >> tmp;
            area[i][j] = tmp;
            origin[i][j] = tmp;
            if(tmp == 2) { // 초기 바이러스의 위치 qu에 저장
                qu.push(make_pair(i,j));
                v.push_back(make_pair(i,j)); // 바이러스 위치 저장
            } 
        }
    }
    wall(0);
    cout<<ans;
    return 0;
}