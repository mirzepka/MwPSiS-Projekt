#include <iostream>
#include <vector>
#include "dijkstra.h"
#include "FileParser.h"

using namespace std;

typedef vector<int> FlightList;

void buildGraph(Graph & g, std::map<int, Edge> & edges);
//void buildFlightList(FlightList & flightList, std::vector<Demand> demands);


int main(){

    FileParser parser("../ModelDataGenerator/data.dat");
    if (false == parser.init())
    {
        cout << "Failed to init parser" << endl;
	return -1;
    }
    auto & edges = parser.getEdges();
    auto & demands= parser.getDemands();
//    int numOfEdges = parser.getNumberOfEdges();
    int numOfNodes = parser.getNumberOfNodes();
//    int numOfDemands = parser.getNumberOfDemands();

    for_each(edges.begin(), edges.end(), [](pair<const int, Edge> & el){ cout << el.second.print(); });

    Graph g(numOfNodes);
    buildGraph(g, edges);

//    FlightList flightList;
//    buildFlightList(flightList, demands);


    for(auto demand = demands.begin(); demand != demands.end(); ++demand)
    {
        for(int ticket = 0; ticket < demand->peop; ++ticket)
	{
            g.bookTicket(demand->start, demand->dest);
	}
    } 
//    for(FlightList::iterator it = flightList.begin(); it != flightList.end(); ++it)
//    {
//        g.bookTicket(startNode, *it);
//    }
    return 0;

}

void buildGraph(Graph & g, map<int, Edge> & edges)
{
    for_each(edges.begin(), edges.end(), [&g](pair<const int, Edge> & p) 
		    { g.addEdgeDirectedWeight(p.second.s, p.second.t, p.second.ksi, p.second.ksi_p, p.second.capa); }); 

    g.initializeState();
}

//void buildFlightList(FlightList & flightList, std::vector<Demand> demands)
//{
//    for_each(demands.begin(), demands.end(), [&flightList](Demand & demand){ flightList.push_back(demand.dest); });
//}

