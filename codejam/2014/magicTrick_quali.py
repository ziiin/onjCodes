'''
This is qualification round problem of google codejam 2014.
    link: https://code.google.com/codejam/contest/dashboard?c=2974486
'''

import sys


def main():
    t = int(raw_input())
    for i in range(1,t+1):
        row1 = int (raw_input())
        s1 = set()
        for j in range(4):
            r_val = sys.stdin.readline()
            if j == (row1 -1):
                for element in r_val.split():
                    s1.add (int(element))

        s2 = set()
        row2 = int(raw_input())
        for j in range(4):
            r_val = sys.stdin.readline()
            if j == (row2 - 1):
                for element in r_val.split():
                    s2.add (int(element))

        s = s1 & s2
        if (len (s)) == 1:
            for ele in s:
                print "Case #" + str(i) + ": " + str(ele)
        elif (len (s) ) == 0:
            print "Case #" + str(i) + ": " + "Volunteer cheated!"
        else:
            print "Case #" + str(i) +": " + "Bad magician!"
    pass

if __name__ == "__main__":
    main()

