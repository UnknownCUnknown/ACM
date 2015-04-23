/*************************************************************************
	> File Name: 1059.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 六 12/27 15:03:45 2014
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
bool haha[1000010];
int a[5010];
int get_val()
{
    int ret=0;
    char c;
    while((c=getchar())!=' '&&c!='\n')
        ret=ret*10+c-'0';
    return ret;
}
int main(){
    int n;
    memset(haha,false,sizeof haha);
    n=get_val();
    for(int i=0;i<n;++i){
        a[i]=get_val();
    }
    if(n==1){
        printf("1\n");
        return 0;
    }
    haha[1]=true;
    int First=n;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            int tmp=fabs(a[i]-a[j]);
            if(haha[tmp]) continue;
            haha[tmp]=true;
            while(haha[First]) ++First;
            for(int k=First;k*k<=tmp;++k){
                if((!haha[k]||!haha[tmp/k])&&tmp%k==0){
                    haha[k]=true;
                    haha[tmp/k]=true;
                    while(haha[First]) ++First;
                }
            }
        }
    }
    printf("%d\n",First);
    return 0;
}
