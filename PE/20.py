#!/usr/bin/python
# coding=utf-8
a=1;
for i in range(2,101):
    a*=i;
ans=0;
while a:
    ans+=a%10;
    a/=10;
print ans;
