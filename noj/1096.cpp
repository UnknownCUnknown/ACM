/*************************************************************************
	> File Name: 1096.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 12/26 18:27:42 2014
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
int main(){
    long long ans=1;
    long long m,n;
    //scanf("%lld%lld",&m,&n);
    cin>>m>>n;
    if(n>m/2) n=m-n;
    long long tmp=1;
    for(int i=0;i<n;++i){
        tmp*=(i+1);
        ans*=(m-i);
    }
    //printf("%lld\n",ans/tmp);
    cout<<ans/tmp<<endl;
    return 0;
}
