/*************************************************************************
	> File Name: b.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  4/ 5 00:52:03 2015
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
int n;
int a[15][3000];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<(1<<(i+1));++j){
            scanf("%d",&a[i][j]);
        }
    }
    int ans=0;
    for(int i=n-1;i>=0;--i){
        for(int j=0;j<(1<<(i+1));j+=2)
        {
            int tmp=max(a[i][j],a[i][j+1]);
            ans-=a[i][j]-tmp+a[i][j+1]-tmp;
            if(i!=0)
                a[i-1][j/2]+=tmp;
        }
    }
    printf("%d\n",ans);
    return 0;
}
