/*************************************************************************
	> File Name: a.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六  1/24 19:01:41 2015
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
struct ch{
    int value;
    int index;
};
bool cmp(ch a,ch b){
    return a.value>b.value;
}
ch child[10];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        memset(child,0,sizeof child);
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            int max=-1,tmp;
            for(int j=0;j<3;++j){
                scanf("%d",&tmp);
                if(tmp>max) max=tmp;
            }
            child[i].value=max;
            child[i].index=i+1;
        }
        sort(child,child+n,cmp);
        for(int i=0;i<n-1;++i){
            for(int j=0;j<n;++j){
                if(child[j].index==i+1){
                    printf("%d ",j+1);
                }
            }
        }
        for(int i=0;i<n;++i){
            if(child[i].index==n){
                printf("%d\n",i+1);
            }
        }
    }
    return 0;
}
