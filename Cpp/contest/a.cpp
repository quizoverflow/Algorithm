/*PS template*/
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

int main(){
    FASTIO
    
    int t,a,b,c;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        if(a < b && b < c) cout << "STAIR\n";
        else if(a < b && b > c)cout<<"PEAK\n";
        else cout<< "NONE\n";
    }

    return 0;
}