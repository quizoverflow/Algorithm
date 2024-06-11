#include <bits/stdc++.h>
using namespace std;

int main(void){

    int arr[5];
    int sum = 0;
    for (int i=0; i < 5; i++){
        cin >>arr[i];
        sum += arr[i];
    }
    sum /= 5;
    sort(arr,arr+5);

    cout << sum <<"\n";
    cout << arr[2];


    return 0;
}