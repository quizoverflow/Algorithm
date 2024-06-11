/*PS template*/
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

bool is_decimal(int n){
    string s = to_string(n);
    for(auto &i : s){
        if(i-'0' != 0 && i - '0' != 1){
            return false;
        }
    }
    return true;
}

int main(){
    FASTIO
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool yes = true;
        while(1){
            if(is_decimal(n)){
                break;
            }
            else{
                if(n % 11 == 0){
                    n /= 11;
                }
                else{
                    yes = false;
                    break;
                }
            }
        }
        if(yes) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}