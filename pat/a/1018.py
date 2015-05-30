#!/usr/bin/env python
import sys
import copy
cpref, n, sp, m = 0, 0, 0, 0
c = []
cmap = []
pres = []
paths = []

def di():
    unknown = [True for i in range(n+1)]
    dist = [99999 for i in range(n+1)]
    dist[0] = 0
    while True:
        suknow, sdist = -1, 999999999
        for i in range(n+1):
            if unknown[i] and i!=suknow and dist[i]<sdist:
                sdist, suknow = dist[i], i
        if suknow == -1: break
        for i in range(n+1):
            if unknown[i] and i!=suknow and cmap[i][suknow]!=-1:
                if cmap[i][suknow]+sdist<dist[i]:
                    dist[i] = cmap[i][suknow]+sdist
                    pres[i] = [suknow]
                elif cmap[i][suknow]+sdist==dist[i]:
                    pres[i].append(suknow)
        unknown[suknow] = False
    
def dfs(root, path):
    path.append(root)
    if root == 0: 
        paths.append(copy.copy(path))
    else:
        for child in pres[root]:
            dfs(child, path)
    path.pop()

def getpaths():
    di()
    dfs(sp, [])
    for i in range(len(paths)):
        send, curr = 0, 0
        paths[i].reverse()
        for j in range(1, len(paths[i])):
            if c[paths[i][j]]>cpref:
                curr = curr + c[paths[i][j]]-cpref
            elif c[paths[i][j]]<cpref:
                if curr >= cpref - c[paths[i][j]]:
                    curr = curr - (cpref-c[paths[i][j]])
                elif curr < cpref - c[paths[i][j]]:
                    send = send - (cpref-c[paths[i][j]]-curr)
                    curr = 0
        paths[i].append(-send)
        paths[i].append(curr)
    minsend, minback, idx = 9999, 9999, 0
    for i in range(len(paths)):
        if minsend>paths[i][-2]:
            idx, minsend, minback = i, paths[i][-2], paths[i][-1]
        elif minsend==paths[i][-2] and minback>paths[i][-1]:
            idx, minback = i, paths[i][-1]

    print(paths[idx][-2], end=' ')
    for i in range(len(paths[idx])-3):
        print(paths[idx][i], end='->')
    print(paths[idx][-3], end=' ')
    print(paths[idx][-1])


if __name__=='__main__':
    line = sys.stdin.readline()[:-1].split(' ')
    cpref, n, sp, m = int(int(line[0])/2), int(line[1]), int(line[2]), int(line[3])
    if n<=0: quit(0)
    line = sys.stdin.readline()[:-1].split(' ')
    ct = [0]
    ct.extend([int(line[i]) for i in range(n)])
    c = ct
    cmap = [[-1 for j in range(n+1)] for i in range(n+1)]
    pres = [[] for i in range(n+1)]
    for i in range(m):
        line = sys.stdin.readline()[:-1].split(' ')
        si, sj, tij = int(line[0]), int(line[1]), int(line[2])
        cmap[si][sj] = cmap[sj][si] = tij
    getpaths()
