#include <iostream>
#include <vector>
#include "dijkstra.h"

using namespace std;

typedef vector<int> FlightList;

void buildGraph(Graph & g);
void buildFlightList(FlightList & flightList);


int main(){

    Graph g(5);
    buildGraph(g);

    FlightList flightList;
    buildFlightList(flightList);

    int startNode = 0;

    for(FlightList::iterator it = flightList.begin(); it != flightList.end(); ++it)
    {
        g.bookTicket(startNode, *it);
    }
    return 0;

}

void buildGraph(Graph & g)
{
    g.addEdgeDirectedWeight(0, 1, 10, 1);
    g.addEdgeDirectedWeight(0, 3, 5,  1);
    g.addEdgeDirectedWeight(1, 2, 1,  3);
    g.addEdgeDirectedWeight(1, 3, 2,  1);
    g.addEdgeDirectedWeight(2, 4, 4,  4);
    g.addEdgeDirectedWeight(3, 1, 3,  1);
    g.addEdgeDirectedWeight(3, 2, 9,  1);
    g.addEdgeDirectedWeight(3, 4, 2,  1);
    g.addEdgeDirectedWeight(4, 0, 7,  1);
    g.addEdgeDirectedWeight(4, 2, 6,  1);

    g.initializeState();
}

void buildFlightList(FlightList & flightList)
{
    flightList.push_back(4);
    flightList.push_back(4);
}

