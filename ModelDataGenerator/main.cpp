#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
    int R = 4;
    if(argc > 1)
        R = atoi(argv[1]);
    
    int edgeNum = 1;
    cout << "Gen: " << R << "x" << R << endl << endl;

    ofstream file;
    file.open ("data.dat");

    file << "data;" << endl << endl;
    file << "param V_count := " << R*R << ";" << endl;
    file << "param E_count := " << 3*(R-1)*(R-1) << ";" << endl;
    file << "param D_count := 2" << endl;

    file << "param : h  s t := " << endl;
    file << " 1      50 1 " << R*R << endl;
    file << endl;

    edgeNum = 1;
    file << "param : A :=" << endl;
    for(int y = 0; y<(R-1); ++y)
    {
        for(int x = 0; x<(R-1); ++x)
        {
            file << " " << edgeNum++ << ", " << y*R+(x+1) << "    1" << endl;
            file << " " << edgeNum++ << ", " << y*R+(x+1) << "    1" << endl;
            file << " " << edgeNum++ << ", " << y*R+(x+1) << "    1" << endl;
        }
    }
    file << ";" << endl;

    edgeNum = 1;
    file << "param : B :=" << endl;
    for(int y = 0; y<(R-1); ++y)
    {
        for(int x = 0; x<(R-1); ++x)
        {
            file << " " << edgeNum++ << ", " << y*R+(x+1)+1 << "    1" << endl;
            file << " " << edgeNum++ << ", " << (y+1)*R+(x+1)+1 << "    1" << endl;
            file << " " << edgeNum++ << ", " << (y+1)*R+(x+1) << "    1" << endl;
        }
    }
    file << ";" << endl;

    edgeNum = 1;
    file << "param : KSI :=" << endl;
    for(int y = 0; y<(R-1); ++y)
    {
        for(int x = 0; x<(R-1); ++x)
        {
            file << " " << edgeNum++ << "      20" << endl;
            file << " " << edgeNum++ << "      20" << endl;
            file << " " << edgeNum++ << "      20" << endl;
        }
    }
    file << ";" << endl;

    edgeNum = 1;
    file << "param : c :=" << endl;
    for(int y = 0; y<(R-1); ++y)
    {
        for(int x = 0; x<(R-1); ++x)
        {
            file << " " << edgeNum++ << "      40" << endl;
            file << " " << edgeNum++ << "      40" << endl;
            file << " " << edgeNum++ << "      40" << endl;
        }
    }
    file << ";" << endl;
    file << "end;" << endl;

    file.close();

    return 0;
}

