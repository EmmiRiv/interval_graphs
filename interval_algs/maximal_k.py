"""
input is a text file of format 
k (number of colors)
n (number of intervals)
a,b (start, end)
c,d
....
"""

from interval import *
import sys

def init_ints(k,sets):
    # sets up dummy intervals

    for i in range(k+1):
        sets.update({-i : [Interval(-i-1,-i,"placeholder")]})
        sets[-i][0].set_index(-i)
        sets[-i][0].set_color(k-i)
        sets[-i][0].set_adj(-i-1)

def init_adj(n,sets):
    # sets up adjacent values for intervals

    for s in range(1,n+1):
        i = 0
        j = sets[s][0].get_left()
        while(j > sets[i][0].get_right()):
            i += 1
        sets[s][0].set_adj(i-1)

def find(k,n,sets,i1):
    # returns the name of the set containing I_i

    for i in range(-k,n+1):
        if i in sets:
            for j in range(len(sets[i])):
                if i1 == sets[i][j].get_index():
                    return i

def union(sets,i1,i2):
    # merges the sets with names I_1 and I_2
    # the name of the combined set will be I_2
    # the original sets no longer exist after this operation

    sets[i2] = sets[i2] + sets[i1]
    del sets[i1]

def output(sets,k,n):
    print("[label,index,color]")
    for i in range(-k,n+1):
        if i in sets:
            for j in range(len(sets[i])):
                print(sets[i][j])

def main():
    infile = open(sys.argv[1])
    sets = {}
    k = int(infile.readline().strip())
    n = int(infile.readline().strip())
    temp = []
    for line in infile:
        interval = line.strip().split(",")
        interval[0] = float(interval[0])
        interval[1] = float(interval[1])
        temp.append(interval)
    temp.sort(key = lambda x: x[1])
    for i in range(n):
        sets.update({i+1 : [Interval(temp[i][0],temp[i][1],temp[i][2])]})
        sets[i+1][0].set_index(i+1)

    init_ints(k,sets)

    init_adj(n,sets)

    # main loop of function

    for i in range(1,n+1):
        j = find(k,n,sets,sets[i][0].get_adj())
        if j == -k:
            sets[i][0].set_color(0)
            union(sets,i,find(k,n,sets,i-1))
        else:
            sets[i][0].set_color(sets[j][0].get_color())
            union(sets,j,find(k,n,sets,j-1))

    output(sets,k,n)

main()