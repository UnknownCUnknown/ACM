/*
 * 告知两人的攻速，询问致死的伤害是谁打出的
 * 可以预处理出1s内所有攻击的属主
 * 用小数存可能精度不够，所以将所有小数乘上x*y转换成整数，排序后遍历，判断第几下攻击是谁的
 * 如果攻击属于两个人，就输出Both
 * 处理出1s内的合攻击力，将生命值对合攻击力取余，只判断1s内的情况
 */
/*************************************************************************
	> File Name: 492D.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二 12/16 15:31:06 2014
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
long long n,x,y;
int attack[2000010];
int main(){
    scanf("%I64d %I64d %I64d",&n,&x,&y);
    long long sum=x+y;
    vector<long long> k;
    for(long long i=1;i<=x;++i){
        k.push_back(y*i);
    }
    for(long long i=1;i<=y;++i){
        k.push_back(x*i);
    }
    sort(k.begin(),k.end());
    memset(attack, 0, sizeof(attack));
    int cnt=1;
    for(vector<long long>::iterator i=k.begin();i!=k.end();++i){
        if((*i)%x==0){
            if((*i)%y==0){
                attack[cnt]=3;
                ++cnt;
            }
            else {
                attack[cnt]=2;
                ++cnt;
            }
        }
        else {
            attack[cnt]=1;
            ++cnt;
        }
    }
    while (n--) {
        long long tmp;
        scanf("%I64d",&tmp);
        tmp%=sum;
        if(x==y){
            printf("Both\n");
            continue;
        }
        else if(tmp==0){
            printf("Both\n");
            continue;
        }
        else {
            if(attack[tmp]==1){
                printf("Vanya\n");
            }
            else if(attack[tmp]==2){
                printf("Vova\n");
            }
            else {
                printf("Both\n");
            }
        }
    }
    return 0;
}
