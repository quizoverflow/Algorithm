#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int get_hash(string &str){
    int hash = 0;
    int d = 250;
    for(int i = 0; i < str.size(); i += 2){
        hash += (str[i] - 'a') * d;
        d--;
    }
    return hash % 10000;
}
int main(){
    TIMME
    string tmp;
    int n,m,hash,ans = 0;
    cin >> n >> m;
    vector<vector<string>> table(10000); 
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        table[get_hash(tmp)].push_back(tmp);
    }
    for(int i = 0; i < m; ++i){ 
        cin >> tmp;
        int index = get_hash(tmp);
        for(int j = 0; j < table[index].size(); ++j){
            if(table[index][j] == tmp){
                ans++;
                break;
            } 
        }
    }
    cout<<ans;
    return 0;
}