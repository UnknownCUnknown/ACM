/*************************************************************************
	> File Name: b_.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四 12/25 01:54:57 2014
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
#define DO double
#define REP(i,n) for (int i=1;i<=n;++i)
int n,m;
int a[5050];
int t[5050];
DO ans;
DO quc[5050],p[5050];
DO f[5050][5050];
#define eps 1e-9
int main() 
{
    scanf("%d%d",&n,&m);
    REP(i,n) 
    {
        scanf("%d%d",&a[i],&t[i]);
        p[i]=(DO) a[i]/100.0;
    }
    quc[0]=1;
    REP(i,m) quc[i]=quc[i-1]*(1.0-p[i]);
    f[0][0]=1;
    double pre=0;
    REP(i,n) 
    {
        pre=ans;
        DO tmp=0;
        quc[0]=1;
        REP(j,m) 
        {
            quc[j]=quc[j-1]*(1.0-p[i]);
            tmp*=(1.0-p[i]);
            tmp+=f[i-1][j-1]*p[i];
            tmp-=(j>=t[i]) ? f[i-1][j-t[i]]*p[i]*quc[t[i]-1] :0;
            f[i][j]=tmp;
            f[i][j]+= (j>=t[i]) ?f[i-1][j-t[i]]*quc[t[i]-1] :0;
            ans+=f[i][j];
        }
        if(fabs(ans-pre)<=eps) break;
    }
    printf("%.10lf\n",ans);
    return 0;
}
