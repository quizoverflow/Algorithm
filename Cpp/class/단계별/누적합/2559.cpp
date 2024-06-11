#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    TIMME
    int i,n,k,tem;
    cin >>n>>k;
    int *day = new int[n+1];
    vector<int> ans;
    day[0] = 0;
    for(i = 1; i <= n; ++i){
        cin >> tem;
        day[i] = tem + day[i-1];
    }
    for(i = k; i <=n; ++i) ans.push_back(day[i] - day[i-k]);
    cout<<*max_element(ans.begin(),ans.end());
    return 0;
}