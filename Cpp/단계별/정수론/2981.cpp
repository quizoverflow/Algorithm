#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int gcd(int x, int y){
    if(y == 0) return x;
    return gcd(y,x%y);
}
int main(){
    TIMME
    int i,n,big;
    cin>>n;
    vector<int> num;
    vector<int> s_num;
    for(i=0; i<n;++i){
        int tem;
        cin>>tem;
        num.push_back(tem);
    }
    sort(num.begin(),num.end());
    for(i=1;i<n;++i){
        s_num.push_back(num[i] - num[i-1]);
    }
    sort(s_num.begin(),s_num.end());
    big = gcd(s_num[0],s_num[1]);
    for(i = 2; i<n-1; ++i){
        int tem = gcd(s_num[i],s_num[i-1]);
        big = gcd(tem, big);
    }
    vector<int>ans;
    ans.push_back(big);
    for(i=2; i<= pow(big,0.5)+ 1; ++i){
        if(big%i ==0){
            ans.push_back(i);
            ans.push_back(big/i);
        }
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    for(i=0; i<ans.size(); ++i){
        cout<<ans[i]<<" ";
    }
    return 0;
}