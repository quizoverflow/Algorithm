#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    TIMME
    int n,k,i,tem,ans = 0;
    vector<int> value;
    cin >>n>>k;
    for(i=0; i<n; ++i){
        cin >> tem;
        value.push_back(tem);
    }
    for(i=n-1; i>=0; --i){
        if(value[i] <= k){
            int quo = k / value[i];
            ans += quo;
            k -= quo*value[i];
        }
        if(k ==0) break;
    }
    cout<<ans;
    return 0;
}