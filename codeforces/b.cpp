/*************************************************************************
	> File Name: b.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 一  3/ 2 16:17:53 2015
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
map<pair<int ,int>,bool > imap;
map<pair<int ,int>,int> num;
int x[100010];
int y[100010];
set <int > is;
int  s[100010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        imap[make_pair(a,b)]=true;
        x[i]=a;
        y[i]=b;
    }
    for(int i=0;i<n;++i){
        for(int xx=x[i]-1;xx<=x[i]+1;++xx){
            if(imap[make_pair(xx,y[i]-1)]){
                ++num[make_pair(x[i],y[i])];
            }
        }
    }
    for(int i=0;i<n;++i){
        bool flag=false;
        for(int xx=x[i]-1;xx<=x[i]+1;++xx){
            if(num[make_pair(xx,y[i]+1)]==1){
                flag=true;
                break;
            }
        }
        if(!flag){
            is.insert(i);
        }
    }
    int k=0;
    int sign=1;
    while(k<n){
        if(sign==1){
            s[k]=*(is.rbegin());
            is.erase(*(is.rbegin()));
        }   
        else{
            s[k]=*(is.begin());
            is.erase(*(is.begin()));
        }
        int a=x[s[k]];
        int b=y[s[k]];
        ++k;
        sign=-sign;

    }
}
