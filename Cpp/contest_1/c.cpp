#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef ONLINE_JUDGE
#define dbg(x,y) ((void)0)
#else
#define dbg(x,y) std::cout << "[Debug] " << x << " : "<< y <<"\n"
#endif 
using namespace std;


int main(){
#ifndef ONLINE_JUDGE
    cout<<"[DEBUG] debug enabled!\n";
#endif
    TIMME
    int t;
    cin >> t;
    while(t--){
        int n, p;
        string s;
        cin >> n >> s;
        bool ans = true;
        for(int i = 0 ; i < n; ++i){
            p = i + 1;
            bool flag = false;
            if(p%2 == 0) true;
            for(int j = p; j < n; ++j){
                if(s[j] == s[i] && j% 2 == p % 2){
                    ans = false;
                    break;
                }
            }
            if(!ans) break;
        }
        if(!ans) cout<< "NO\n";
        else cout<< "YES\n";
    }

    return 0;
}