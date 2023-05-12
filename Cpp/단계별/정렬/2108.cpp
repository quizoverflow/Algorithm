#include <bits/stdc++.h>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i,n,count= 0,mid,check,mode,range;
    double sum = 0;
    cin >> n;
    int arr[8001] = {};
    vector<int> vec;
    for(i = 0; i < n; i++){
        int tem;
        cin >> tem;
        sum += tem;
        arr[4000+tem] ++;
    }
    check = 0;
    for(i=0; i < 8001; i++){
        
        if(count < (n+1)/2) {
            count += arr[i];
            if(count >= (n+1)/2){
                mid = i - 4000;
            }
        }

        if(arr[i] > check) check = arr[i];

    }
    for(i=0; i<8001; i++){
        if(arr[i] == check){
            vec.push_back(i-4000); 
        }
        if(vec.size() >= 2) break;
    }
    if(vec.size() >= 2) mode = vec[1];
    else mode = vec[0];

    int start, end;
    for(i = 0; i < 8001; i++){
        if(arr[i] != 0){
            start = i;
            break;
        }
    }
    for(i = 8000; i >= 0; i--){
        if(arr[i] != 0){
            end = i;
            break;
        }
    }
    range = end - start;
    
    cout << (int)round(sum / n) << "\n";
    cout << mid <<"\n";
    cout << mode << "\n";
    cout << range;

    return 0;
}