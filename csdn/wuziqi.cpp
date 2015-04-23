/*************************************************************************
	> File Name: wuziqi.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/15 21:36:47 2014
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
const int N = 20;
const int zx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int zy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m;
int g[N][N];

int isOverBound(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m) return 1;
    return 0;
}


int check(int c)
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            if (c != g[i][j]) continue;
            for (int k = 0; k < 8; ++k)
            {
                int ok = 1, nx = i, ny = j;
                for (int t = 1; t <= 5 && ok; ++t)
                {
                    if (isOverBound(nx, ny) || c != g[nx][ny]) ok = 0;
                    nx += zx[k];
                    ny += zy[k];
                }
                if (ok) return 1;
            }
        }
    return 0;
}

int main() {
    while (cin >> n >> m)
    {
        memset(g, -1, sizeof(g));
        cin.ignore();
        for (int i = 1; i <= n; ++i)
        {
            string s;
            getline(cin, s);
            for (int j = 1; j <= m; ++j)
                if ('0' == s[j - 1]) g[i][j] = 0;
                else if ('1' == s[j - 1]) g[i][j] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                if (g[i][j] != -1) continue;
                g[i][j] = 1;
                if (check(1)) ans = 1;
                g[i][j] = -1;
            }
        if (ans == 1)
        {
            cout << "YES" << endl;
            continue;
        }
        int tot = 0;
        int xx, yy;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                if (g[i][j] != -1) continue;
                g[i][j] = 0;
                if (check(0))
                {
                    tot++;
                    xx = i;
                    yy = j;
                }
                g[i][j] = -1;
            }
        if (tot >= 2)
        {
            cout << "NO" << endl;
            continue;
        }
        if (tot == 1)
        {
            g[xx][yy] = 1;
            tot = 0;
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j)
                {
                    if (g[i][j] != -1) continue;
                    g[i][j] = 1;
                    if (check(1)) tot++;
                    g[i][j] = -1;
                }
            ans = 0;
            if (tot >= 2) ans = 1;
        }
        else
        {
            ans = 0;
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j)
                {
                    if (g[i][j] != -1) continue;
                    g[i][j] = 1;
                    int cnt = 0;
                    for (int ii = 1; ii <= n; ++ii)
                        for (int jj = 1; jj <= m; ++jj)
                        {
                            if (g[ii][jj] != -1) continue;
                            g[ii][jj] = 1;
                            cnt += check(1);
                            g[ii][jj] = -1;
                        }
                    if (cnt >= 2) ans = 1;
                    g[i][j] = -1;
                }
        }
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
} 
