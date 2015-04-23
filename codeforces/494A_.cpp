/*************************************************************************
	> File Name: 494A_.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二  2/ 3 13:30:09 2015
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
char s[100010];
int main(){
    gets(s);
    int size=(int)strlen(s);
    int l=0,r=0;
    int lastp=-1;
    int jn=0;
    for(int i=0;i<size;++i){
        if(s[i]=='(') ++l;
        else if(s[i]==')') ++r;
        else {
            ++jn;
            lastp=i;
        }
    }
    if(l>=r+jn){
        int tmp=l-(r+jn)+1;
        int le=0,ri=0;
        bool flag=false;
        for(int i=0;i<size;++i){
            if(s[i]=='(')++le;
            else if(s[i]==')') ++ri;
            else{
                if(i==lastp) ri+=tmp;
                else ++ri;
            }
            if(ri>le){
                flag=true;
                puts("-1");
                break;
            }
        }
        if(!flag&&ri==le){
            for(int i=0;i<jn-1;++i){
                puts("1");
            }       
            printf("%d\n",tmp);
        }else if(!flag){
            puts("-1");
        }
    }
    else puts("-1");
    return 0;
}
