#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#include <iostream>
#include <queue>
#include <stack>
#include <set>


class Graph{
    int V;
    std::set<int> *adj;
public:
    explicit Graph(int v);
    ~Graph();
    void addEdge(int v1, int v2);
    void BFS(int s) const;
    void DFS(int s) const;
    void printAdjacencyList();
    void printAdjacencyMatrix();
};


#endif //GRAPH_GRAPH_H
