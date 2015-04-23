/*************************************************************************
	> File Name: 101.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 三  3/11 15:28:23 2015
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
int n;
int vis[110];
struct point{
    int left,right;
    int index;
};
point p[110];
int ans[110];
bool opt[110];
int haha[7];
int flag_point[10];
int main(){
    scanf("%d",&n);
    memset(haha,0,sizeof haha);
    for(int i=0;i<n;++i){
        scanf("%d%d",&p[i].left,&p[i].right);
        p[i].index=i;
        ++haha[p[i].left];
        ++haha[p[i].right];
    }
    int odd=0;
    for(int i=0;i<=6;++i){
        if(haha[i]&1){
            if(odd==2){
                ++odd;
                break;
            }
            else{
                flag_point[odd]=i;
                ++odd;
            }
        }
    }
    //printf("%d\n",flag_point[0]);
    bool ok=true;
    if(odd==0){
        int num=0;
        ans[num]=1;
        opt[num]=true;
        ++num;
        vis[0]=true;
        int need=p[0].right;
        while(num!=n){
            int i;
            for(i=0;i<n;++i){
                if(!vis[i]){
                    if(p[i].left==need){
                        ans[num]=i+1;
                        opt[num]=true;
                        need=p[i].right;
                        vis[i]=true;
                        ++num;
                        break;
                    }
                    else if(p[i].right==need)
                    {
                        ans[num]=i+1;
                        opt[num]=false;
                        need=p[i].left;
                        ++num;
                        vis[i]=true;
                        break;
                    }
                }
            }
            if(i==n){
                ok=false; 
                break;
            }
        }
    }
    else if(odd==2){
        int num=0;
        int need;
        for(int i=0;i<n;++i){
            if(p[i].left==flag_point[0]){
                ans[num]=i+1;
                opt[num]=true;
                need=p[i].right;
                vis[i]=true;
                break;
            }
            else if(p[i].right==flag_point[0]){
                ans[num]=i+1;
                opt[num]=false;
                need=p[i].left;
                vis[i]=true;
                break;
            }
        }
        int fi=0;
        int en=n-1;
        //cout<<flag_point[1]<<endl;
        while(fi<en){
            while(p[en].left==flag_point[1]||p[en].right==flag_point[1]){
                --en;
            }
            //cout<<fi<<" "<<en<<endl;
            if(fi>=en) break;
            else{
                if(p[fi].left==flag_point[1]||p[fi].right==flag_point[1]){
                    swap(p[fi],p[en]);
                }
                ++fi;
            }
        }
        //cout<<p[2].left<<" "<<p[2].right<<endl;
        //printf("%d\n",need);
        ++num;
        while(num!=n){
            //printf("%d\n",num);
            int i;
            for(i=0;i<n;++i){
                //printf("i=%d\n",i);
                if(!vis[p[i].index]){
                    if(p[i].left==need){
                        ans[num]=p[i].index+1;
                        opt[num]=true;
                        need=p[i].right;
                        vis[p[i].index]=true;
                        ++num;
                        break;
                    }
                    else if(p[i].right==need)
                    {
                        ans[num]=p[i].index+1;
                        opt[num]=false;
                        need=p[i].left;
                        ++num;
                        vis[p[i].index]=true;
                        break;
                    }
                }
            }
            if(i==n){
                ok=false; 
                break;
            }
        }
    }
    else{
        ok=false;
    }
    if(ok){
        for(int i=0;i<n;++i){
            printf("%d %s\n",ans[i],opt[i]?"+":"-");
        }
    }
    else {
        printf("No solution\n");
    }
    return 0;
}
