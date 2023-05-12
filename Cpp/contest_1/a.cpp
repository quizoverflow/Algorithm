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
    int t, a, b, c;
    cin >> t;
    while(t--){
        cin>> a >> b >> c;
        if(a + b == c){
            cout<<"+\n";
        }
        else cout<<"-\n";
    }

    return 0;
}