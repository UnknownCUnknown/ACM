/*************************************************************************
	> File Name: a.cpp
	> Author: 
	> Mail: 
	> Created Time: 日 12/14 18:59:36 2014
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <a.cpp>
using namespace std;
char s[]="marshtomp";
char ex[]="fjxmlhx";
char input[1000];
char tmp[1000];
int main(){
    int len=(int)strlen(s);
    while(gets(input)){
        int size=(int)strlen(input);
        for(int i=0;i<size;++i){
            tmp[i]=tolower(input[i]);
        }
        tmp[size]='\0';
        for(int i=0;i<size;++i){
            if(i<=size-len&&strncmp(tmp+i,s,len)==0){
                printf("%s",ex);
                i+=len-1;
            }
            else printf("%c",input[i]);
        }
        printf("\n");
    }
    return 0;
}

