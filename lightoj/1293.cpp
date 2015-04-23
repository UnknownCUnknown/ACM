/*************************************************************************
	> File Name: 1293.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 二  3/10 14:27:32 2015
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
char s[110];
const char en[]="END";
string words[50010];
map<string,bool> imap;
map<string,int> kmap;
int main(){
    int T;
    scanf("%d",&T);
    getchar();
    for(int ca=1;ca<=T;++ca){
        imap.clear();
        kmap.clear();
        int cnt=0;
        while(gets(s),strcmp(s,en)){
            int size=(int)strlen(s);
            for(int i=0;i<size;++i){
                if(islower(s[i])){
                    if(i==0){
                        ++cnt;
                        words[cnt].clear();
                        words[cnt].push_back(s[i]);
                    }
                    else if(!islower(s[i-1])){
                        ++cnt;
                        words[cnt].clear();
                        words[cnt].push_back(s[i]);
                    }
                    else {
                        words[cnt].push_back(s[i]);
                    }
                }
            }
        }
        ++cnt;
        int ansp=0,ansq=0;
        int minpq=50010;
        int l=1,r=1;
        int numofkind=0;
        for(int i=1;i<cnt;++i){
            //cout<<words[i]<<endl;
            if(!imap[words[i]]){
                ++numofkind;
                imap[words[i]]=true;
            } 
        }
        int num=0;
        while(l<cnt){
            while(r<cnt&&numofkind!=num){
                if(kmap[words[r]]==0){
                    ++num;
                }
                ++kmap[words[r]];
                ++r;
            }
            if(numofkind!=num){
                break;
            }
            else{
                if(r-l<minpq){
                    minpq=r-l;
                    ansp=l;
                    ansq=r-1;
                }
                --kmap[words[l]];
                if(kmap[words[l]]==0){
                    --num;
                }
                ++l;
            }
        }
        printf("Case %d: %d %d\n",ca,ansp,ansq);
    }
    return 0;
}
