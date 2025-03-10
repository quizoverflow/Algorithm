/*
#BOJ 1011 Fly me to the Alpha Centauri
#수학
*/
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef PSJINU
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

void run_case(){
    long long x , y;
    cin >> x >> y;

    y -= x;

    long long n = 1;
    long long dd;
    while(1){
        dd = n * n + n;
        if(dd >= y) break;
        n++;
    }
    if(dd - n >= y) n = 2*n - 1;
    else n *= 2;
    
    cout << n << "\n";
}

int main(){
    FASTIO

    int testcase;
    cin >> testcase;

    while(testcase--){
        run_case();
    }

    return 0;
}