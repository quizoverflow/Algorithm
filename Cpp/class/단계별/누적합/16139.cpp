#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int alphabet[200001][27];
int main(){
    TIMME
    string s;
    char alpha;
    int i,j,q,l,r,a;
    cin >>s>>q;
    for(i=0;i<26;++i) alphabet[0][i] = 0;
    for(i=1; i <=s.size(); ++i){
        int tem = s[i-1] - 'a';
        for(j=0; j < 26; ++j){
            if(j == tem) alphabet[i][tem] = alphabet[i-1][tem] + 1;
            else alphabet[i][j] = alphabet[i-1][j];
        }
    }
    for(i=0; i <q; ++i){
        cin >>alpha>> l >> r;
        a = alpha - 'a';
        cout<<alphabet[r+1][a] - alphabet[l][a]<<"\n";
    }
    return 0;
}