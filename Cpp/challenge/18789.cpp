#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef ONLINE_JUDGE
#define dbg(x,y) ((void)0)
#else
#define dbg(x,y) std::cout << "[Debug] " << x << " : "<< y <<"\n"
#endif 
using namespace std;

pair<int,int> delta[8] ={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

int result(vector<vector<int>> &board){
    int res = 1;
    register int i,j;
    while(1){
        bool flag = false;
        string goal = to_string(res);
        vector<int> g;
        for(auto &a : goal) g.push_back(a-'0');
        queue<pair<pair<int,int>,int>> qu;
        for(i = 0; i < 8; ++i){
            for(j = 0; j < 14; ++j){
                if(board[i][j] == g.front()){
                    qu.push({{i,j},1});
                }
            }
        }
        if(qu.empty()) return res -1;
        while(!qu.empty()){
            pair<int,int> now = qu.front().first;
            int point = qu.front().second;
            qu.pop();
            if(point == g.size()){
                flag = true;
                break;
            } 
            for(i = 0; i < 8; ++i){
                int ny = now.first+delta[i].first;
                int nx = now.second + delta[i].second;
                if(ny >= 0 && nx >= 0 && ny < 8 && nx <14){
                    if(board[ny][nx] == g[point]){
                        qu.push({{ny,nx},point+1});
                    }    
                }
                
            }
        }
        if(flag) res++;
        else{
            return res - 1;
        }
    }
}
void make_random_board(vector<vector<int>> &b){
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 14; ++j){
            b[i][j] = rand() % 10;
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
    cout<<"[DEBUG] debug enabled!\n";
#endif
    TIMME
    register int i , j, k; // 조금이라도 더 빨리 연산하라고..
    int first_gene_size,roulette_size = 1275; //룰렛 휠 크기..상위 50개를 기준으로 설정됨
    //초기 유전자 수 설정 (일단 100개)
    first_gene_size = 100;
    
    //룰렛 휠 생성..고득점 오름차순 정렬 후 i번 째 인덱스의 룰렛 크기 = (50-i) 
    vector<int> wheel;
    int wheel_size = 1;
    for(i = 0; i < (first_gene_size / 2); ++i){
        for(j = 0; j < wheel_size; ++j){
            wheel.push_back(i);
        }
        wheel_size++;
    }
    vector<vector<vector<int>>> genes(first_gene_size,vector<vector<int>>(8,vector<int>(14)));
    vector<pair<int,int>> genes_point; // first : point  second : index
    for(int i = 0; i < first_gene_size; ++i){
        make_random_board(genes[i]);
        genes_point.push_back({result(genes[i]),i});
    }
    sort(genes_point.begin(),genes_point.end());
    cout<<" == <first generation genes production has completed  == \n";

    //유전 시작
    int count = 0;
    vector<vector<vector<int>>> next(first_gene_size,vector<vector<int>>(8,vector<int>(14)));
    while(1){
        int father,mother;
        for(i =0 ; i < (first_gene_size/2); ++i){
            father = genes_point[wheel[rand() % roulette_size]].second;
            mother = genes_point[wheel[rand() % roulette_size]].second;
            for(j= 0; j < 8; ++j){
                for(k = 0; k < 7; ++k){
                    next[2*i][j][k] = genes[father][j][k]; //딸 하나 아들 하나
                    next[2*i+1][j][k] = genes[mother][j][k];
                }
                for(k = 7; k < 14; ++k){
                    next[2*i][j][k] = genes[mother][j][k]; //딸 하나 아들 하나
                    next[2*i+1][j][k] = genes[father][j][k];
                }
            }
        }
        if(rand()%1000 == 1){ // 0.1퍼센트의 확률로 자손 중 하나에 돌연변이
            next[rand()%100][rand()%8][rand()%14] = 5;
        }
        for(i = 0; i < (first_gene_size / 2); ++i){
            for(j = 0; j < 8; ++j){
                for(k = 0; k < 8; ++k){
                    genes[i][j][k] = next[i][j][k];
                }
            }
        }
        genes_point.clear();
        for(i = 0; i < first_gene_size; ++i){
            genes_point.push_back({result(genes[i]),i});
        } 
        sort(genes_point.begin(),genes_point.end());
        count++;

        int max_point = genes_point.back().first;
        if(count % 10 == 0) cout<<"current maximum point = " << max_point <<"\n";
        if(max_point > 3000){
            cout<<"===complete===\n";
            for(i = 0; i < 8; ++i){
                for(j = 0; j < 14; ++j){
                    cout<<next[genes_point[0].second][i][j];
                }
                cout<<"\n";
            }
        }
    }
    return 0;
}