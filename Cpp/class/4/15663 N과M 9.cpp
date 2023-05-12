#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int N, M;
set<int> num;
vector<int> tmp;
int visited[10001] = {0};
void dfs(int cnt){
    int i,t;
    if(cnt == M){
        for(i = 0; i <M; ++i) cout<<tmp[i] <<" ";
        cout<<"\n";
        return;
    }
    for(set<int>::iterator it=num.begin(); it !=num.end(); ++it){
        t = *it;
        if(visited[t]!= 0){
            visited[t]--;
            tmp.push_back(t);
            dfs(cnt + 1);
            tmp.pop_back();
            visited[t]++;
        } 
    }
}
int main(){
    TIMME
    int i,j,tem;
    cin>>N>>M;
    for(i = 0; i < N; ++i){
        cin >> tem;
        num.insert(tem);
        visited[tem]++;
    }
    dfs(0);
    return 0;
}