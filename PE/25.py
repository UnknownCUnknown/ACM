#!/usr/bin/python
# coding=utf-8

a=[1,1];
def judge(x):
    if x==0:
        return 1;
    cnt=0;
    while x:
        x/=10;
        cnt=cnt+1;
    return cnt;
size=2;
tmp=a[size-1]+a[size-2];
k=judge(tmp);
while k<1000:
    a.append(tmp);
    size=size+1;
    tmp=a[size-1]+a[size-2];
    k=judge(tmp);
    print k;
print size;
