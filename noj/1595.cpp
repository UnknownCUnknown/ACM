/*************************************************************************
	> File Name: 1595.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一 12/29 15:52:20 2014
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
char a[10],b[10],sum[10];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s %s %s",a,b,sum);
        int l1=0,r=0,l2=0;
        int size1=(int)strlen(a);
        int size2=(int)strlen(b);
        int size3=(int)strlen(sum);
        int ans;
        bool flag=false;
        for(ans=16;ans>=2;--ans){
            l1=l2=r=0;
            int i;
            for(i=0;i<size1;++i){
                if(a[i]>=ans+'0') break;
                l1*=ans;
                l1+=a[i]-'0';
            }
            if(i!=size1) break;
            for(i=0;i<size2;++i){
                if(b[i]>=ans+'0') break;
                l2*=ans;
                l2+=b[i]-'0';
            }
            if(i!=size2) break;
            for(i=0;i<size3;++i){
                if(sum[i]>=ans+'0') break;
                r*=ans;
                r+=sum[i]-'0';
            }
            if(i!=size3) break;
            if(l1+l2==r){
                printf("%d\n",ans);
                flag=true;
                break;
            }
        }    
        if(!flag){
            printf("0\n");
        }
    }
    return 0;
}
