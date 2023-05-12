#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int gcd(int x, int y){
    if(y==0) return x;
    return gcd(y,x%y);
}

int main(){
    TIMME
    int i,t,a,b;
    cin >> t;
    for(i= 0; i<t; ++i){
        cin>>a>>b;
        cout<< a*b/gcd(a,b)<<"\n";
    }
    return 0;
}