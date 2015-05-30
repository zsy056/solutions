#!/usr/bin/env python
import sys

def conv(num, rad):
    ret = 0
    for digi in num:
        ret = int(digi, 36) + ret*rad
    return ret

def bifun(a, b, maxdigi, ub):
    mid = int((ub+maxdigi)/2)
    con = conv(b, mid)
    if con == a and mid==ub:
        print(mid)
        quit(0)
    elif maxdigi==ub: im()
    elif con >= a:
        bifun(a, b, maxdigi, mid)
    else:
        bifun(a, b, mid+1, ub)


def fun(a, b, maxdigi):
    maxdigi = max(maxdigi, 1)
    i = maxdigi + 1
    if len(b) > 1: ub = int(a**(1/(len(b)-1)))
    else: ub = 0
    if ub < i: ub = i+1
    bifun(a, b, i, ub)
    im()

def im():
    print('Impossible')
    quit(0)


if __name__=='__main__':
    line = sys.stdin.readline()[:-1].split(' ')
    a, b = line[0], line[1]
    tag, rad = int(line[2]), int(line[3])
    if rad<2: im()
    maxdigia, maxdigib = int(max(a), 36), int(max(b), 36)
    if tag==1:
        if rad<=maxdigia: im()
        fun(conv(a, rad), b, maxdigib) 
    else:
        if rad<=maxdigib: im()
        fun(conv(b, rad), a, maxdigia)
