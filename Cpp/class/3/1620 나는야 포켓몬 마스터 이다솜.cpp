#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    TIMME
    int n, m, i,j;
    cin >>n>>m;
    map<string,int> map;
    vector<string> mon;
    string tem;
    for(i=0;i<n;++i){
        cin >> tem;
        mon.push_back(tem);
        map[tem] = i;
    }
    for(i=0; i<m; ++i){
        cin >> tem;
        if(tem[0]>=48 && tem[0] <= 58){
            int ans = 0;
            for(j = 0; j <tem.size(); ++j){
                ans += (tem[j]- '0')* pow(10,tem.size()-1-j);
            }
            cout<<mon[ans - 1]<<"\n";
        }
        else cout<<map[tem] + 1<<"\n";
    }
    return 0;
}