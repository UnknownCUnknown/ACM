#!/usr/bin/python
# coding=utf-8
M=1000000;
isprime=[True]*(M+10);
isprime[0]=isprime[1]=False;
for i in range(2,M+1):
    if(isprime[i]):
        j=i+i;
        while j<M+1:
            isprime[j]=False;
            j=j+i;
prime=[];
for i in range(2,M+1):
    if isprime[i]:
        prime.append(i);
print prime[10000];
