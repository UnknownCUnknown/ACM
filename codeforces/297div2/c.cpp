/*************************************************************************
	> File Name: c.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  3/27 01:22:22 2015
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
long long n;
long long len[100010];
bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    scanf("%I64d",&n);
    for(int i=0;i<n;++i){
        scanf("%I64d",len+i);
    }
    sort(len,len+n,cmp);
    long long ans=0;
    long long flag=0;
    long long a,b;
    for(int i=0;i<n;++i){
        if(len[i]==len[i+1]){
            if(flag==0){
                a=len[i];
                flag=1;
            }
            else{
                b=len[i];
                ans+=a*b;
                flag=0;
            }
            ++i;
        } 
        else if(len[i]-1==len[i+1]){
            if(flag==0){
                a=len[i]-1;
                flag=1;
            }
            else{
                b=len[i]-1;
                ans+=a*b;
                flag=0;
            }
            ++i;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}
