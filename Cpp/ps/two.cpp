/*PS template*/
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

typedef unsigned long long ull;

int main(){
    FASTIO

    vector<ull> x, y;
    ull tmp;
    int xSize, ySize;
    cin >> xSize >> ySize;

    for(int i = 0; i < xSize; ++i){
        cin >> tmp;
        x.push_back(tmp);
    }
    for(int i = 0; i < ySize; ++i){
        cin >> tmp;
        y.push_back(tmp);
    }

    


    return 0;
}