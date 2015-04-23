/*************************************************************************
	> File Name: g.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 日  3/29 13:26:39 2015
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
const int N = 200500;
typedef long long LL;

int p[N];
int num;
bool in[N];
int a[N];
int n;
int nn[N];

void get_prime()
{
    num = 0;
    for(int i=2; i<N; i++)
    {
        if(!in[i])
        {
            p[num++] = i;
            for(int j=i; j<N; j+=i)
            {
                in[j] = true;
            }
        }
    }
}
int numofone=0;
void init()
{
    memset(nn, 0, sizeof(nn));
    int cnt = 0;
    int ele[100];
    scanf("%d", &n);
    int temp = 0;
    numofone=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        if(a[i]==1){
            ++numofone;           
            --i;
            --n;
            continue;
        }
        temp = a[i];
        cnt = 0;
        for(int  j=0; p[j]*p[j] <= temp; j++)
        {
            if(temp % p[j] == 0)
            {
                ele[cnt++] = p[j];
                while(temp%p[j] == 0)
                    temp /= p[j];
            }
        }
        if(temp != 1)
        {
            ele[cnt++] = temp;
        }
        for(int j=1; j<(1<<cnt); j++)
        {
            temp = 1;
            for(int k=0; k<cnt; k++)
            {
                if( (1<<k) & j )
                {
                    temp *= ele[k];
                }
            }
            nn[temp]++;
        }
    }
}

void solve()
{
    LL ans = n;
    LL ss = 0;
    int temp;
    for(int i=0; i<n; i++)
    {
        int cnt = 0;
        int ele[100];
        temp = a[i];
        cnt = 0;
        for(int  j=0; p[j]*p[j] <= temp; j++)
        {
            if(temp % p[j] == 0)
            {
                ele[cnt++] = p[j];
                while(temp%p[j] == 0)
                    temp /= p[j];
            }
        }
        if(temp != 1)
        {
            ele[cnt++] = temp;
        }
        LL ret = 0;
        for(int j=1; j<(1<<cnt); j++)
        {
            temp = 1;
            int hh = 0;
            for(int k=0; k<cnt; k++)
            {
                if( (1<<k) & j )
                {
                    temp *= ele[k];
                    hh++;
                }
            }
            if(hh%2 == 1) ret += nn[temp];
            else ret -= nn[temp];
        }
        //if(ret == 0) continue;
        ss = ss + (n-ret);
       // cout<<i<<"  "<<ret<<"  "<<ss<<endl;
    }
    ss/=2;
    //printf("%lld\n",ss);
    ss+=numofone*n;
    if(numofone>0){
        ss+=numofone*(numofone-1)/2;
    }
    cout<<ss<<endl;
}

int main()
{
    get_prime();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        init();
        solve();
    }
    return 0;
}
