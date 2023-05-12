#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

vector<string>ans(1000000);
int main(){
    TIMME
    string tmp;
    int n, m;
    vector<string> nohear,nosee;
    cin >> n>> m;
    for(int i =0 ; i < n; ++i){
        cin>>tmp;
        nohear.push_back(tmp);
    }
    for(int i = 0; i < m; ++i){
        cin >> tmp;
        nosee.push_back(tmp);
    }
    sort(nohear.begin(),nohear.end());
    sort(nosee.begin(),nosee.end());
    auto it = set_intersection(nohear.begin(),nohear.end(),nosee.begin(),nosee.end(),ans.begin());
    ans.erase(it,ans.end());

    cout<<ans.size()<<"\n";
    sort(ans.begin(),ans.end());
    for(int i = 0; i< ans.size(); ++i) cout<<ans[i]<<"\n";

    return 0;
}