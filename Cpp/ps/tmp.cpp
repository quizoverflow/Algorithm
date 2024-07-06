#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

void sayHi(int &i){
    cout <<"hello"<<endl;
    i++;
}

int main(){
    FASTIO

    vector<int> t = {1,2,3,4,5};
    int cnt = 4;
    for(int i = 0; i < t.size();sayHi(i)){
        if(cnt) t.push_back(cnt--);
        cout << t[i] << endl;
    }

    return 0;
}