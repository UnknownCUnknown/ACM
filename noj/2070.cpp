#include <cstdio>
int f[56];
int main(){
    f[1]=1;f[2]=2;f[3]=3;for(int i=4;i<=55;++i) f[i]=f[i-3]+f[i-1];
    int T;scanf("%d",&T);
    while(T--){int tmp;scanf("%d",&tmp);printf("%d\n",f[tmp]);}
    return 0;
}
