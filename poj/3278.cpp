/*************************************************************************
	> File Name: 3278.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一  1/19 21:36:28 2015
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
int a,b;
int step;
int flag=false;
struct num{
    int value;
    int cnt;
    num(){

    }
    num(int a,int b){
        value=a;
        cnt=b;
    }
};
bool vis[200010];
queue<num> q;
num ans;
void bfs(){
    memset(vis,false,sizeof vis);
    while(!q.empty()){
        num tmp=q.front();
        q.pop();
        if(tmp.value==b) {
            ans=tmp;
            break;
        }
        for(int i=0;i<3;++i){
            num k;
            k.cnt=tmp.cnt+1;
            if(i==0) {
                k.value=tmp.value+1;
            }
            else if(i==1){
                k.value=tmp.value-1;
            }
            else{
                k.value=tmp.value*2;
            }
            if(k.value>200000||k.value<0) continue;
            if(vis[k.value]) continue;
            else vis[k.value]=true;
            q.push(k);
            if(k.value==b) {
                flag=true;
                ans=k;
                break;
            }
        }
        if(flag) break;
    }
}
int main(){
    scanf("%d%d",&a,&b);
    q.push(num(a,0));
    bfs();
    printf("%d\n",ans.cnt);
    return 0;
}
