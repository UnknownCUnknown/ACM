/*************************************************************************
	> File Name: 3.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六  4/11 14:36:24 2015
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
#include <iomanip>
#include <climits>
using namespace std;
int const MAX = 110;
int const INF = 0x3fffffff;

int n,m, nx, ny;
int link[MAX], lx[MAX], ly[MAX], slack[MAX];
int visx[MAX], visy[MAX], w[MAX][MAX];

int DFS(int x)
{
    visx[x] = 1;
    for(int y = 1; y <= ny; y++)
    {
        if(visy[y])
            continue;
        int t = lx[x] + ly[y] - w[x][y];
        if(t == 0)      
        {
            visy[y] = 1;
            if(link[y] == -1 || DFS(link[y]))
            {
                link[y] = x;
                return 1;
            }
        }
        else if(slack[y] > t) 
            slack[y] = t;
    }
    return 0;
}

int KM()
{
    memset(link, -1, sizeof(link));
    memset(ly, 0, sizeof(ly));
    for(int i = 1; i <= nx; i++)  
    {
        lx[i] = -INF;          
        for(int j = 1; j <= ny; j++)
            if(w[i][j] > lx[i])
                lx[i] = w[i][j];
    }
    for(int x = 1; x <= nx; x ++)
    {
        for(int i = 1; i <= ny; i ++)
            slack[i] = INF;
        while(true)
        {
            memset(visx, 0, sizeof(visx));
            memset(visy, 0, sizeof(visy));
            if(DFS(x))    
                break;  
            int d = INF;
            for(int i = 1; i <= ny; i++)
                if(!visy[i] && d > slack[i])
                    d = slack[i];
            for(int i = 1; i <= nx; i++)
                if(visx[i])
                    lx[i] -= d;
            for(int i = 1; i <= ny; i++) 
                if(visy[i])
                    ly[i] += d;
                else
                    slack[i] -= d;
        }
    }
    int res = 0;
    for(int i = 1; i <= ny; i++)
        if(link[i] > -1)
            res += w[link[i]][i];
    return res;
}

int main ()
{
    int T;
    scanf("%d", &T);
    for(int ca=1;ca<=T;++ca)
    {
        scanf("%d%d", &n,&m);
        nx = ny = min(n,m);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                scanf("%d", &w[i][j]);
                w[i][j]=-w[i][j];
            }
        int ans = KM();
        ans=-ans;
        if(n>m){
            for(int i=m+1;i<=n;++i){
                int tmp=-w[i][1];
                for(int j=2;j<=m;++j){
                    tmp=min(-w[i][j],tmp);
                }
                ans+=tmp;
            }
        }
        else if(n<m){
            for(int j=n+1;j<=m;++j){
                int tmp=-w[1][j];
                for(int i=2;i<=n;++i){
                    tmp=min(-w[i][j],tmp);
                }
                ans+=tmp;
            }
        }
        printf("Case %d: %d\n",ca, ans);
    }
    return 0;
}


