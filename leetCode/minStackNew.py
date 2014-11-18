# Problem url: https://oj.leetcode.com/problems/min-stack/
# Status: Solved
class minStack:

    def __init__ (self):
        self.elements = []
        self.minNow =None

    # @param x, an integer
    # @return an integer
    def push(self, x):
        if len(self.elements) == 0:
            self.minNow = x
            self.elements.append(0)
        else:
            self.elements.append(x - self.minNow)
            self.minNow = min(x, self.minNow)

        return len(self.elements)

    # @return nothing
    def pop(self):
        res = self.elements.pop()
        if res <0 :
            self.minNow = self.minNow - res
        return res
    
    # @return an integer
    def top(self):
        res = self.elements[-1]
        if res > 0 :
            return self.minNow + res
        else:
            return self.minNow
        
    # @return an integer
    def getMin(self):
        return self.minNow

        
