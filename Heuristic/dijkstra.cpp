#include <iostream>
#include <cstring>
#include <iomanip>

#include "dijkstra.h"

#define INT_MAX 0xffff

using namespace std;


Graph::Graph(int vertexCount) {
    this->vertexCount = vertexCount;

    this->key = new int[vertexCount];
    this->distance = new int[vertexCount];
    this->parent = new int[vertexCount];

    adjMatrix = new pair<Costs,int>*[vertexCount];
    for (int i = 0; i < vertexCount; i++) {
        adjMatrix[i] = new pair<Costs, int>[vertexCount];
           for (int j = 0; j < vertexCount; j++)
              adjMatrix[i][j] = make_pair(Costs(),0);
    }
}
Graph::~Graph() {
    for (int i = 0; i < vertexCount; i++)
         delete[] adjMatrix[i];
            delete[] adjMatrix;
}
void Graph::initializeState(){
    for(int i=0; i<this->vertexCount; i++){
        this->key[i] = 0; // 0=not in MST, 1=yes in MST
        this->distance[i]= INT_MAX; //initially distance is Max int
        this->parent[i] = -1;  // -1=no parent, else parent info
                               //
    }
}
void Graph::addEdgeDirectedWeight(int i, int j, int cost, int costPremium, int seats) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
        adjMatrix[i][j] = make_pair(Costs(cost, costPremium), seats);
    }
}
void Graph::removeEdgeUndirected(int i, int j) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
        adjMatrix[i][j] = make_pair(Costs(), 0);
        adjMatrix[j][i] = make_pair(Costs(), 0);
    }
}
int Graph::isEdge(int i, int j) {
    if (adjMatrix[i][j].second <= 0)
    {
//        cout<<"No more seats.\n";
        return 0;
    }
    else if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount)
    {
         return adjMatrix[i][j].first.regularCost;
    }
    else{
        cout<<"Invalid vertex number.\n";
        return 0;
    }
}
void Graph::display(){
    int  u,v; //vertex
    cout<<"Costs      ";
    for(u=0; u<vertexCount; u++){
        cout << setw(2) << u << " ";
    }
    for(u=0; u<vertexCount; u++) {
        cout << "\nNode[" << (char) (u+48) << "] -> ";
        for(v=0; v<vertexCount; ++v) {
            cout << setw(2) << adjMatrix[u][v].first.regularCost << " " ;
        }
    }
    cout<<"\n\nTickets    ";
    for(u=0; u<vertexCount; u++){
        cout << setw(2) << u << " ";
    }
    for(u=0; u<vertexCount; u++) {
        cout << "\nNode[" << (char) (u+48) << "] -> ";
        for(v=0; v<vertexCount; ++v) {
            cout << setw(2) << adjMatrix[u][v].second << " " ;
        }
    }
    cout << "\n\n";
}
void Graph::showBasicInfo(){
    for(int i=0; i<vertexCount; i++){
        cout<<"node: "<<i<<" Key: "<<key[i]
            <<" distance: "<<distance[i]<<" parent: "<<parent[i]<<"\n";
    }
}
int Graph::isAllKeyTrue(){
    for(int i=0; i<this->vertexCount; i++){
        if(this->key[i]==0)
            return 0; // not MST yet
    }
    return 1; // MST done

}
int Graph::findMinDistanceNode(){
    int minDistant=INT_MAX;
    int minDistantNode;

    for(int i=0; i<vertexCount; i++) {
        if(minDistant > this->distance[i] && this->key[i]==0)
        { //0 means that node is not in MST
            minDistantNode = i;
            minDistant = this->distance[i];
            //cout<<"min: "<<minDistantNode<<"\n";
        }
    }
    //cout<<"Min Distant Node: "<<minDistantNode<<" Cost: "<<minDistant<<"\n";
    return minDistantNode;
}
int Graph::bookTicket(int startNode, int destinationNode, bool premiumTicket)
{
    int ticketsCost = 0;
    display();
    Dijkstra(startNode, premiumTicket);

    deque<int> v = printPath(destinationNode);

    v.push_front(startNode);

    for(deque<int>::iterator it2 = v.begin(); (it2+1) < v.end(); ++it2)
    {
        //cout <<"To be decreased: " << *it2 << "->" << *(it2+1) << " Value : " << g.adjMatrix[*it2][*(it2+1)].second << endl;
        ticketsCost += adjMatrix[*it2][*(it2+1)].first.regularCost;
	if (premiumTicket)
	{
            ticketsCost += adjMatrix[*it2][*(it2+1)].first.premiumCost;
	}
        adjMatrix[*it2][*(it2+1)].second = adjMatrix[*it2][*(it2+1)].second - 1;
    }
    return ticketsCost;
}
deque<int> Graph::printPath(int j)
{
    // Base Case : If j is source
    if (parent[j]==-1)
    {
        return deque<int>();
    }

    cout << "Travel cost to Node:" << j << " is " << distance[j] << endl;

    deque<int> v = printPath(parent[j]);
    v.push_back(j);
    return v;
}
void Graph::Dijkstra(int startNode, bool premiumTicket){
    for(int i = 0; i < vertexCount; ++i) // not sure if needed
    {
        this->key[i] = 0;
        this->distance[i]= INT_MAX; //initially distance is Max int
        this->parent[i] = -1;  // -1=no parent, else parent info
    }
    cout<<"\nDijkstra Shortest Path starts . . . \n";

    // initialization is done before call this method
    this->distance[startNode]=0; //start node's distance is 0
    int minDistanceNode, i;

    // 0 means Shortest path calculation is not done yet.
    while(!this->isAllKeyTrue()){
        //cout<<"-------------------------------\n";
        minDistanceNode = findMinDistanceNode();
        this->key[minDistanceNode] = 1;  // this node's shortes path is done

//        cout<<"Shortest Path: "<<this->parent[minDistanceNode]<<"->"
//            <<minDistanceNode<<", Destination Node's cost is: "<<distance[minDistanceNode]<<"\n";


        for(i=0; i<vertexCount; i++){
            if(this->isEdge(minDistanceNode, i) && this->key[i]==0 ){
                //Below is the code for relaxation
		if(premiumTicket)
		{
                    if(this->distance[i] > this->distance[minDistanceNode]
                                           + adjMatrix[minDistanceNode][i].first.premiumCost){
                        this->distance[i] = this->distance[minDistanceNode]
                                            + adjMatrix[minDistanceNode][i].first.premiumCost;
                        this->parent[i] = minDistanceNode;
                    }
		}
		else
		{
                    if(this->distance[i] > this->distance[minDistanceNode]
                                           + adjMatrix[minDistanceNode][i].first.regularCost){
                        this->distance[i] = this->distance[minDistanceNode]
                                            + adjMatrix[minDistanceNode][i].first.regularCost;
                        this->parent[i] = minDistanceNode;
                    }
		}
            }
        }

        //this->showBasicInfo(); // To visualize more clearly
        // you can comment this to only show the edges of MST
    }

}



