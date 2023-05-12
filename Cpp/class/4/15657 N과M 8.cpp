#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int N ,M;
int num[8];
int tree[10001]= {0,};
vector<int> ans;
void dfs(int s){
    int i,tmp;
    if(ans.size() == M){
        for(i = 0; i < M; ++i) cout<<ans[i]<<" ";
        cout<<"\n";
        return ;
    }
    for(i = s; i < N; ++i){
        tmp = num[i];
        ans.push_back(tmp);
        dfs(i);
        ans.pop_back();
    }
    
}

int main(){
    TIMME
    int i;
    cin>>N>>M;
    for(i = 0; i < N; ++i){
       cin >> num[i]; 
    }
    sort(num,num+N);
    dfs(0);
    return 0;
}