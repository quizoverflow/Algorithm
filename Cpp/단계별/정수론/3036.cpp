#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int gcd(int x, int y){
    if(y == 0) return x;
    return gcd(y, x%y);
}

int main(){
    TIMME
    int n,i,tem;
    int start, radius;
    cin >> n;
    cin >> start;
    for(i = 0; i< n-1; ++i){
        cin >> radius;
        tem = gcd(radius,start);
        cout<<start/tem <<"/"<<radius / tem<<"\n";
    }

    return 0;
}