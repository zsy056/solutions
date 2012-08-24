#! /usr/bin/env python

import sys

def max_sub_seq(seq):
    max_sum, beg, end = 0, seq[0], seq[-1]
    for i in range(len(seq)):
        imax_sum, isum, iend = 0, 0, -1
        if seq[i]<=0: continue
        for j in range(i, len(seq)):
            isum = isum + seq[j]
            if imax_sum<isum:
                imax_sum, iend = isum, j
        if imax_sum > max_sum:
            max_sum, beg, end = imax_sum, seq[i], seq[iend]
    print(max_sum, beg, end, sep=' ')

if __name__=='__main__':
    line = sys.stdin.readline()
    line = sys.stdin.readline()[:-1].split(' ')
    seq = []
    for wd in line:
        seq.append(int(wd))
    max_sub_seq(seq)
