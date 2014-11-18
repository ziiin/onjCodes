# Problem url: https://oj.leetcode.com/problems/min-stack/
# Status: Unsolved
class MinStack:

    def __init__ (self):
        self.elements = []
        self.minNow = []

    # @param x, an integer
    # @return an integer
    def push(self, x):
        minElement = None
        if len(self.minNow) == 0
        #
        if self.minElement != None and x < self.minElement:
            self.minElement = x
        elif self.minElement == None :
            self.minElement = x

        self.elements.append(x)
        return len(self.elements)

    # @return nothing
    def pop(self):
        self.elements.pop()
    
    # @return an integer
    def top(self):
        return self.elements[len(self.elements)-1]
        
    # @return an integer
    def getMin(self):
        return self.minElement

        
