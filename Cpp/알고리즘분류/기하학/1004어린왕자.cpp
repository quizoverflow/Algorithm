/*
#BOJ 1004 어린 왕자
#기하
*/

#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef PSJINU
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

#define power(x) (x) * (x)

struct COORD{
    int x,y,r;
};

int dsq(COORD s, COORD e){
    return power(s.x - e.x) + power(s.y - e.y);
}

void run_case(){
    int n,ans = 0;
    COORD s,e;
    cin >> s.x >> s.y;
    cin >> e.x >> e.y;
    cin >> n;

    for(int i = 0; i < n; ++i){
        COORD star;
        cin >> star.x >> star.y >> star.r;
        bool sin = false, ein = false;
        if(dsq(s,star) < power(star.r)) sin = true;
        if(dsq(e,star) < power(star.r)) ein = true;
        if(!(sin&&ein) && !(!sin && !ein)) ans++;
    }
    cout << ans << "\n";
}

int main(){
    FASTIO

    int testcase;
    cin >> testcase;

    while(testcase--){
        run_case();
    }

    return 0;
}