#!/usr/bin/env python

import sys

n = 0
coms = []
gra = {}

def dfs(root, x):
    coms[x] = root
    for j in range(n):
        a, b = max(x, j), min(x, j)
        if x==j or coms[j]!=-1 or a not in gra.keys() \
                or b not in gra[a]: continue
        dfs(root, j)

def isconnected():
    for i in range(n):
        if coms[i]!=-1: continue
        coms[i] = i
        for j in range(n):
            if i==j: continue
            a, b = max(i, j), min(i, j)
            if (a in gra.keys()) and (b in gra[a]):
                dfs(i, j)
    compo = len(set(coms))
    if compo!=1:
        print('Error: '+str(compo)+' components')
        return False
    return True

def cdfs(root, pre, x, depth, dlist):
    flag = True
    for i in range(n):
        if x==i or pre==i: continue
        a, b = max(x, i), min(x, i)
        if  (a in gra.keys()) and (b in gra[a]):
            cdfs(root, x, i, depth+1, dlist)
            flag = False
    if flag:
        if root not in dlist.keys(): dlist[root] = depth
        elif dlist[root]<depth: dlist[root] = depth
    

def droot():
    dlist = {}
    for i in range(n): cdfs(i, -1, i, 0, dlist)
    maxdepth = max(dlist.values())
    for i in dlist.keys():
        if dlist[i]==maxdepth: print(i+1)

if __name__=='__main__':
    n = int(sys.stdin.readline()[:-1])
    coms = [-1 for i in range(n)]
    for i in range(n-1):
        line = sys.stdin.readline()[:-1].split(' ')
        a, b = int(line[0])-1, int(line[1])-1
        a, b = max(a, b), min(a, b)
        if a in gra.keys(): gra[a].append(b)
        else: gra[a] = [b]
    if isconnected(): droot()
