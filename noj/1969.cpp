/*************************************************************************
	> File Name: 1969.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一  2/ 2 09:24:27 2015
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
int T;
int attack[10];
int hp[10];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i){
            int tmp;
            scanf("%d%d",attack+i,&tmp);
        }
        for(int i=0;i<m;++i){
            int tmp;
            scanf("%d%d",&tmp,hp+i);
        }
        sort(attack,attack+n,cmp);
        sort(hp,hp+m,cmp);
        int top=0;
        bool flag=false;
        for(int i=0;i<n;++i){
            if(attack[i]>=hp[top]){
                ++top;
                if(top==m){
                    flag=true;
                    printf("YES\n");
                    break;
                }
            }
            else {
                hp[top]-=attack[i];   
            }
        }
        if(!flag) printf("NO\n");
    }
    return 0;
}
