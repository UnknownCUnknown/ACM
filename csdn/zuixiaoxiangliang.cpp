/*************************************************************************
	> File Name: zuixiaoxiangliang.cpp
	> Author: 
	> Mail: 
	> Created Time: 日 12/14 10:55:47 2014
 ************************************************************************/

#include<iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long a[100010];
long long b[100010];
int main(){
    int num;
    while(~scanf("%d",&num)){
        for(int i=0;i<num;++i){
            scanf("%lld",&a[i]);
        }
        for(int i=0;i<num;++i){
            scanf("%lld",&b[i]);
        }
        sort(a,a+num);
        sort(b,b+num);
        long long sum=0;
        for(int i=0;i<num;++i){
            sum+=a[i]*b[num-1-i];
        }
        printf("%lld\n",sum);
    }
    return 0;
}
