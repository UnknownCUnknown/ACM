#!/usr/bin/python
# coding=utf-8
def nn(x):
    i=1;
    res=0;
    while i*i<x:
        if x%i==0:
            res+=i;
            res+=x/i;
        i=i+1;
    if i*i==x:
        res+=i;
    return res;
ans=[];
map=[0]*1000000;
ans=0;
for i in range(1,10000):
    a=nn(i);
    if map[a]=1:
        ans.append(i);
    else :
        map[a]=1;

