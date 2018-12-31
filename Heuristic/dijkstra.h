#include <deque>

struct Costs{
	int regularCost;
	int premiumCost;
	Costs(int cost = 0, int premCost = 0):regularCost(cost), premiumCost(premCost)
	{}
};
class Graph {
private:
    std::pair<Costs, int> **adjMatrix;
    int vertexCount;

    int *key;
    int *distance;
    int *parent;

public:
    Graph(int vertexCount);
    ~Graph();
    void addEdgeDirectedWeight(int i, int j, int cost, int costPremium, int seats);
    void removeEdgeUndirected(int i, int j);
    int isEdge(int i, int j);
    void display();
    void initializeState();
    std::deque<int> printPath(int j);
    void showBasicInfo();
    bool Dijkstra(int startNode, bool premiumTicket);
    int isAllKeyTrue();  //0 means not MST, 1 means MST
    int findMinDistanceNode();
    int bookTicket(int startNode, int destinationNode, bool premiumTicket = false);

};

