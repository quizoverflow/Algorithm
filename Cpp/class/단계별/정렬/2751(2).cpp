#include <bits/stdc++.h>

using namespace std;

int main(void){

    int n;
    cin >> n;
    vector<int> vec;
    vector<int> vec2;

    for(int i=0; i < n; i++){
        int tem;
        cin >> tem;
        vec.insert(vec.begin() + i,tem);
    }
    
    
    for(int i = 0; i < n; i++){
        int num = 0;
        for(int j = 0; j < vec.size(); j++){
            if (vec[num] > vec[j]){
                num = j;
            }
            
        }
        vec2.push_back(vec[num]);
        vec.erase(vec.begin()+num);
        

    }

    for(int i = 0; i < n; i++){
        cout << vec2[i] <<"\n";
    }

    return 0;
}