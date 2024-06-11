#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    TIMME
    int n;
    cin >> n;
    while(n!= 1){
        for(int i = 2; i <pow(n,0.5); ++i){
            if(n % i == 0){
                cout<<i<<"\n";
                n /= i;
                break;
            }
        }
    }
    
    return 0;
}