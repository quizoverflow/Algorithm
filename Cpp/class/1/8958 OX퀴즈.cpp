#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    TIMME
    int t, i, j;
    string res;
    cin >> t;
    for(i = 0; i < t; ++i){
        cin >> res;
        int tmp = 0;
        int ans = 0;
        for(j = 0; j < res.size(); ++j){
            if(res[j] == 'O') tmp ++;
            else tmp = 0;
            ans += tmp;
        }
        cout<<ans<<"\n";
    }
    return 0;
}