/*
 * 根据每一列比较字典序，用两个数组存当前满足字典序的位置，一个存整体的，一个存当前列的。
 * 每次扫的时候，如果整体的那个数组发现当前行以满足字典序，则不用扫
 * 如果当前列没有不满足字典序的，则将当前列的数组存入整体得数组中
 * 如果有，则将答案++，并且不更新整体的那个数组。
 */
/*************************************************************************
	> File Name: c.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四 12/18 01:10:45 2014
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
char words[110][110];
int islex[110];
int tmprows[110];
int n,m;
int neederase;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%s",words[i]);
    }
    memset(islex,0,sizeof islex);
    int cnt=0;
    neederase=0;
    for(int i=0;i<m;++i){
        memset(tmprows,0,sizeof tmprows);
        cnt=0;
        for(int j=0;j<n-1;++j){
            if(!islex[j]){
                if(words[j][i]<words[j+1][i]){
                    tmprows[cnt]=j;
                    ++cnt;
                }
                else if(words[j][i]>words[j+1][i]){
                    cnt=0;
                    ++neederase;
                    break;
                }
            }   
        }
        if(cnt!=0){
            for(int i=0;i<cnt;++i){
                islex[tmprows[i]]=1;
            }
        }
    } 
    printf("%d\n",neederase);
    return 0;
}
