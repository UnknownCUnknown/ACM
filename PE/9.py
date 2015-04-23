#!/usr/bin/python
# coding=utf-8
for a in range(0, 400):
    for b in range(a+1, 500):
        c=1000-a-b;
        if c>b:
            if c*c==a*a+b*b:
                print a,b,c
