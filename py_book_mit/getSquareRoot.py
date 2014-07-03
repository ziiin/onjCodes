
import math

def squareRoot (num, precise = 3):
    ''' Returns closest square-root of a number,
        using Bisection search algorithm.
        @num : The number for which square root is needed
        @precise: Precise upto number precise number of digits'''
    if num < 0:
        return -1
    elif num == 0:
        return 0
    step = 0.1
    precission = step / ((10**precise))
    start = 0
    end = num
    while ( True ):
        mid = (start + end) / 2.0
        squareTillNow = mid*mid
        if abs(squareTillNow - num) < precission:
            break
        else:
            if squareTillNow > num:
                end = mid
            else :
                start = mid
    return mid
     
print squareRoot (10000, 4)
