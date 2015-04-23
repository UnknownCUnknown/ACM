/*************************************************************************
	> File Name: 2705.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  3/12 13:53:48 2015
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
long long n;
long long fac[200010];
map<long long ,long long> imap;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    int cnt=0;
    long long i;
    for(i=1;i*i<n;++i){
        if(n%i==0){
            fac[cnt++]=i;
            fac[cnt++]=n/i;
            imap[i]+=1;
            imap[n/i]+=1;
        }
    }
    if(i*i==n){
        fac[cnt++]=i;
        imap[i]+=1;
    }
    sort(fac,fac+cnt);
    long long ans=n;
    for(int i=cnt-2;i>=0;--i){
        long long tmp=n/fac[i];
        //cout<<tmp<<endl;
        //cout<<fac[i]<<" "<<imap[fac[i]]<<endl;;
        tmp-=imap[fac[i]];
        ans+=tmp*fac[i];
        long long j;
        for(j=1;j*j<fac[i];++j){
            if(fac[i]%j==0){
                imap[fac[i]/j]+=tmp;
                imap[j]+=tmp;
            }
        }
        if(j*j==fac[i]){
            imap[j]+=tmp;
        }
        //cout<<ans<<" "<<tmp<<" "<<fac[i]<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
