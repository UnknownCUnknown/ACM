/*************************************************************************
	> File Name: 1882.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/29 00:32:13 2014
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
int n,k;
char s[45];
long long kkk[45][45];
long long ans[45][10];
int main(){
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    int size=(int)strlen(s);
    for(int i=0;i<size;++i){
        long long tmp=0;
        for(int j=i;j<size;++j){
            tmp*=10;
            tmp+=s[j]-'0';
            kkk[i][j]=tmp;
        }
    }
    memset(ans,0,sizeof ans);
    for(int i=0;i<size;++i){
        ans[i][0]=kkk[0][i];
    }
    for(int i=0;i<size;++i){
        for(int j=1;j<=k;++j){
            for(int t=0;t<=i;++t){
                ans[i][j]=max(ans[i][j],ans[t][j-1]*kkk[t+1][i]);
            } 
        }
    }
    printf("%lld\n",ans[size-1][k]);
    return 0;
}
