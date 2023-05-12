#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    TIMME
    int i,m,tem;
    string cal;
    set<int> num;
    set<int> num_new;
    for(i=1; i<=20; ++i) num_new.insert(i);
    cin >> m;
    for(i= 0; i <m; ++i){
        cin >> cal;
        if(cal == "add"){
            cin >> tem;
            num.insert(tem);
        }
        else if(cal == "remove"){
            cin >> tem;
            num.erase(tem);
        }
        else if(cal == "check"){
            cin >> tem;
            if(num.find(tem) == num.end()) cout<<0<<"\n";
            else cout<<1<<"\n";
        }
        else if(cal == "toggle"){
            cin >> tem;
            if(num.find(tem) == num.end()) num.insert(tem);
            else num.erase(tem);   
        }
        else if(cal == "all") num = num_new;
        else num.clear();
    }

    return 0;
}