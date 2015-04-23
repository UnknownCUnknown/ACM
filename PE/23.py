#!/usr/bin/python
# coding=utf-8


def la(x):
    i = 1
    res = 0
    while i * i < x:
        if x % i == 0:
            res += i
            res += x / i
        i = i + 1
    if i * i == x:
        res += i
    return res > x * 2
a = []
for i in range(1, 28124):
    if la(i):
        a.append(i)
size = len(a)
s = [True]*28124;
for i in range(0, size):
    for j in range(0, size):
        if a[i]+a[j]<28124:
            s[a[i]+a[j]]=False;
sum=0;
for i in range(0,28124):
    if(s[i]):
        sum+=i;
print sum;
