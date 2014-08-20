class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:

    # @param head, a ListNode
    # @return a ListNode
    def sortList(self, head):
        pass


def quickSort (arr, start, end):
    pivot = start # customise pivot to be median
    left = start + 1
    right = end

    while ( left < right):
        while (arr[left] < arr[pivot]):
            arr[left], arr[pivot] = arr[pivot], arr[left]
            left = left + 1
            pivot = pivot + 1
        while (arr[right] > arr[pivot]):
            right = right -1

        arr[left], arr[right] = arr[right], arr[left]
        print arr


