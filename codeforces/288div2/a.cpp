/*************************************************************************
	> File Name: a.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 三  1/28 00:32:25 2015
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
bool Map[1010][1010];
int X1[]={-1,-1,0};
int Y1[]={0,-1,-1};
int judge1(int x,int y){
    for(int i=0;i<3;++i){
        if(!Map[x+X1[i]][y+Y1[i]]) return false;
    }
    return true;           
}
int X2[]={0,1,1};
int Y2[]={-1,-1,0};
int judge2(int x,int y){
    for(int i=0;i<3;++i){
        if(!Map[x+X2[i]][y+Y2[i]]) return false;
    }
    return true;
}
int X3[]={-1,-1,0};
int Y3[]={0,1,1};
int judge3(int x,int y){
    for(int i=0;i<3;++i){
        if(!Map[x+X3[i]][y+Y3[i]]) return false;
    }
    return true;
}
int X4[]={0,1,1};
int Y4[]={1,0,1};
int judge4(int x,int y){
    for(int i=0;i<3;++i){
        if(!Map[x+X4[i]][y+Y4[i]]) return false;
    }
    return true;
    
}
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    memset(Map,false,sizeof Map);
    int  flag=false;
    int step;
    for(step=1;step<=c;++step){
        int x,y;
        scanf("%d%d",&x,&y);
        Map[x][y]=true;
        if(flag) continue;
        if(judge1(x,y)) {
            printf("%d\n",step);
            flag=true;
            continue;
        }
        if(judge2(x,y)){
            printf("%d\n",step);
            flag=true;
            continue;
        }
        if(judge3(x,y)){
            printf("%d\n",step);
            flag=true;
            continue;
        }
        if(judge4(x,y)){
            printf("%d\n",step);
            flag=true;
            continue;
        } 
    }    
    if(!flag) puts("0");
    return 0;
}
