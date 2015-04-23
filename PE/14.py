#!/usr/bin/python
# coding=utf-8
ans=[0]*1000010;
max=0;
for i in range(1,1000001):
    k=i;
    cnt=0;
    while k!=1:
        ans[i]=ans[i]+1;
        if k%2==0:
            k=k/2;
        else:
            k=3*k+1;
    #print i,ans[i];
    if ans[i]>max:
        max=ans[i];
        maxans=i;
print maxans;
