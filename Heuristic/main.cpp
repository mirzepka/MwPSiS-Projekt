#include <iostream>
#include <vector>
#include "dijkstra.h"
#include "FileParser.h"

using namespace std;

typedef vector<int> FlightList;

void buildGraph(Graph & g, std::map<int, Edge> & edges);


int main(int argc, char** argv)
{
    FileParser parser("../ModelDataGenerator/data.dat");

    if(argc > 1)
        parser = string(argv[1]);

    if (false == parser.init())
    {
        cout << "Failed to init parser" << endl;
	return -1;
    }
    auto & edges = parser.getEdges();
    auto & demands= parser.getDemands();
    int numOfNodes = parser.getNumberOfNodes();

    for_each(edges.begin(), edges.end(), [](pair<const int, Edge> & el){ cout << el.second.print(); });

    Graph g(numOfNodes);
    buildGraph(g, edges);



    int totalCost = 0;
    for(auto demand = demands.begin(); demand != demands.end(); ++demand)
    {
        for(int ticket = 0; ticket < demand->peop; ++ticket)
	{
            int re = g.bookTicket(demand->start, demand->dest, ticket < demand->prem);
	    if (re == 0xffff)
	    {
                cout << "Forced to quit!" << endl;
		return 0;
	    }
	    cout<<"TicketsCosts: "<< re<< endl;
	    totalCost += re;
	}
    } 
    cout << endl << "FINAL_LOG:Heuristic:" << endl;
    cout << "FINAL_LOG:TotalCost: " << totalCost << endl;

    return 0;

}

void buildGraph(Graph & g, map<int, Edge> & edges)
{
    for_each(edges.begin(), edges.end(), [&g](pair<const int, Edge> & p) 
		    { g.addEdgeDirectedWeight(p.second.s, p.second.t, p.second.ksi, p.second.ksi_p, p.second.capa); }); 

    g.initializeState();
}

