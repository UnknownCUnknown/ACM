/*************************************************************************
    > File Name: 1204.cpp
    > Author: UnknownCUnknown
    > Mail: jsnjhcb@icloud.com
    > Created Time: 三 12/17 15:26:02 2014
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
struct table{
    int value[110];
};
table Copy[110];
table Map[110];
table target[110];
table tmp[110];
table row_copy[110];
int n,m;
bool is[110];
bool cmp(table a,table b){
    for(int i=0;i<m;++i){
        if(a.value[i]==b.value[i]) continue;
        else return a.value[i]<b.value[i];
    }
    return a.value[0]<b.value[0];
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                scanf("%d",&Map[i].value[j]);
                Copy[j].value[i]=Map[i].value[j];
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                scanf("%d",&target[i].value[j]);
                row_copy[j].value[i]=target[i].value[j];
            }
        }
        memcpy()
        sort(row_copy,row_copy+m,cmp);
        int cnt=0;
        int ans=-1;
        for(int i=0;i<m;++i){
            memset(is,false,sizeof is);
            cnt=0;
            for(int j=0;j<n;++j){
                if(Copy[i].value[j]!=row_copy[i].value[j]){
                    is[j]=true;
                    for(int k=0;k<m;++k){
                        Copy[k].value[j]=Copy[k].value[j]==0?1:0;
                    }
                    ++cnt;
                }
            } 
            sort(Copy,Copy+m,cmp);
            int i,j;
            for(i=0;i<n;++i){
                for(j=0;j<m;++j){
                    if(Copy[j].value[i]!=row_copy[j].value[i]) break;
                }
                if(j!=m) break;
            } 
            if(i==n){
                
            }
        }
    }
    return 0;
}

