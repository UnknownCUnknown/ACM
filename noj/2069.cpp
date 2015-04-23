/*************************************************************************
	> File Name: 2069.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二 12/30 19:43:36 2014
 ************************************************************************/

#include <cstdio>
int gcd(int a,int b){
    return a%b?gcd(b,a%b):b;
}
int a[10];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<3;++i){
            scanf("%d",a+i);
        }
        int t=gcd(a[0],gcd(a[1],a[2]));
        for(int i=0;i<3;++i){
            a[i]/=t;
        }
        int k,i;
        for(i=0;i<3;++i){
            k=gcd(a[i],t);
            while(k!=1){
                a[i]/=k;
                k=gcd(a[i],t);
            }
            if(a[i]!=1){
                break;
            }
        }
        if(i==3)
            puts("YES");
        else puts("NO");
    }
    return 0;
}
