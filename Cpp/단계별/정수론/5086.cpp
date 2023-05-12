#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    TIMME
    int fir,sec;
    while(1){
        cin >> fir >> sec;
        if(fir ==0 && sec ==0) break;
        if(fir <sec && sec % fir == 0) cout <<"factor"<<"\n";
        else if(fir > sec && fir % sec == 0) cout <<"multiple"<<"\n";
        else cout<<"neither"<<"\n";
    }
    return 0;
}