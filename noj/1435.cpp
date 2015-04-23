/*************************************************************************
	> File Name: 1435.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二  1/20 08:06:41 2015
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
long long C[1010][1010];
void init(){
    memset(C,0,sizeof C);
    for(int i=0;i<=1000;++i){
        C[i][0]=1;
    }
    for(int i=1;i<=1000;++i){
        for(int j=1;j<=i;++j){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            C[i][j]%=12345;
            //printf("%d %d %lld\n",i,j,C[i][j]);
        }
    }
}
int main(){
    long long n;
    init();
    while(~scanf("%lld",&n)){
        long long ans=0;
        for(int i=0;i<=n;i+=2){
            long long tmp=C[n][i];
            if(i>2) tmp=tmp*2%12345;
            ans+=tmp;
            ans%=12345;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
