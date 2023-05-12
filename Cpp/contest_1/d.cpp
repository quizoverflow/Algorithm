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
    int t;
    cin >> t;
    while(t--){
        int n, q ,tmp,sum = 0;
        cin >> n >> q;
        vector<int> num(n+1);
        for(int i = 1; i<= n; ++i){
            cin >> tmp;
            sum += tmp;
            num[i] = sum;
        }
        while(q--){
            int l, r, k;
            cin >> l >> r >> k;
            int s = num[n] - num[r] + num[l-1] + k * (r - l + 1);
            if(s % 2 == 0) cout << "NO\n";
            else cout<<"YES\n";
        }
    }

    return 0;
}