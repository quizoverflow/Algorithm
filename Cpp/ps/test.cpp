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


    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;

    vector<pair<int,int>> v ={
        {1,0},
        {1,1},
        {9,2},
        {8,4},
        {10,1},
        {9,3},
        {1,-1}
    };

    for(int i = 0; i < v.size(); ++i){
        pq.push(v[i]);
    }

    while(!pq.empty()){
       // cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }

    int i = 0;

    cout << i * (i-1) / 2;
    
    return 0;
}