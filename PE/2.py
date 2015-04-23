#!/usr/bin/python
# coding=utf-8
a=1;
b=2;
sum=2;
c=3;
while c<4000000:
    if c%2==0:
        sum+=c;
    c=a+b;
    a=b;
    b=c;
print sum
