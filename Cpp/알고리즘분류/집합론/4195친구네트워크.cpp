/*
#BOJ 4195 친구네트워크
#자료구조
#분리집합
*/

#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef PSJINU
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

unordered_map<string,int> nameIdx;
vector<int> par;
vector<int> parCnt;
int pCnt = 0;

int find(int idx){
    if(par[idx] == idx) return idx;
    else return par[idx] = find(par[idx]);
}

void merge(int a, int b){
    int pa = find(a);
    int pb = find(b);

    if(pa!=pb){
        par[pb] = pa;
        parCnt[pa] += parCnt[pb];
    }
}


void clear(){
    nameIdx.clear();
    par.clear();
    parCnt.clear();
    pCnt = 0;
}

void run_case(){
    clear();
    int f;
    cin >> f;
    for(int i = 0; i < f; ++i){
        string a, b;
        cin >> a >> b;
        if(nameIdx.find(a) == nameIdx.end()){
            nameIdx[a] = pCnt++;
            par.push_back(nameIdx[a]);
            parCnt.push_back(1);
        }
        if(nameIdx.find(b) == nameIdx.end()){
            nameIdx[b] = pCnt++;
            par.push_back(nameIdx[b]);
            parCnt.push_back(1);
        }
        merge(nameIdx[a],nameIdx[b]);
        cout << parCnt[find(nameIdx[a])] << "\n";
    }
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