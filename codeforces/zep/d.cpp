/*************************************************************************
	> File Name: d.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  4/ 5 01:46:04 2015
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
char s[1000010];
int Next[1000010];
int n;
void preKMP(){
    int i,j;
    j=Next[0]=-1;
    i=0;
    while(i<n){
        while(-1!=j&&s[i]!=s[j]) j=Next[j];
        Next[++i]=++j;
    }
}
int k;
bool ans[1000010];
int kkk[1000010];
int main(){
    scanf("%d%d",&n,&k);
    if(k==1){
        for(int i=0;i<n;++i){
            printf("1");
        }
        printf("\n");
        return 0;
    }
    scanf("%s",s);
    memset(ans,false,sizeof ans);
    memset(kkk,0,sizeof kkk);
    preKMP();
    int befor=-10;
    for(int i=1;i<=n;++i){
        //printf("%d %d\n",i,Next[i]);
        int x=i-Next[i];
        int l=i;
        if(x==0) continue;
        else if(l%x==0&&i/x%k==0){
            ans[i]=true;
            kkk[i]=i/k;
        }
        else if(l%x==0&&i/x%(k+1)==0){
            ans[i]=true;
        }
        else{
            int x=i;
            while(Next[x]!=0){
                if(kkk[i-Next[x]]){
                    if(Next[x]<=kkk[i-Next[x]]){
                        ans[i]=true;
                        break;
                    }   
                }
                x=Next[x];
            }
        }
    }
    for(int i=1;i<=n;++i){
        printf("%d",ans[i]?1:0);
    }
    printf("\n");
    return 0;
}
