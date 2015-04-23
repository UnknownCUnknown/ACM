/*************************************************************************
	> File Name: 1502.cpp
	> Author: UnknownCUnknown
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五  1/30 14:39:19 2015
 ************************************************************************/

#include <cstdio>
int a1[100];
int a2[100];
char s1[1000010];
char s2[1000010];
int main(){
    int n;
    while(~scanf("%d",&n)){
        scanf("%s%s",s1,s2);
        a1['A'-'A']=a1['G'-'A']=a1['C'-'A']=a1['T'-'A']=0;
        a2['A'-'A']=a2['G'-'A']=a2['C'-'A']=a2['T'-'A']=0;
        int num='a';
        int num1='a';
        bool flag=false;
        for(int i=0;i<n;++i){
            if(!a1[s1[i]-'A']){
                a1[s1[i]-'A']=num;
                s1[i]=num;
                ++num;
            }
            else {
                s1[i]=a1[s1[i]-'A'];
            }
            if(!a2[s2[i]-'A']){
                a2[s2[i]-'A']=num1;
                s2[i]=num1;
                ++num1;
            }
            else {
                s2[i]=a2[s2[i]-'A'];
            }
            if(s1[i]!=s2[i]){
                flag=true;
                break;
            }
        }
        if(!flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
