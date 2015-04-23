/*************************************************************************
	> File Name: f.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/26 19:52:51 2014
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
int f[1100];
int w[1100];
int va[1100];
int main(){
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca){
        int A,B,n;
        scanf("%d%d%d",&A,&B,&n);
        for(int i=1;i<=n;++i){
            scanf("%d",&w[i]); 
        }       
        for(int i=1;i<=n;++i){
            scanf("%d",&va[i]);
        }
        bool flag = false;
        memset(f,0,sizeof f);
        for(int i=1;i<=n;++i){
            for(int v=A;v>=0;--v){
                if(v>=w[i])
                    f[v]=max(f[v],f[v-w[i]]+va[i]);
                if(f[v]>=B) {
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag||f[A]>=B) {
            printf("Case #%d: YES\n",ca);
        }
        else {
            printf("Case #%d: NO\n",ca);
        }
    }
    return 0;
}
