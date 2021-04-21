#include "Graph.h"
#include <vector>

Graph::Graph(int v) {
    V = v;
    adj = new std::set<int>[v];
}

Graph::~Graph() {
    V = 0;
    delete []adj;
}

void Graph::addEdge(int v1, int v2) {
    adj[v1].insert(v2);
}

void Graph::BFS(int s) const {
    std::cout << std::endl << "Breadth-First Search" << std::endl;
    bool *visited = new bool[V];
    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }
    std::queue<int> queue;      
    visited[s] = true;         
    queue.push(s);             
    while (!queue.empty()){
        s = queue.front();      
        queue.pop();            
        std::cout << "Checking adjacent vertices for vertex " << s << std::endl;
        for (auto i : adj[s]) {
            if (!visited[i]){   
                visited[i] = true;
                queue.push(i);  
                std::cout << "Visited and enqueue " << i << " vertex" << std::endl;
            }
        }
    }
}

void Graph::DFS(int s) const {
    std::cout << std::endl << "Depth-First Search" << std::endl;
    bool *visited = new bool[V];
    for (int i = 0; i < V; ++i) {
        visited[i] = false;
    }
    std::stack<int> stack;      
    visited[s] = true;          
    stack.push(s);              
    while (!stack.empty()){
        s = stack.top();        
        stack.pop();            
        std::cout << "Checking adjacent vertices for vertex " << s << std::endl;
        for (auto i : adj[s]) {
            if (!visited[i]){   
                visited[i] = true;
                stack.push(i);  
                std::cout << "Visited and enqueue " << i << " vertex" << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

void Graph::printAdjacencyList() {
    std::cout << std::endl << "Adjacency List" << std::endl;
    for (int i = 0; i < V; ++i) {
        std::cout << i << ": ";
        for (auto j : *(adj + i)) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::printAdjacencyMatrix() {
    std::cout << std::endl << "Adjacency Matrix" << std::endl;
    bool adjMatrix[V][V];
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            adjMatrix[i][j] = false;
        }
    }
    for (int i = 0; i < V; ++i) {
        for (auto j : adj[i]){
            adjMatrix[i][j] = true;
        }
    }
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
