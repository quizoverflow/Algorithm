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
        int n,query,tmp;
        map<int,int> d;
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> tmp;
            if(d.find(tmp) != d.end()) d[tmp]++;
            else d.insert({tmp,1});
        }
        cin >> query;
        while(query--){
            long long x, y;
            cin >> x >> y;
            long long a = (x + sqrt(x*x - 4*y)) / 2;
            long long b = (x - sqrt(x*x - 4*y)) / 2;
            if(x*x < 4*y){
                cout<<0<<"\n";
                continue;
            }
            double sq = sqrt(x*x - 4*y);
            if(sq - int(sq) != 0){
                cout<<0<<" ";
                continue;
            }
            else if(d.find(a) == d.end() || d.find(b) == d.end()){
                cout<<0<<" ";
                continue;
            }
            else if(a != b) cout<< d[a] * d[b]<<" ";
            else if(a == b) cout<< d[a] * (d[a] - 1) / 2 << " ";
        }
        cout<<"\n";
    }   

    return 0;
}