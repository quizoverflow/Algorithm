#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(x...)
#endif 
using namespace std;

vector<int> getPi(string p){
    int m = p.size();
    //j는 문자열의 접미사 시작부분을 나타낸다
    //아래 반복문에서 i는 접두사 시작부분
    int j = 0;
    vector<int> pi(m,0);
    //하나의 문자열은 가능한 최장 접두/접미사 배열길이가 1이므로 조건에 위해. 따라서 i =1 부터 시작
    for(int i = 1; i < m; ++i){
        //최장 접두사/접미사 콤보에 실패했으므로, 접미사 시작 지점 다시 갱신하기
        while(j > 0 && p[i] != p[j]){
            j = pi[j-1];
        }
        //최장  접두/접미사 길이가 그대로 증가
        if(p[i] == p[j]){
            pi[i] = ++j;
        }
    }
    return pi;
}
vector<int> kmp(string t, string p){
    //정답 벡터
    vector<int> ans;
    //pi 벡터 생성
    vector<int> pi = getPi(p);
    int n = t.size(), m = p.size();
    //j 변수는 찾을 특정 문자열 p가 어디까지 매치되었는지를 나타냄
    //매치 콤보라고 생각하면 편함
    int j = 0;
    // 탐색 시작
    for(int i = 0; i < n; ++i){
        //글자가 다르면서 콤보는 쌓여있는 경우
        while(j > 0 && t[i] != p[j]){
            //콤보가 완전히 초기화 되는 것이 아님에 유의한다.
            j = pi[j-1];
        }
        //글자가 같은 경우
        if(t[i] == p[j]){
            //글자가 전부 같을 경우
            if(j == m-1) {
                j = pi[j];
                ans.push_back(i - m + 1);
            }
            // 매치 콤보 증가
            else{
                ++j;
            }
        }
    }
    return ans;
}

void test(string t, string p){
    vector<int> pi = getPi(p);
    for(auto i : pi){
        debug(i);
    }
}

int main(){
    FASTIO
    string t, p;
    getline(cin,t);
    getline(cin,p);

    p = "bcbc";
    t = "abcbcbccbc";
    vector<int> dv = getPi(p);

    for(auto &a : dv) cout<< "d "<<a <<endl;

    vector<int> ans = kmp(t,p);
    cout<<ans.size()<<"\n";
    for(auto &i : ans) cout << i + 1<< " ";

    return 0;
}