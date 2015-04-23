#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;
const int MAXN=600010;
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int wa[MAXN*3],wb[MAXN*3],wv[MAXN*3],wss[MAXN*3];
int c0(int *r,int a,int b)
{
    return r[a] == r[b] && r[a+1] == r[b+1] && r[a+2] == r[b+2];
}
int c12(int k,int *r,int a,int b)
{
    if(k == 2)
        return r[a] < r[b] || ( r[a] == r[b] && c12(1,r,a+1,b+1) );
    else return r[a] < r[b] || ( r[a] == r[b] && wv[a+1] < wv[b+1] );
}
void sort(int *r,int *a,int *b,int n,int m)
{
    int i;
    for(i = 0;i < n;i++)wv[i] = r[a[i]];
    for(i = 0;i < m;i++)wss[i] = 0;
    for(i = 0;i < n;i++)wss[wv[i]]++;
    for(i = 1;i < m;i++)wss[i] += wss[i-1];
    for(i = n-1;i >= 0;i--)
        b[--wss[wv[i]]] = a[i];
}
void dc3(int *r,int *sa,int n,int m)
{
    int i, j, *rn = r + n;
    int *san = sa + n, ta = 0, tb = (n+1)/3, tbc = 0, p;
    r[n] = r[n+1] = 0;
    for(i = 0;i < n;i++)if(i %3 != 0)wa[tbc++] = i;
    sort(r + 2, wa, wb, tbc, m);
    sort(r + 1, wb, wa, tbc, m);
    sort(r, wa, wb, tbc, m);
    for(p = 1, rn[F(wb[0])] = 0, i = 1;i < tbc;i++)
        rn[F(wb[i])] = c0(r, wb[i-1], wb[i]) ? p - 1 : p++;
    if(p < tbc)dc3(rn,san,tbc,p);
    else for(i = 0;i < tbc;i++)san[rn[i]] = i;
    for(i = 0;i < tbc;i++) if(san[i] < tb)wb[ta++] = san[i] * 3;
    if(n % 3 == 1)wb[ta++] = n - 1;
    sort(r, wb, wa, ta, m);
    for(i = 0;i < tbc;i++)wv[wb[i] = G(san[i])] = i;
    for(i = 0, j = 0, p = 0;i < ta && j < tbc;p++)
        sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
    for(;i < ta;p++)sa[p] = wa[i++];
    for(;j < tbc;p++)sa[p] = wb[j++];
}
void da(int str[],int sa[],int Rank[],int height[],int n,int m)
{
    for(int i = n;i < n*3;i++)
        str[i] = 0;
    dc3(str, sa, n+1, m);
    int i,j,k = 0;
    for(i = 0;i <= n;i++)Rank[sa[i]] = i;
    for(i = 0;i < n; i++)
    {
        if(k) k--;
        j = sa[Rank[i]-1];
        while(str[i+k] == str[j+k]) k++;
        height[Rank[i]] = k;
    }
}


int Rank[MAXN],height[MAXN];
int RMQ[MAXN];
int mm[MAXN];
int best[20][MAXN];
void initRMQ(int n)
{
    mm[0]=-1;
    for(int i=1;i<=n;i++)
        mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
    for(int i=1;i<=n;i++)best[0][i]=i;
    for(int i=1;i<=mm[n];i++)
        for(int j=1;j+(1<<i)-1<=n;j++)
        {
            int a=best[i-1][j];
            int b=best[i-1][j+(1<<(i-1))];
            if(RMQ[a]<RMQ[b])best[i][j]=a;
            else best[i][j]=b;
        }
}
int askRMQ(int a,int b)
{
    int t;
    t=mm[b-a+1];
    b-=(1<<t)-1;
    a=best[t][a];b=best[t][b];
    return RMQ[a]<RMQ[b]?a:b;
}
int lcp(int a,int b)
{
    a=Rank[a];b=Rank[b];
    if(a>b)swap(a,b);
    return height[askRMQ(a+1,b)];
}
char A[MAXN],B[MAXN];
int r[MAXN];
int sa[MAXN];

int main()
{
    int k;
    while (~scanf("%s%s",A,B))
    {
        scanf("%d", &k);
        int len1 = strlen(A);
        int len2 = strlen(B);
        if(len1 < len2)
        {
            printf("0\n");
            continue;
        }
        int n = len1+len2+1;
        for(int i = 0;i < len1;i++)r[i] = A[i];
        for(int i = 0;i < len2;i++)r[len1+1+i] = B[i];
        r[len1] = 1;
        r[n] = 0;
        da(r,sa,Rank,height,n,128);
        for(int i = 1;i <= n;i++)RMQ[i] = height[i];
        initRMQ(n);
        int ans = 0;
        for(int i = 0;i <= len1-len2;i++)
        {
            int st = i;
            int ed = len1 + 1;
            int tmp = lcp(st,ed);
            st += tmp;
            ed += tmp;
            if(ed >= n)
            {
                ans++;
                continue;
            }
            if (!k) continue;
            st++;
            ed++;
            if(ed >= n)
            {
                ans++;
                continue;
            }
            tmp = lcp(st,ed);
            st += tmp;
            ed += tmp;
            if(ed >= n)
            {
                ans++;
                continue;
            }
            if (1 == k) continue;
            st++;
            ed++;
            if(ed >= n)
            {
                ans++;
                continue;
            }
            tmp = lcp(st,ed);
            st += tmp;
            ed += tmp;
            if(ed >= n)
            {
                ans++;
                continue;
            }
            if (2 == k) continue;
            st++;
            ed++;
            if(ed >= n)
            {
                ans++;
                continue;
            }
            tmp = lcp(st,ed);
            st += tmp;
            ed += tmp;
            if(ed >= n)
            {
                ans++;
                continue;
            }
            if (3 == k) continue;
            st++;
            ed++;
            if(ed >= n)
            {
                ans++;
                continue;
            }
            tmp = lcp(st,ed);
            st += tmp;
            ed += tmp;
            if(ed >= n)
            {
                ans++;
                continue;
            }
            if (4 == k) continue;
            st++;
            ed++;
            if(ed >= n)
            {
                ans++;
                continue;
            }
            tmp = lcp(st,ed);
            st += tmp;
            ed += tmp;
            if(ed >= n)
            {
                ans++;
                continue;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
