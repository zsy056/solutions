#!/usr/bin/env python

import sys

def r_conv(a, base):
    if a==0:
        return ['0']
    out = []
    while a>0:
        r = a%base
        out.append(str(r))
        a = int(a/base)
    return out

def is_pal(nstr):
    return nstr == nstr[::-1]

if __name__=='__main__':
    line = sys.stdin.readline()[:-1].split(' ')
    out = r_conv(int(line[0]), int(line[1]))
    if is_pal(out):
        print('Yes')
    else:
        print('No')
    print(out[::-1][0], end='')
    for i in out[::-1][1:]:
        print(' '+i, end='')
    print()
