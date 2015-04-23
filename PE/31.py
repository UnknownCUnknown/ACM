#!/usr/bin/python
# coding=utf-8
a=[200,100,50,20,10,5,2,1];
ans=0;
def dfs(i,now):
    global ans;
    if now==200:
        ans=ans+1;
        return ;
    if i==7:
        if now<200:
            ans=ans+1;
            return ;
    j=i;
    while now+a[j]>200:
        j=j+1;
    for k in range(j,8):
        dfs(k,now+a[k]);
dfs(0,0);
print ans;
