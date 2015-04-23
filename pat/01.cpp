/*************************************************************************
  > File Name: 01.cpp
  > Author: UnknownCUnknown
  > Mail: jsnjhcb@icloud.com
  > Created Time: 二  4/ 7 11:21:49 2015
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
int a[100010];
int main(){
    int n;
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int ans=0;
        int tmp=0;
        bool flag=false;
        for(int i=0;i<n;++i){
            scanf("%d",a+i);
            if(a[i]>=0){
                flag=true;
            }
            tmp+=a[i];
            if(ans<tmp){
                ans=tmp;
            }
            if(tmp<0){
                tmp=0;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
