/*PS template*/
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

#define p(x) x*x

struct COORD{
    double x, y;
};

double line(COORD a, COORD b){
    return sqrt(p((a.x-b.x)) + p((a.y-b.y)));
}

int main(){
    FASTIO
    cout.precision(6);
    cout<<fixed;
    int n;
    double a,b;
    COORD tmp;
    vector<COORD> point;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        tmp.x = a; tmp.y = b;
        point.push_back(tmp);
    }
    
    

    return 0;
}