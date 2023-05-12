#include <bits/stdc++.h>
using namespace std;
int main(){
    int i, A, B,a,b,ans;
    cin>>A>>B;
    for(i=2; i>=0;--i){
        a = to_string(A)[i] - '0';
        b = to_string(B)[i] - '0';
        if(a != b){
            ans = a > b ? A : B;
            break;
        }
    }
    cout<<ans/100 + (ans%100/10)*10 + ans%100%10*100; 
    return 0;
}