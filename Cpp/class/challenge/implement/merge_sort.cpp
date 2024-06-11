#include <iostream>
using namespace std;

int array_size;

void merge_sort(int *arr,int idx_s,int idx_e,int compare_size){
    int *temp = new int[compare_size];
    for(int i = 0; i < compare_size; ++i){
        temp[i] = max(arr[idx_s + i], arr[idx_e + i]);
        temp[i+1] = min(arr[idx_s + i], arr[idx_e + i]);
    }
}


int main(){
    cout<< "input number of array size"<<endl;
    cin >> array_size;

    int *arr = new int[array_size];
    cout<<"input array elements"<<endl;
    for(int i = 0; i < array_size; ++i){
        cin >> arr[i];
    }

    //merge start
    int c_size = array_size % 2 == 0 ? array_size / 2 : array_size+1;
    merge_sort(arr,0,array_size/2,c_size);

    cout<<"sorted array elements"<<endl;
    for(int i = 0; i < array_size; ++i){
        cout<<arr[i] << " ";
    }
    return 0;
}