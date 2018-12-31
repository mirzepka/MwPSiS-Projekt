#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>
#include <set>

using namespace std;

int main(int argc, char** argv)
{
    int R = 4;
    if(argc > 1)
        R = atoi(argv[1]);

    int edgeNum = 2*3*(R-1)*(R-1) + 2*2*(R-1);
    int edgeIt = 1;
    int demNum = R;
    int nodeNum = R * R;
    set<int> targetNodes;
    std::default_random_engine rng(std::random_device{}()); 
    std::uniform_int_distribution<int> dist(2, nodeNum);

    while(targetNodes.size() < demNum)
    {
        targetNodes.insert(dist(rng));
    }


    cout << "Gen: " << R << "x" << R << endl << endl;

    ofstream file;
    file.open ("data.dat");

    file << "data;" << endl << endl;
    file << "param V_count := " << nodeNum << ";" << endl;
    file << "param E_count := " << edgeNum << ";" << endl;
    file << "param D_count := " << demNum << ";" << endl;

    file << "param : h  s t b := " << endl;

    int idx = 1;
    for(auto target : targetNodes)
    {
        file << " " << idx++ << "      2 1 " << target<< " 1" << endl;
    }
    file << ";" << endl;

    edgeIt = 1;
    file << "param : A :=" << endl;
    for(int y = 0; y<R; ++y)
    {
        for(int x = 0; x<R; ++x)
        {
	    if ( x < R-1 )
	    {	    
                file << " " << edgeIt++ << ", " << y*R+(x+1) << "    1" << endl;
            	file << " " << edgeIt++ << ", " << y*R+(x+1)+1 << "    1" << endl;
	    }
	    if ( x < R-1 && y < R-1 )
	    {	    
            	file << " " << edgeIt++ << ", " << y*R+(x+1) << "    1" << endl;
            	file << " " << edgeIt++ << ", " << (y+1)*R+(x+1)+1 << "    1" << endl;
	    }
	    if ( y < R-1 )
	    {	    
            	file << " " << edgeIt++ << ", " << y*R+(x+1) << "    1" << endl;
            	file << " " << edgeIt++ << ", " << (y+1)*R+(x+1) << "    1" << endl;
	    }
        }
    }
    file << ";" << endl;

    edgeIt = 1;
    file << "param : B :=" << endl;
    for(int y = 0; y<R; ++y)
    {
        for(int x = 0; x<R; ++x)
        {
	    if ( x < R-1 )
	    {	    
            	file << " " << edgeIt++ << ", " << y*R+(x+1)+1 << "    1" << endl;
                file << " " << edgeIt++ << ", " << y*R+(x+1) << "    1" << endl;
	    }
	    if ( x < R-1 && y < R-1 )
	    {	    
            	file << " " << edgeIt++ << ", " << (y+1)*R+(x+1)+1 << "    1" << endl;
            	file << " " << edgeIt++ << ", " << y*R+(x+1) << "    1" << endl;
	    }
	    if ( y < R-1 )
	    {	    
            	file << " " << edgeIt++ << ", " << (y+1)*R+(x+1) << "    1" << endl;
            	file << " " << edgeIt++ << ", " << y*R+(x+1) << "    1" << endl;
	    }
        }
    }
    file << ";" << endl;

    std::default_random_engine costRng(std::random_device{}()); 
    std::uniform_int_distribution<int> costDist(10, 100);
    edgeIt = 1;
    file << "param : KSI :=" << endl;
    for(int y = 0; y<R; ++y)
    {
        for(int x = 0; x<R; ++x)
        {
	    if ( x < R-1 )
	    {	    
            	file << " " << edgeIt++ << "      " << costDist(costRng) << endl;
            	file << " " << edgeIt++ << "      " << costDist(costRng) << endl;
	    }
	    if ( x < R-1 && y < R-1 )
	    {	    
            	file << " " << edgeIt++ << "      " << costDist(costRng) << endl;
            	file << " " << edgeIt++ << "      " << costDist(costRng) << endl;
	    }
	    if ( y < R-1 )
	    {	    
            	file << " " << edgeIt++ << "      " << costDist(costRng) << endl;
            	file << " " << edgeIt++ << "      " << costDist(costRng) << endl;
	    }
        }
    }
    file << ";" << endl;

    std::default_random_engine costPRng(std::random_device{}()); 
    std::uniform_int_distribution<int> costPDist(100, 200);
    edgeIt = 1;
    file << "param : KSI_P :=" << endl;
    for(int y = 0; y<R; ++y)
    {
        for(int x = 0; x<R; ++x)
        {
	    if ( x < R-1 )
	    {	    
            	file << " " << edgeIt++ << "      " << costPDist(costPRng) << endl;
            	file << " " << edgeIt++ << "      " << costPDist(costPRng) << endl;
	    }
	    if ( x < R-1 && y < R-1 )
	    {	    
            	file << " " << edgeIt++ << "      " << costPDist(costPRng) << endl;
            	file << " " << edgeIt++ << "      " << costPDist(costPRng) << endl;
	    }
	    if ( y < R-1 )
	    {	    
            	file << " " << edgeIt++ << "      " << costPDist(costPRng) << endl;
            	file << " " << edgeIt++ << "      " << costPDist(costPRng) << endl;
	    }
        }
    }
    file << ";" << endl;

    edgeIt = 1;
    file << "param : c :=" << endl;
    for(int y = 0; y<R; ++y)
    {
        for(int x = 0; x<R; ++x)
        {
	    if ( x < R-1 )
	    {	    
            	file << " " << edgeIt++ << "      " << 2 * demNum << endl;
            	file << " " << edgeIt++ << "      " << 2 * demNum << endl;
	    }
	    if ( x < R-1 && y < R-1 )
	    {	    
            	file << " " << edgeIt++ << "      " << 2 * demNum << endl;
            	file << " " << edgeIt++ << "      " << 2 * demNum << endl;
	    }
	    if ( y < R-1 )
	    {	    
            	file << " " << edgeIt++ << "      " << 2 * demNum << endl;
            	file << " " << edgeIt++ << "      " << 2 * demNum << endl;
	    }
        }
    }
    file << ";" << endl;
    file << "end;" << endl;

    file.close();

    return 0;
}

