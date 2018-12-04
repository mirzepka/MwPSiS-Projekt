#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <regex>
#include <cstdlib>

struct Edge
{
    int s;//start
    int t;//dest
    int ksi;//cost
    int ksi_p;//cost premium
    int capa;//capa
//Edge(int st, int dst, int ks, int cap):
    Edge(const Edge &) = default;
    Edge(int st, int dst, int ks, int ks_p, int cap):
	    s(st),
	    t(dst),
	    ksi(ks),
	    ksi_p(ks_p),
	    capa(cap)
	{}
    std::string print();
};
struct Demand
{
    int peop;
    int start;
    int dest;
    int prem;
    Demand():
	peop(0),
	start(0),
	dest(0),
	prem(0)
    {}
};

class FileParser
{
    std::string fileName;
    int V; 
    int E; 
    int D; 
    std::map<int, Edge> edges;
    std::vector<Demand> demands;
public:
    FileParser(std::string file);
    bool init();
    std::vector<Demand> & getDemands() { return demands;}
    std::map<int, Edge> & getEdges() { return edges; }
    int getNumberOfNodes() { return V;}
    int getNumberOfEdges() { return E;}
    int getNumberOfDemands() { return D;}
};

