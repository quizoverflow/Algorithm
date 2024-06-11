#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    TIMME
    pair<int,int> p[3];
    int i,a = 0,b = 0;
    for(i = 0; i < 3; ++i){
        cin >> p[i].first >> p[i].second;
    }
    for(i = 0; i < 3; ++i){
        a += p[i].first * p[(i+1)%3].second;
        b += p[(3-i)%3].first * p[2 - i].second;
    }
    if(a>b) cout<<"1";
    else if(a < b) cout<<"-1";
    else cout<<"0";
        
    return 0;
}