/*************************************************************************
	> File Name: 1010_.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 三  3/18 20:17:21 2015
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
int a,b,t;//a宽度，b长度，t目标步数
bool flag = false;//判断是否满足条件
char m[20][20]; //记录地图
bool vis[20][20]; //vis[i][j]表示我是否到达过坐标i，j的地方

int row[]={-1,0,0,1};
int col[]={0,1,-1,0};
//x+row[i],y+row[i]
bool judge(int x,int y){
    if(x<0||y<0) return false;
    if(x>=a||y>=b) return false;
    if(vis[x][y]) return false;
    if(m[x][y]=='X') return false;
    return true;
}
void dfs(int step,int x,int y)//step当前步数，x，y为当前坐标
{
    if (step==t){
        if(m[x][y]=='D'){
            flag=true;
        }
        return ;
    }
    if(flag) return ;
    for(int i=0;i<4;++i){
        if(judge(x+row[i],y+col[i])){
            vis[x+row[i]][y+col[i]]=true;
            dfs(step+1,x+row[i],y+col[i]);
            vis[x+row[i]][y+col[i]]=false;
        }
        if(flag) return ;
    }
}
int a[100];//假设是从小到大
int binary_search(int low,int high,int key){
    if(low>high) return -1;
    int mid = (low+high)/2;
    if(a[mid]==key) return mid;
    else if(a[mid]>key){
        return binary_search(low,mid-1,key);
    } 
    else {
        return binary_search(mid+1,high,key);
    }
}
