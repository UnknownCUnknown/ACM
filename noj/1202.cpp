/*************************************************************************
	> File Name: 1202.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二 12/16 19:07:51 2014
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
char s[10];
long long C(long long m,long long n){
    long long res=1;
    for(long long i=0;i<n;++i){
        res*=m-i;
    }
    for(long long i=2;i<=n;++i){
        res/=i;
    }
    return res;
}
int ok=0;
int main(){
    int T;
    while(scanf("%d",&T)!=EOF){
        while(T--){
            scanf("%s",s);
            int size=(int)strlen(s);
            ok=0;
            for(int i=0;i<size;++i){
                if(!isalpha(s[i])){
                    printf("0\n");
                    ok=1;
                    break;
                }
            }
            if(ok) continue;
            for(int i=1;i<size;++i){
                if(s[i]>s[i-1]) continue;
                else {
                    printf("0\n");
                    ok=1;
                    break;
                }
            }
            if(ok) continue;
            long long ans=0;
            for(long long i=1;i<=size-1;++i){
                ans+=C(26,i);
            }
            for(long long i=0;i<size;++i){
                for(long long j=(i==0?'a':(s[i-1]+1));j<s[i];++j){
                    ans+=C(25-(j-'a'),size-1-i);
                }
            }
            ++ans;
            cout<<ans<<endl;
        }
        printf("\n");
    }
    return 0;
}
