#!/usr/bin/python
# coding=utf-8
i=2;
x=600851475143;
while i*i<=x:
    while x%i==0:
        x/=i;
        ans=i;
        print i;
    i=i+1;
print ans
