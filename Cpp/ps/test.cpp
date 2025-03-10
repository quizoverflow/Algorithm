#include<stdio.h>
long t,x,y,n,d;
main(){
    scanf("%d",&t);
    while(t--){
        scanf("%ld %ld",&x,&y);
        y-=x;
        n=1;
        while(1){
            d=n*n+n;
            if(d>=y)break;
            ++n;
        }
        n*=2;
        if(d-n/2>=y)--n;
        printf("%d",n);
    }
}