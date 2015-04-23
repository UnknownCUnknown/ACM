/*************************************************************************
	> File Name: 1034.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/26 17:46:01 2014
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
map<string,int> imap;
int main(){
    int n;
    ios::sync_with_stdio(false);
    while(cin>>n,n){
        string s;
        imap.clear();
        int max=0;
        string ans;
        for(int i=0;i<n;++i){
            cin>>s;
            ++imap[s];
            if(imap[s]>max){
                ans=s;
                max=imap[s];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
