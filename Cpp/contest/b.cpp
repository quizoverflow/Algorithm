/*PS template*/
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

int main(){
    FASTIO
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        bool c = false;
        for(int i = n-1; i >= 0; --i){
            if(s[i] >= '5'){
                for(int j = i; j < n; ++j) s[j] = '0';
                if(i > 1) s[i-1]++;
                else c = true;
            }
        }
        if(c) cout<<1;
        for(auto &a : s) cout<< a - '0';
        cout<<"\n";
    }

    return 0;
}