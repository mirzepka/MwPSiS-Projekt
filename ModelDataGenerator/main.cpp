#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
    int R = 4;
    if(argc > 1)
        R = atoi(argv[1]);
    
    int edgeNum = 2*3*(R-1)*(R-1) + 2*2*(R-1);
    int edgeIt = 1;
    cout << "Gen: " << R << "x" << R << endl << endl;

    ofstream file;
    file.open ("data.dat");

    file << "data;" << endl << endl;
    file << "param V_count := " << R*R << ";" << endl;
    file << "param E_count := " << edgeNum << ";" << endl;
    file << "param D_count := 1;" << endl;

    file << "param : h  s t b := " << endl;
    file << " 1      2 1 4 1" << endl;
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

    edgeIt = 1;
    file << "param : KSI :=" << endl;
    for(int y = 0; y<R; ++y)
    {
        for(int x = 0; x<R; ++x)
        {
	    if ( x < R-1 )
	    {	    
            	file << " " << edgeIt++ << "      20" << endl;
            	file << " " << edgeIt++ << "      20" << endl;
	    }
	    if ( x < R-1 && y < R-1 )
	    {	    
            	file << " " << edgeIt++ << "      20" << endl;
            	file << " " << edgeIt++ << "      20" << endl;
	    }
	    if ( y < R-1 )
	    {	    
            	file << " " << edgeIt++ << "      20" << endl;
            	file << " " << edgeIt++ << "      20" << endl;
	    }
        }
    }
    file << ";" << endl;
    edgeIt = 1;

    file << "param : KSI_P :=" << endl;
    for(int y = 0; y<R; ++y)
    {
        for(int x = 0; x<R; ++x)
        {
	    if ( x < R-1 )
	    {	    
            	file << " " << edgeIt++ << "      50" << endl;
            	file << " " << edgeIt++ << "      50" << endl;
	    }
	    if ( x < R-1 && y < R-1 )
	    {	    
            	file << " " << edgeIt++ << "      50" << endl;
            	file << " " << edgeIt++ << "      50" << endl;
	    }
	    if ( y < R-1 )
	    {	    
            	file << " " << edgeIt++ << "      50" << endl;
            	file << " " << edgeIt++ << "      50" << endl;
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
            	file << " " << edgeIt++ << "      1" << endl;
            	file << " " << edgeIt++ << "      1" << endl;
	    }
	    if ( x < R-1 && y < R-1 )
	    {	    
            	file << " " << edgeIt++ << "      1" << endl;
            	file << " " << edgeIt++ << "      1" << endl;
	    }
	    if ( y < R-1 )
	    {	    
            	file << " " << edgeIt++ << "      1" << endl;
            	file << " " << edgeIt++ << "      1" << endl;
	    }
        }
    }
    file << ";" << endl;
    file << "end;" << endl;

    file.close();

    return 0;
}

