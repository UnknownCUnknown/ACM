/*************************************************************************
	> File Name: c.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二 12/30 23:42:02 2014
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
using namespace std;
int n,m;
int w[510];
int haha[510];
int xulie[510];
int mei[1000];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d",w+i);
    }
    memset(haha,0,sizeof haha);
    int cnt=0;
    for(int i=0;i<m;++i){
        scanf("%d",mei+i);
        if(haha[mei[i]]==0){
            xulie[cnt]=mei[i];
            ++cnt;
            haha[mei[i]]=1;
        }
    }
    int ans=0;
    for(int i=0;i<m;++i){
        int tmp=0;
        for(int j=0;j<cnt;++j){
            if(mei[i]!=xulie[j]){
                tmp+=w[xulie[j]-1];
            }
            else {
                int tt=xulie[j];
                for(int k=j;k>=1;--k){
                    xulie[k]=xulie[k-1];
                }
                xulie[0]=tt;
                break; 
            }
        }
        ans+=tmp;
    }
    printf("%d\n",ans);
    return 0;
}
