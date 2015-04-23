/*
 * lingxing[i][j]表示与点i和点j都相连的点的数量
 * 遍历lingxing对于每个值tmp给结果加上tmp*(tmp-1)/2
 */
/*************************************************************************
	> File Name: 489D.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二 12/16 16:29:53 2014
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
vector<int> x[3010];
vector<int> y[3010];
int haha[3010][3010];
int lingxing[3010][3010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int a,b;
    while (m--) {
        scanf("%d%d",&a,&b);
        haha[a][b]=1;
        x[a].push_back(b);
        y[b].push_back(a);
    }
    memset(lingxing, 0, sizeof(lingxing));
    for(int i=1;i<=n;++i){
        for(vector<int>::iterator j=x[i].begin();j!=x[i].end();++j){
            for(vector<int>::iterator k=y[i].begin();k!=y[i].end();++k){
                ++lingxing[*j][*k];
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i==j) continue;
            long long tmp=lingxing[i][j];
            tmp=tmp*(tmp-1)/2;
            ans+=tmp;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}
