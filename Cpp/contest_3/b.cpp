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
    int t, n, k;
    string s;
    cin >> t;
    for(int i = 0; i< t; ++i){
        cin >> n >> k >> s;
        int ans = 0;
        vector<pair<int,int>> alp(26,{0,0});
        for(int j = 0; j < n; ++j){
            if(s[j] < 'a'){
                alp[s[j]-'A'].first++;
            }
            else{
                alp[s[j] - 'a'].second++;
            }
        }
        for(int j = 0; j < 26; ++j){
            if(alp[j].first > alp[j].second){
                ans += alp[j].second;
                alp[j].first -= alp[j].second;
                alp[j].second = 0;
            }
            else if(alp[j].first < alp[j].second){
                ans += alp[j].first;
                alp[j].second -= alp[j].first;
                alp[j].first = 0;
            }
            else if(alp[j].first == alp[j].second && alp[j].first != 0){
                ans += alp[j].first;
                alp[j].first = 0;
                alp[j].second = 0;
            }
        }
        for(int j = 0; j < 26; ++j){
            if(k == 0) break;
            if(alp[j].first != 0){
                if((alp[j].first / 2) <= k){
                    ans += alp[j].first / 2;
                    k -= alp[j].first / 2;
                }
            }
            if(alp[j].second != 0){
                if((alp[j].second / 2) <= k){
                    ans += alp[j].second / 2;
                    k -= alp[j].second / 2;
                }
            }
        }
        cout << ans <<"\n";
    }

    return 0;
}