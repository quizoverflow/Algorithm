#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    TIMME
    vector<unsigned long long> pado(101);
    int i,t,n;
    pado[1] = 1;
    pado[2] = 1;
    pado[3] = 1;
    pado[4] = 2;
    pado[5] = 2;
    pado[6] = 3;
    pado[7] = 4;
    for(i = 8; i<=100; ++i){
        pado[i] = pado[i-1] + pado[i-5];
    }
    cin >> t;
    for(i=0; i < t; ++i){
        cin >>n;
        cout<<pado[n]<<"\n";
    }
    
    return 0;
}