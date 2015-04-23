#!/usr/bin/python
# coding=utf-8

sum=0;
def dfs(i, num, micihe):
    # print num,micihe;
    global sum;
    if i == 7:
        return;
    if micihe != 0:
        k = 0;
        if num == micihe:
            print micihe;
            sum = sum + micihe
    else:
        k = 1;
    for j in range(k, 10):
        dfs(i + 1, num * 10 + j, micihe + pow(j, 5));
sum = 0;
dfs(0, 0, 0);
print sum - 1;
