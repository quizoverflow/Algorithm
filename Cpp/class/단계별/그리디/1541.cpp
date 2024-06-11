#include <bits/stdc++.h>
#define TIMME ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main(){
    TIMME
    string exp;
    vector<int> num;
    cin >> exp;
    int i;
    int string_to_num = 0;
    int digit = 0;
    for(i=exp.size()-1; i >=  0; --i){
        if(exp[i] == '+'){
            num.push_back(string_to_num);
            num.push_back(-1);
            string_to_num = 0;
            digit = 0;
        }
        else if(exp[i] == '-'){
            num.push_back(string_to_num);
            num.push_back(-2);
            string_to_num = 0;
            digit = 0;
        }
        else{
            string_to_num += (exp[i] - '0') * pow(10,digit);
            digit++;
        }
    }
    if(string_to_num !=0) num.push_back(string_to_num);
    int ans = num.back();
    int symbol = 1;
    for(i=num.size()-2; i>=0; --i){
        if(num[i] > 0){
            ans += symbol * num[i];
        }
        else if(num[i] == -2){
            symbol = -1;
        }
    }
    cout<<ans;
    return 0;
}