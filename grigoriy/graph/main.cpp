#include "Graph.h"
using namespace std;

/*
void printMap(const map<int,int>& m){
    for (const auto& [key, value] : m) {
        std::cout << key << " = " << value << "; ";
    }
    std::cout << "\n";
}
*/

int main() {

    Graph g(9);
//    0
    g.addEdge(0,1);
    g.addEdge(0,8);
//    1
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(1,3);
//    2
    g.addEdge(2,1);
    g.addEdge(2,5);
//    3
    g.addEdge(3,1);
    g.addEdge(3,6);
//    4
    g.addEdge(4,6);
    g.addEdge(4,7);
//    5
    g.addEdge(5,2);
//    6
    g.addEdge(6,3);
    g.addEdge(6,4);
//    7
    g.addEdge(7,4);
//    8
    g.addEdge(8,0);

    g.printAdjacencyList();
//    g.printAdjacencyMatrix();
    g.BFS(1);
//    g.DFS(1);

    return 0;
}
