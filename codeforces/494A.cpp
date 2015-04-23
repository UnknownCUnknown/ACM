#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
char s[100100];
int ans[100100];
int left_num=0;
int main(){
    scanf("%s",s);
    int size=(int)strlen(s);
    int cnt=0;
    int left=0,right=0;
    for(int i=0;i<size;++i){
        if(s[i]=='(') {
            ++left;
            ++left_num;
        }
        else if(s[i]==')') {
            ++right;
            --left_num;
            if(left_num<0){
                printf("-1\n");
                return 0;
            }
        }
        else {
            if(left_num<=0){
                printf("-1\n");
                return 0;
            }
            --left_num;
            ++cnt;
        }
    }
    int left1=0,right1=0;
    for(int i=size-1;i>=0;--i){
        if(s[i]=='(') ++left1;
        else if(s[i]==')') ++right1;
        else break;
    }
    if(left1>right1){
        printf("-1\n");
        return 0;
    }
    if(left-right<cnt) printf("-1\n");
    else {
        int k=0;
        for(int i=0;i<cnt-1;++i){
            ans[k++]=1;
        }
        ans[cnt-1]=left-right-cnt+1;
        int tmp=0;
        k=0;
        for(int i=0;i<size;++i){
            if(s[i]=='('){
                ++tmp;
            }
            else if(s[i]==')'){
                --tmp;
                if(tmp<0) {
                    printf("-1\n");
                    return 0;
                }
            }
            else{
                tmp-=ans[k];
                ++k;
                if(tmp<0){
                    printf("-1\n");
                    return 0;
                }
            }
        }
        for(int i=0;i<cnt;++i){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
