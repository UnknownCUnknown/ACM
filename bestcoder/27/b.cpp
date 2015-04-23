/*************************************************************************
	> File Name: b.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六  1/24 19:20:27 2015
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
int T;
int n,m;
long long a[100010];
long long ans;
long long res[100010];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof a);
        memset(res,0,sizeof res);
        for(int i=1;i<n;++i){
            scanf("%lld",a+i);
            res[i]=a[i]+res[i-1];
        }
        ans=0;
        for(int i=1;i<=m;++i){
            ans=0;
            int be=(i-1)%n+1;
            int l,r;
            scanf("%d%d",&l,&r);
            if(l<be){
                ans+=res[n-1]-res[be-1];
                ans+=res[n-1]-res[l-1];
                if(l>=r){
                    ans+=res[l-1]-res[r-1];
                }
                else {
                    ans+=res[l-1]-res[0];
                    ans+=res[r-1]-res[0];
                }
            }
            else {
                ans+=res[l-1]-res[be-1];
                if(l<=r){
                    ans+=res[r-1]-res[l-1];   
                }
                else{
                    ans+=res[n-1]-res[l-1];
                    ans+=res[n-1]-res[r-1];
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
