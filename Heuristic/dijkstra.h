#include <deque>

class Graph {
private:
    std::pair<int, int> **adjMatrix;
    int vertexCount;
    // below attributes are for Prims

    int *key;
    int *distance;
    int *parent;

public:
    Graph(int vertexCount);
    ~Graph();
    void addEdgeDirectedWeight(int i, int j, int cost, int seats);
    void removeEdgeUndirected(int i, int j);
    int isEdge(int i, int j);
    void display();
    void initializeState();
    std::deque<int> printPath(int j);
    void showBasicInfo();
    void Dijkstra(int startNode);
    int isAllKeyTrue();  //0 means not MST, 1 means MST
    int findMinDistanceNode();
    void bookTicket(int startNode, int destinationNode);

};

