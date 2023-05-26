#include<stdio.h>
long long i,n,d[99]={0,1},a;main(){scanf("%d",&n);for(i=2;i<n;++i){d[i]=d[i-1]+d[i-2];}a=n>2?d[n-1]+d[n-2]:1;printf("%lld",a);}