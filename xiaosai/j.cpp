/*************************************************************************
	> File Name: j.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  3/29 13:37:07 2015
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
int n,m;
int cnt;
int a[15];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        cnt=0;
        int ans=0;
        for(int i=0;i<n;++i){
            int x,y;
            scanf("%d%d",&x,&y);
            int tmp=x-y;
            if(tmp>=1) {
                ans+=3;
            }
            else{
                if(tmp==0){
                    ans+=1;
                }
                a[cnt++]=tmp;
            }
        }
        sort(a,a+cnt,cmp);
        for(int i=0;i<cnt;++i){
            if(a[i]==0){
                if(m>=1){
                    --m;
                    ans+=2;
                }
            }
            else if(a[i]<0){
                if(a[i]+m>0){
                    m+=a[i];
                    --m;
                    ans+=3;
                }
                else if(a[i]+m==0){
                    m=0;
                    ans+=1;
                    break;
                }
                else {
                    break;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
