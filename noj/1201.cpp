/*
 * 发现0~（x*10+9）的时候个位数正好是0到9*x
 * 所以将n减到模10余9
 * 然后处理非个位数，就是n/10的结果*10
 * 递归可解
 * solve是暴力解法，显然会T，用来对拍
 * solve2是递归解法 可过
 * noj1201
 */
/*************************************************************************
	> File Name: 1201.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二 12/16 17:49:57 2014
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
int ans[10];
void solve(int n){
    for(int i=1;i<=n;++i){
        int tmp=i;
        while(tmp){
            ++ans[tmp%10];
            tmp/=10;
        }
    }
}
void solve2(int n,int sign){
    if(n<10){
        for(int i=1;i<=n;++i){
            ans[i]+=sign;
        }
    }
    else{
        while(n%10!=9){
            int tmp=n;
            while(tmp){
                ans[tmp%10]+=sign;
                tmp/=10;
            }
            --n;
        }
        if(n<10){
            for(int i=1;i<=9;++i){
                ans[i]+=sign;
            }
            return;
        }
        for(int i=0;i<=9;++i){
            ans[i]+=(1+n/10)*sign;
        }
        ans[0]-=sign;
        solve2(n/10,sign*10);
    }
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        memset(ans,0,sizeof ans);
        solve2(n,1);
        for(int i=0;i<=9;++i){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
