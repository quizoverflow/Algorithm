#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
#define debug cout<<"debug " <<++debug_count<<endl;
int n;
int ans = 0;
int *chess = new int[n];

bool check(int x, int y){
    int i;
    for(i = 0; i < y ; ++i){
        if(chess[i] == x) return false;
        if(abs(chess[i] - x) == abs(y-i)) return false;
    }
    return true;
}
void dfs(int col){
    if(col == n) {
        ans++; 
        return;
    }
    int i;
    for(i = 0; i < n; ++i){
        chess[col] = i;
        if(check(i,col)) dfs(col + 1);
    }
}

int main(){
    TIMME
    cin >> n;
    dfs(0);
    cout<<ans;    
    return 0;
}