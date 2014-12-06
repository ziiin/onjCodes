# URL: https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/
# Status: Solved

class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        low = 0
        high = len(num) - 1
        _min = num[0]
        # big min small
        # if low < mid : low = mid+1
        while low < high-1:
            mid = (low+high)/2
            if num[mid] > num[low]:
                _min = min(_min, num[low])
                low = mid+1
            elif num[mid] < num[low]:
                _min = min (_min, num[mid])
                high = mid - 1
            else:
                _min = min(_min, num[low])
                low = low+1
            print "Min: ", _min
        # if mid < low : high = mid -1
        # low ++ : update min
        _min = min(num[low],num[high],_min)
        return _min
