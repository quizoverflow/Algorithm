#include <bits/stdc++.h>
using namespace std;
#define bigger(x,y) x > y ? x : y

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i,n,tem,ans;
    cin >> n;
    vector<int> vec;
    vector<int> mem;
    for(i = 0; i < n; i++){
        cin >> tem;
        vec.push_back(tem);
    }
    mem.push_back(vec[0]);
    ans = vec[0];
    for(i = 1; i < n; i++){
        mem.push_back(bigger(mem[i-1] + vec[i], vec[i]));
        ans = bigger(mem[i], ans);
    }
    cout << ans;
    return 0;
}