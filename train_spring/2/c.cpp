/*************************************************************************
	> File Name: c.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  3/20 18:41:34 2015
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
char s[110][15];
char g[110][110][15];
int g_num[110];
int ans[110][110];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%s%d",s[i],&g_num[i]);
            for(int j=0;j<g_num[i];++j){
                scanf("%s",g[i][j]);
            }
        }
        int filenum;
        scanf("%d",&filenum);
        memset(ans,-1,sizeof ans);
        for(int i=0;i<filenum;++i){
            char tmp[15];
            scanf("%s",tmp);
            char k[4];
            scanf("%s",k);
            scanf("%s",tmp);
            for(int j=0;j<n;++j){
                if(strcmp(s[j],tmp)==0){
                    ans[j][i]=k[0]-'0';
                    break;
                }
            }
            scanf("%s",tmp);
            for(int j=0;j<n;++j){
                if(ans[j][i]==-1){
                    int kkk;
                    for(kkk=0;kkk<g_num[j];++kkk){
                        if(strcmp(g[j][kkk],tmp)==0){
                            ans[j][i]=k[1]-'0';
                            break;
                        }
                    }
                    if(kkk==g_num[j]){
                        ans[j][i]=k[2]-'0';
                    }
                }   
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<filenum-1;++j){
                printf("%d ",ans[i][j]);
            }
            printf("%d\n",ans[i][filenum-1]);
        }
    }
    return 0;
}
