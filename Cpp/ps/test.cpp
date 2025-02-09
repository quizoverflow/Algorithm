#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef PSJINU
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

int main(){
    FASTIO

    vector<int> v = {1,2,3,4,5};
    debug(v);

    vector<int> a = {9,9,9,9};

    v.assign(a.begin(),a.end());
    
    cout << "#2"<<v.size() << endl;
    debug(v);

    v.assign(1,3);
    cout <<"#3"<<v.size() << endl;
    debug(v);

    return 0;
}