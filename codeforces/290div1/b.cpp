/*************************************************************************
	> File Name: b.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二  2/ 3 00:36:33 2015
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
int gcd(int x,int y){
    if(x<y){
        int tmp=x;
        x=y;
        y=tmp;
    }
    if(y==0) return x;
    else return gcd(x%y,y);
}
int l[310];
int c[310];
int main(){
    int n;
    printf("%d\n",gcd(15015,gcd(10010,gcd(6006,gcd(2730,2310)))));
    scanf("%d",&n);
    int ans=200010;
    for(int i=0;i<n;++i){
        scanf("%d",l+i);
    }
    for(int i=0;i<n;++i){
        scanf("%d",c+i);
    }
    for(int i=0;i<n;++i){
        if(l[i]==1) {
            if(c[i]<ans) ans=c[i];
        }
        for(int j=i+1;j<n;++j){
            if(gcd(l[i],l[j])==1){
                int tmp=c[i]+c[j];
                if(c[i]+c[j]<ans) ans=c[i]+c[j];
            }
        }
    }
    if(ans==200010) printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}
