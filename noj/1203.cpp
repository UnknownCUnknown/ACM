/*
 * noj1203
 * 最多约数问题
 * 正整数x的约数是能整除x的正整数。正整数x的约数个数记为div（x）。例如，1,2,5,10都是正整数10的约数，且div(10)=4。 对于给定的2个正整数a<=b，编程计算a与b之间约数个数最多的数。
 * a b的范围大约在1e9，遍历a，b且并计算约数的大小并比较必然不行
 * 一开始想用2，3，4，5。。。去筛那个区间，但是数组开不下
 * 所以先筛出100000以内的素因子
 * 首先我们知道正整数k分解质因数为k=p1^n1*p2^n2*p3^n3*...*pk^nk，则它的约数的个数则为(n1+1)*(n2+1)*(n3+1)*...*(nk+1)
 * 所以枚举素因子，看累积在[a,b]里的结果的约数的个数。
 * 也就是说，先枚举2*2*2*2...直到>b,然后2*2*2*..*3...这样枚举。
 * 大素数的问题，如果有一个大于100000的大素数怎么办，就看当前乘积是否小于a，且乘上prime[cnt-1]是否小于b，是则将当前约数乘2与Max比较，即假设有一个大素数。
 * 几个剪枝：
 * 1、当前乘积超过b，剪掉
 * 2、如果当前扫到素数5，设当前乘积为k，则约数最大能乘上2^q,q=log(b/now)/log(5);如果这样还比当前Max小，则直接剪掉。
 * 3、如果当前乘积为k<a，而(a-1)/k=b/k,则[a,b]不存在k的整数倍，直接剪掉。
 */
/*************************************************************************
	> File Name: 1203.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二 12/16 20:12:34 2014
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <string>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;
int maxn=100000;
int prime[100010];
bool isprime[100010];
int cnt=0;
void init(){
    memset(isprime,true,sizeof isprime);
    isprime[0]=isprime[1]=false;
    for(int i=2;i<=maxn;++i){
        if(isprime[i]){
            for(int j=i+i;j<=maxn;j+=i){
                if(isprime[j]) isprime[j]=false;
            }
        }  
    } 
    for(int i=2;i<=maxn;++i){
        if(isprime[i]){
            prime[cnt]=i;
            ++cnt;
        }
    }
}
long long a,b;
int Max=0;
long long qpow(long long x,long long n){
    long long result=1;
    while(n){
        if(n&1){
            result*=x;
        }
        x*=x;
        n/=2;
    }
    return result;
}
void dfs(int point,int cnt1,long long now,long long num){
    if(now>b){
        return;
    }
    long long k=num*(cnt1+1);
    if(now>=a){
        if(k>Max) Max=k;
    }
    for(int i=point;i<cnt&&prime[i]<=b;++i){
        long long tmp=now*prime[i];
        if(tmp>b) return;
        if(i==point){
            dfs(i,cnt1+1,tmp,num);
        }
        else {
            long long k=num*(cnt1+1);
            long long rest=b/now;
            long long q=log(rest)/log(prime[point]);
            long long r2q=qpow(2,q);
            if(r2q*k<=Max) return;
            if((a-1)/now==b/now) return;
            else if(now<a&&b/now>prime[cnt-1]){
                if(2*k>Max) Max=2*k;
            }
            dfs(i,1,tmp,k);
        }
    }
}
int main(){
    init();
    scanf("%lld %lld",&a,&b);
    dfs(0,0,1,1);
    printf("%d\n",Max);
    return 0;
}
