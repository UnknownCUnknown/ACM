/*************************************************************************
	> File Name: lingleibianjijuli.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/15 11:59:37 2014
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
int m,n;
int a[1010][1010];
char s1[1010];
char s2[1010];
int LCS(const char *s1,const char *s2){
    m=(int)strlen(s1);
    n=(int)strlen(s2);
    int i,j;
    a[0][0]=0;
    for(i=1;i<=m;++i) a[i][0]=0;
    for(i=1;i<=n;++i) a[0][i]=0;
    for(i=1;i<=m;++i){
        for(j=1;j<=n;++j){
            if(s1[i-1]==s2[j-1]) a[i][j]=a[i-1][j-1]+1;
            else if(a[i-1][j]>a[i][j-1]) a[i][j]=a[i-1][j];
            else a[i][j]=a[i][j-1];
        }
    }
    return a[m][n];
}
int main(){
    while(scanf("%s%s",s1,s2)!=EOF){
        int k=LCS(s1,s2);
        int ans=n-k+m-k;
        printf("%d\n",ans);
    }
    return 0;
}
