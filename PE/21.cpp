/*************************************************************************
	> File Name: 21.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  3/ 5 13:26:35 2015
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
int nn(int x){
    int i;
    int res=0;
    for(i=1;i*i<x;++i){
        if(x%i==0){
            res+=i;
            res+=x/i;
        }
    }
    if(i*i==x){
        res+=i;
    }
    return res-x;
}
int a[10010];
set<int> s;
int main(){
    for(int i=1;i<10000;++i){
        a[i]=nn(i);
    }
    for(int i=1;i<10000;++i){
        for(int j=1;j<i;++j){
            if(a[i]==j&&a[j]==i){
                s.insert(i);
                s.insert(j);
            }
        }
    }
    int sum=0;
    for(set<int>::iterator i=s.begin();i!=s.end();++i){
        sum+=*i;
    }
    printf("%d\n",sum);
    return 0;
}
