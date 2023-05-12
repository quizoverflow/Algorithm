#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    TIMME
    int i,n,ans=0,tem;
    vector<int> p;
    cin>>n;
    for(i=0; i<n;++i){
        cin>>tem;
        p.push_back(tem);
    } 
    sort(p.begin(),p.end());
    for(i=0; i<n; ++i) ans += p[i] *(n-i);
    cout<<ans;
    return 0;
}