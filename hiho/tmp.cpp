/*************************************************************************
	> File Name: tmp.cpp
	> Author: 
	> Mail: 
	> Created Time: 日 12/14 18:52:07 2014
 ************************************************************************/

#include<iostream>
using namespace std;
int main(){
    int n=10;
    for(int i=0;i<100;++i){
        printf("%d %d\n",i,n%49);
        n=n*10%49;
    }
}
