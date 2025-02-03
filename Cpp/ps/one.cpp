/*
#BOJ 1002 터렛
#기하학 #많은 조건분기
*/

#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef PSJINU
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

#define power(x) (x) * (x)

struct Circle{
    double x,y,r;
};

Circle c1,c2;
double dsq;

//case 1
int outer_point(){
    double ssq = power(c1.r + c2.r);
    if(ssq > dsq){
        return 2;
    }
    else if (ssq == dsq){
        return 1;
    }
    else{
        return 0;
    }
}

//case 2
int inner_point(){
    double msq = power(c2.r - c1.r);
    if(dsq < msq){
        return 0;
    }
    else if(dsq == msq){
        return 1;
    }
    else{
        return 2;
    }
}

//case 3
int same_point(){
    if(c1.r == c2.r) return -1;
    else return 0;
}

void run_case(){
    cin >> c1.x >> c1.y >> c1.r >> c2.x >> c2.y >> c2.r;
    if(c2.r < c1.r){
        swap(c1,c2);
    }
    dsq = power(c1.x - c2.x) + power(c1.y - c2.y);

    int ans;
    if(c1.x == c2.x && c1.y == c2.y){
        ans = same_point();
    }
    else{
        if(dsq <= c2.r * c2.r){
            ans = inner_point();
        }
        else{
            ans = outer_point();
        }
    }

    cout << ans << "\n";
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