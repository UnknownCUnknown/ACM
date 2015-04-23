/*************************************************************************
	> File Name: a.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日 12/21 14:35:47 2014
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
struct shiyan{
    int value;
    int gailv;
};
shiyan a[15];
double dp[100];
double tmp[100];
int n;
double eps=1e-8;
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;++i){
            scanf("%d%d",&a[i].value,&a[i].gailv);
        }
        double ans=0;
        dp[0]=(double)(100-a[0].gailv)/100.0;
        dp[a[0].value]=(double)(a[0].gailv)/100.0;
        for(int i=1;i<n;++i){
            memcpy(tmp,dp,sizeof dp);
            printf("%g\n",tmp[10]);
            for(int j=0;j<27;++j){
                if(dp[j]>eps){
                    dp[j]+=(double)tmp[j]*(double)(100-a[i].gailv)/100.0;
                    dp[j+a[i].value]+=(double)tmp[j]*(double)(a[i].gailv)/100.0;
                    if(j+a[i].value>=27){
                        ans+=dp[j+a[i].value]*(i+1);
                        dp[j+a[i].value]=0;
                    }
                }    
            }
            for(int j=0;j<27;++j){
                printf("%d %d %g\n",i,j,dp[j]);
            }
        }
        printf("%.6f\n",ans);
    }
    return 0;
}
