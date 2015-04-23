/*************************************************************************
	> File Name: b.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  3/29 11:13:14 2015
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
bool is[15][15];
int a[15];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i){
            a[i]=i;
        }
        a[n+1]=1;
        memset(is,false,sizeof is);
        for(int i=0;i<m;++i){
            int a,b;
            scanf("%d%d",&a,&b);
            is[a][b]=is[b][a]=true;
        }
        bool flag;
        do{
            flag=true;
            a[n+1]=a[1];
            for(int i=1;i<=n;++i){
                //printf("%d %d\n",a[i],a[i+1]);
                if(!is[a[i]][a[i+1]]){
                    flag=false;
                    break;
                }
            }
        }while(!flag&&next_permutation(a+1,a+n+1));
        //printf("%d\n",(int)flag);
        for(int i=1;i<=n;++i){
            printf("%d ",a[i]);
        }
        printf("%d\n",a[n+1]);
    }
    return 0;
}
