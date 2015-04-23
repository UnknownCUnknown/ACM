/*************************************************************************
    > File Name: zuidadehuafen.cpp
    > Author: UnknownCUnknown
    > Mail: jsnjhcb@icloud.com
    > Created Time: 一 12/15 00:54:57 2014
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
using namespace std;
int n;
int h[100010];
int fac[100010];
set<int> jingdianshu;
bool judge(int len){
    int st=1,ed=len;
    while (ed<=n) {
        //printf("st=%d ed=%d\n",st,ed);
        if(jingdianshu.lower_bound(st)==jingdianshu.upper_bound(ed)) return false;
        st+=len,ed+=len;
    }
    return true;
}
int main(){
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;++i){
            scanf("%d",h+i);
        }
        jingdianshu.clear();
        for(int i=2;i<n;++i){
            if(h[i]>h[i-1]&&h[i]>h[i+1]){
                jingdianshu.insert(i);
            }
        }
        if(jingdianshu.size()==0) {
            printf("0\n");
            continue;
        }
        int cnt=0;
        for(int i=1;i*i<=n;++i){
            if(n%i==0){
                int tmp=n/i;
                if(tmp!=i){
                    fac[cnt]=i;
                    ++cnt;
                    fac[cnt]=tmp;
                    ++cnt;
                }
                else {
                    fac[cnt]=i;
                    ++cnt;
                }
            }
        }
        sort(fac,fac+cnt);
        int l=0,h=cnt-1;
        int ans=1;
        while(l<=h){
            int mid=(l+h)/2;
           // printf("%d\n",fac[mid]);
            if(judge(fac[mid])){
                ans=fac[mid];
             //   printf("mid=%d\n",fac[mid]);
                h=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        printf("%d\n",n/ans);
    }
    return 0;
}
