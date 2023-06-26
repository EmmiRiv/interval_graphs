from interval import *
import sys
import networkx as nx
import itertools

def improvement():
    return

def if_indep():

    return

def t_opt():

    return

def generate_dicts(infile, classes, overlaps, label_list):
    for line in infile:
        rect = line.strip().split(",")
        rect[0] = float(rect[0])
        rect[1] = float(rect[1])
        rect[2] = float(rect[2])
        rect[3] = float(rect[3])
        classes.update({rect[4] : Interval2(rect[0],rect[1],rect[2],rect[3],rect[4])})
        overlaps.update({rect[4] : []})

        for label in label_list:
            if classes.get(label).get_left1() != 0:
                if not (classes.get(label).get_left1() >= rect[1] or classes.get(label).get_right1() <= rect[0]):
                    overlaps.get(label).append(rect[4])
                    overlaps.get(rect[4]).append(label)
            if classes.get(label).get_left2() != 0 and (rect[4] not in overlaps.get(label)):
                if not (classes.get(label).get_left2() >= rect[3] or classes.get(label).get_right2() <= rect[2]):
                    overlaps.get(label).append(rect[4])
                    overlaps.get(rect[4]).append(label)
        
        label_list.append(rect[4])

def main():
    infile = open(sys.argv[1])
    n = int(infile.readline().strip())
    classes = {}
    overlaps = {}
    label_list = []

    generate_dicts(infile, classes, overlaps, label_list)

    graph = nx.Graph(overlaps)

    for label in label_list:
        print(classes.get(label))
        print(overlaps.get(label))

    print(nx.algorithms.approximation.clique.maximum_independent_set(graph))
    print(nx.maximal_independent_set(graph))
main()