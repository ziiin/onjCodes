#http://www.hackerearth.com/hotelsoft-hiring-challenge/algorithm/simple-math-1/

import math
import sys

def nCr(n,r):
    f = math.factorial
    return f(n) / (f(r) * f(n-r))
            
def f():
    tests = sys.stdin.readline().split()
    n = int(tests[0])
    r = int(tests[1])
    
    if n < r:
        return -1
    else:
        return nCr(n-1, r-1)% 10000007
