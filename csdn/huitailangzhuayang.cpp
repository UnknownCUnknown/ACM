/*************************************************************************
	> File Name: huitailangzhuayang.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/15 13:27:41 2014
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
#define N 550
#define INF 0x0fffffff

int n, q, d;
//连接矩阵 
int Map[N][N];
//足迹 
int mark[N];
//子树表 
int Next[N][2];
//从父节点到本节点的消耗 
int vs[N];
int dp[N][N];
//递归建立从属关系 
void build(int root){
    int i, j;
    mark[root] = 1;
    for(i = j = 0; i < n && j < 2; i++){
        if(Map[root][i] >= 0 && mark[i] == 0){
            Next[root][j] = i;
            vs[i] = Map[root][i];
            build(i);
            j++;
        }
    }
}
//建立dp表 
void run(int root){
    int i, j, c1, c2;
    if(root < 0){//叶子的子节点,当递归run时,会走到这里 
        return;
    }
    c1 = Next[root][0], c2 = Next[root][1];//两子节点 
    run(c1);//先建立子dp表 
    run(c2);
    dp[root][1] = vs[root] * 2;//仅取根节点 
    if(c1 > 0 && c2 > 0){//双子都在 
        for(i = 1; i + 1 <= n; i++){
            int min = INF;
            for(j = 0; j <= i; j++){
                int v1 = c1 > 0 ? dp[c1][j] : INF;//INF表示不可选 
                int v2 = c2 > 0 ? dp[c2][i - j] : INF;
                if(v1 + v2 < min){
                    min = v1 + v2;
                }
            }
            dp[root][i + 1] = min + vs[root] * 2;
        }
    } else if(c1 > 0){
        for(i = 1; i + 1 <= n; i++){
            dp[root][i + 1] = dp[c1][i] + vs[root] * 2;
        }
    } else if(c2 > 0){
        for(i = 1; i + 1 <= n; i++){
            dp[root][i + 1] = dp[c2][i] + vs[root] * 2;
        }
    }
}

int main(void){
    int i, j;
    while(scanf("%d%d%d", &n, &q, &d), n != 0){
        //初始化 
        memset(mark, 0, sizeof(mark));
        for(i = 0; i < N; i++){
            Next[i][0] = Next[i][1] = -1;
            for(j = 0; j < N; j++){
                Map[i][j] = -1;
                dp[i][j] = INF;
            }
        }
        for(i = 0; i < N; i++){
            dp[i][0] = 0;
        }
        for(i = 1; i < n; i++){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            Map[a][b] = Map[b][a] = c;
        }
        
        build(0);
        vs[0] = d;//从家到0节点 
        run(0); 
        for(i = 0; i < q; i++){
            int t, m;
            scanf("%d%d", &t, &m);
            printf(dp[0][m] <= t ? "I love you\n" : "Go to the hell\n");
        }
    }
    return 0;
}
