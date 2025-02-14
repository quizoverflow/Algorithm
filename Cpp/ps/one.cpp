/*
#BOJ 1918 후위표기식 
#자료구조 #스택
*/
#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef PSJINU
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

char symbol[4] = {'+','-','*','/'};

void ChangeNotation(string &s, int start, int end){
    string postNotation;

    for(int i = start + 1; i < end; ++i){
        
    }

    s.replace(start,start-end+1,postNotation);
}

void Brace(string &s,int start ,int end){
    if(s[start] == '(') start++;
}


int main(){
    FASTIO

    string infix;
    cin >> infix;
    for(int i = 0; i < infix.size(); ++i){
        if(infix[i] ==)
    }

    return 0;
}