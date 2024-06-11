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
    string s;
    string ap;
    while(t--){
        cin >> s;
        int h, m;
        bool is_am = true;
        h = 10 * (s[0] - '0') + (s[1] - '0');
        m = 10 * (s[3] - '0') + (s[4] - '0');
        if(h >= 12){
            is_am = false;
            if(h != 12) h -= 12;
        }
        if(h == 0){
            h += 12;
        }
        string ans_h = to_string(h);
        string ans_m = to_string(m);
        if(h < 10){
            ans_h = '0' + to_string(h);
        }
        if(m < 10){
            ans_m = '0' + to_string(m);
        }
        if(is_am) ap = "AM";
        else ap = "PM";
        cout<<ans_h<<":"<<ans_m<<" "<<ap<<"\n";

    }

    return 0;
}