from common.mymath import *

n = 100000
Plst = PrimeLst(n)

def primefactorLst(n):
    lst = []
    for i in Plst:
        if n == 1:
            break
        if n%i==0:
            cnt = 0
            while n%i==0:
                cnt += 1
                n = n/i
            item = (i,cnt)
            lst.append(item)
    return lst

import operator
def factorlstIn(l):
    if len(l)==0:
        return [1]
    lz = factorlstIn(l[1:])
    (p, e) = l[0]
    return reduce(operator.add,[[p**i*j for j in lz] for i in range(0,e+1)],[])


def factorlst(n):
    l = primefactorLst(n)
    return factorlstIn(l)

def getSumDiv(n):
    if n<=1:
        return 0
    return sum(factorlst(n)) - n

def isAmi(n):
    m = getSumDiv(n)
    nn = getSumDiv(m)
    if n == nn and m!=n:
        print n,m
        return True
    return False

s = []
for i in range(2,10000+1):
    if isAmi(i):
        s.append(i)

print s
print sum(s)
