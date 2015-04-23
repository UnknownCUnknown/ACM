/*************************************************************************
	> File Name: d.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 三 12/31 01:01:13 2014
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
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define sqr(x) ((x)*(x))
#define sz(x) ((int)(x).size())
#define clr(a,v) memset(a,v,sizeof(a))
#define pb push_back
#define mp make_pair

#define lson x+x,l,y
#define rson x+x+1,y+1,r

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<long long, long long> PLL;

#define INF 1000000000
#define EPS (double)1e-9
const int maxn = 100000 + 10;
int n;
vector<pair<PII, int> > edges;
vector<int> e[maxn];
int cnt[maxn], dep[maxn];
void dfs(int u, int f, int d) {
    cnt[u] = 1;
    dep[u] = d;
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        if (v == f) continue;
        dfs(v, u, d+1);
        cnt[u] += cnt[v];
    }
}

double calc(int u, int x) {
    int up = n-cnt[u];
    int down = cnt[u];
    double ans = 0;
    // down 2, up 1
    if (down >= 2 && up >= 1) {
        ans += 6.0*down/n*(down-1)/(n-1)*up/(n-2)*x;
    }
    // down 1, up 2
    if (down >= 1 && up >= 2) {
        ans += 6.0*up/n*(up-1)/(n-1)*down/(n-2)*x;

    }
    return ans;
}

int main(int argc, char *argv[])
{
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b, l;
        scanf("%d%d%d", &a, &b, &l);
        e[a].push_back(b);
        e[b].push_back(a);
        edges.push_back(make_pair(mp(a,b), l));
    }

    dfs(1, 0, 1);

    double ans = 0;

    for (int i = 0; i < n-1; i++) {
        int a = edges[i].first.first,
            b = edges[i].first.second,
            l = edges[i].second;
        if (dep[a] < dep[b])
            ans += calc(b, l);
        else
            ans += calc(a, l);
    }
    int q; cin >> q;
    rep(ccc,1,q)
    {
        int r, w;
        scanf("%d%d", &r, &w); r--;
        int dec = edges[r].second - w;
        edges[r].second = w;
        int a = edges[r].first.first,
            b = edges[r].first.second;
        if (dep[a] < dep[b])
            ans -= calc(b, dec);
        else
            ans -= calc(a, dec);
        printf("%.12f\n", ans);
    }
    return 0;
}
