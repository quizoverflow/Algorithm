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
        int n,tmp;
        cin >> n;
        vector<pair<int,int>> a;
        vector<int> b;
        for(int i = 0; i< n; ++i){
            cin >> tmp;
            a.push_back({tmp,i});
        }
        for(int i = 0; i < n; ++i){
            cin >> tmp;
            b.push_back(tmp);
        }
        sort(a.begin(),a.end());
        for(int i = 0; i < n; ++i){
            if(a[i].first - b[a[i].second] > )
        }
    }
    

    return 0;
}