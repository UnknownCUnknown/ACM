#!/usr/bin/python
# coding=utf-8

def judge(x):
    cnt=0;
    a=[];
    while(x):
        a.append(x%10);
        cnt=cnt+1;
        x=x/10;
    for i in range(0,cnt/2):
        if(a[i]!=a[cnt-i-1]):
            return False;

    return True;
ans = 0;
for i in range(100,1000):
    for j in range(100,1000):
        if(judge(i*j)):
            if(i*j>ans):
                ans=i*j
print ans
