/*************************************************************************
	> File Name: 1739.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  1/15 11:47:48 2015
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
map<int,int> imap;
int main(){
    int n;
    while(~scanf("%d",&n)){
        imap.clear();
        for(int i=0;i<n;++i){
            int a,b;
            scanf("%d%d",&a,&b);
            if(b>imap[a]) imap[a]=b;
        }
        int ans=0;
        int max=-1;
        for(map<int,int>::reverse_iterator i=imap.rbegin();i!=imap.rend();++i){
            if((*i).second>max){
                max=(*i).second;
                ++ans;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
