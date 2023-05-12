#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
bool cmp(pair<unsigned, unsigned> a, pair<unsigned, unsigned> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
int main(){
    TIMME
    unsigned i,n,ans = 0,a,b;
    vector<pair<unsigned,unsigned>> e_time;
    cin>>n;
    for(i = 0; i < n; ++i){
        cin >> a >>b;
        e_time.push_back({a,b});
    }
    sort(e_time.begin(),e_time.end(),cmp);
    unsigned start = 0;
    for(i=0; i<n; ++i){
        if(e_time[i].first >= start){
            ans++;
            start = e_time[i].second;
        }
    }
    cout << ans;
    return 0;
}