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
        int n, tmp, even = 0, odd = 0;
        cin >> n;
        for(int i = 0; i< n; ++i){
            cin >> tmp;
            if (tmp % 2 == 0) even += tmp;
            else odd += tmp;
        }
        if(even > odd) cout <<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}