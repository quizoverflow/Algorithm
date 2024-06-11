#include <iostream>
using namespace std;
int divisor(int x, int y){
    if(y == 0) return x;
    return divisor(y,x%y);
}
int main(){
    int f,s;
    cin>>f>>s;
    int gcd;
    gcd = divisor(f,s);
    cout <<gcd <<"\n";
    cout<< f*s/gcd;    
    return 0;
}