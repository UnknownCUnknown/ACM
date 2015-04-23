#!/usr/bin/python
# coding=utf-8
M=2000000;
isprime=[True]*(M+10);
isprime[0]=isprime[1]=False;
prime=[];
for i in range(2,M+1):
    if isprime[i]:
        j=i+i;
        while j<M+1:
            isprime[j]=False;
            j+=i;
        prime.append(i);
max=0;
for i in range(-999,1000):
    for j in prime:
        print j;
        if j>=1000:
            break;
        else:
            n=0;
            while isprime[n*n+i*n+j]:
                n=n+1;
            if n>max:
                ansa=i;
                ansb=j;
                max=n;
print max,ansa,ansb

