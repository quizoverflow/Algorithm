#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef ONLINE_JUDGE
#define dbg(x,y) ((void)0)
#else
#define dbg(x,y) std::cout << "[Debug] " << x << " : "<< y <<"\n"
#endif 
using namespace std;


int main(){
#ifndef ONLINE_JUDGE
    cout<<"[DEBUG] debug enabled!\n";
#endif
    TIMME
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> loc(3,vector<pair<int,int>>(n));
    for(int i = 0; i< n; ++i){
        int a , b, c;
        loc[i][0] = {a,i};
        loc[i][1] = {b,i};
        loc[i][2] = {c,i};
    }
    for(int i = 0; i < 2; ++i) sort(loc[i].begin(),loc[i].end());
    for(int i = 0; i < 3; ++i){
        
    } 
    
    return 0;
}