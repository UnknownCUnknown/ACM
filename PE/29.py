#!/usr/bin/python
# coding=utf-8
a=[];
for x in range(2,101):
    for b in range(2,101):
        a.append(pow(x,b));
a.sort();
size=len(a);
cnt=1;
for i in range(1,size):
    if a[i]!=a[i-1]:
        cnt=cnt+1;
print cnt;
