#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    TIMME
    int i,n,tem,a=0,b=0,ans = 0;
    cin >> n;
    for(i = 1; i <=n; ++i){
        tem = i;
        while(1){
            if(tem%2 ==0){
                tem /=2;
                a++;
            }
            else break;
        }
        tem = i;
        while(1){
            if(tem%5 ==0){
                tem /=5;
                b++;
            }
            else break;
        }
    }
    cout<<ans + min(a,b);
    
    return 0;
}