#!/usr/bin/python
# coding=utf-8
a=pow(2,1000);
sum=0;
while a:
    sum+=a%10;
    a/=10;
print sum;
