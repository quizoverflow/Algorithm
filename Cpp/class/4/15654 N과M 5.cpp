#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int N, M;
int num[8];
vector<vector<int>> ans;
vector<int> tmp;
bool visited[10001] = {false};
void dfs(int cnt){
    int i;
    if(cnt == M){
        for(i = 0; i <M; ++i){
            cout<<tmp[i] <<" ";
        }
        cout<<"\n";
        return;
    }
    for(i=0; i <N; ++i){
        int target = num[i];
        if(!visited[target]){
            visited[target] = true;
            tmp.push_back(target);
            dfs(cnt + 1);
            tmp.pop_back();
            visited[target] = false;
        } 
    }
    
}

int main(){
    TIMME
    int i,j;
    cin>>N>>M;
    for(i = 0; i < N; ++i){
        cin >> num[i];
    }
    sort(num,num+N);

    dfs(0);

    return 0;
}