/*************************************************************************
	> File Name: e.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/26 19:07:07 2014
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
struct qujian{
    int left,right;
};
qujian a[100010];
bool cmp(qujian a,qujian b){
    if(a.right!=b.right){
        return a.right<b.right;
    }
    else {
        return a.left>b.left;
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%d%d",&a[i].left,&a[i].right);
        }
        sort(a,a+n,cmp);
        int ans=0;
        int now=0;
        for(int i=0;i<n;++i){
            if(now<a[i].left){
                now=a[i].right;
                ++ans;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
