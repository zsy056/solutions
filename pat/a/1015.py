#!/usr/bin/env python

import sys

def is_prime(a):
    if a==2: return True
    if a==0 or a==1: return False
    for i in range(2, a-1):
        if a%i == 0: return False
    return True

def r_conv(a, base):
    out = ''
    while a>0:
        r = a%base
        out = out + str(r)
        a = int(a/base)
    #print(out)
    return out

if __name__=='__main__':
    while True:
        line = sys.stdin.readline()[:-1].split(' ')
        n = int(line[0])
        if n<0: break
        d = int(line[1])
        if not is_prime(n):
            print('No')
        elif is_prime(int(r_conv(n, d), d)):
            print('Yes')
        else:
            print('No')

