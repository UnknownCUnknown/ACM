#!/usr/bin/python
# coding=utf-8
ans=1;
i=1;
while i<=20:
    if ans%i!=0:
        ans*=i;
        print i;
    i=i+1;
print ans;
