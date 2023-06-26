import networkx as nx

def gen_g1():
    nodes = [1,2,3,4,5,6,7,8,9,10,11]
    edges = [(1,9), (2,9), (4,5), (4,8), (4,10), (5,10), (5,8), (5,7), (7,10), (8,10)]
    g1 = nx.Graph()
    g1.add_nodes_from(nodes)
    g1.add_edges_from(edges)
    return g1

def gen_g2():
    nodes = [1,2,3,4,6,7,11,12,13,14]
    edges = [(1,3), (6,7), (4,14), (4,13), (11,12), (13,14)]
    g2 = nx.Graph()
    g2.add_nodes_from(nodes)
    g2.add_edges_from(edges)
    return g2

def gen_g():
    nodes = range(1,15)
    edges = [(1,9), (2,9), (4,5), (4,8), (4,10), (5,10), (5,8), (5,7), (7,10), (8,10), (1,3), (6,7), (4,14), (4,13), (11,12), (13,14)]
    g = nx.Graph()
    g.add_nodes_from(nodes)
    g.add_edges_from(edges)
    return g

def maximum_independent_set(graph):
    iset, _ = nx.algorithms.approximation.clique.clique_removal(graph)
    return iset

def main():
    g1 = gen_g1()
    g2 = gen_g2()
    g = gen_g()
    print(maximum_independent_set(g1))
    print(maximum_independent_set(g2))
    print(maximum_independent_set(g))
main()
