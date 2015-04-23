/*************************************************************************
	> File Name: 1921.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  1/22 12:00:41 2015
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
struct celuo{
    long long p,q;
    long long s;
};
celuo c[10010];
bool cmp(celuo a,celuo b){
    return a.p<b.p;
}
int main(){
    int n,t;
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;++i){
        scanf("%I64d%I64d",&c[i].p,&c[i].q);
        c[i].s=c[i].q*c[i].p;
    }
    sort(c,c+n,cmp);
    //for(int i=0;i<n;++i){
        //printf("%I64d\n",c[i].p);
    //}
    for(int i=0;i<t;++i){
        long long tmp;
        scanf("%I64d",&tmp);
        long long ans=1e15;
        for(int i=n-1;i>=0;--i){
            long long k;
            if(c[i].p>tmp){
                k=c[i].s;
                if(k<ans) ans=k;
            }    
            else {
                k=tmp*c[i].q;
                if(k<ans) ans=k;
                break;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
