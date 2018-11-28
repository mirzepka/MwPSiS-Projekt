#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
    int R = 4;
    if(argc > 1)
        R = atoi(argv[1]);
    
    int edgeNum = 1;
    cout << "Gen: " << R << "x" << R << endl << endl;

    cout << "data;" << endl << endl;
    cout << "param V_count := " << R*R << ";" << endl;
    cout << "param E_count := " << 3*(R-1)*(R-1) << ";" << endl;
    cout << "param D_count := 2" << endl;

    cout << "param : h  s t := " << endl;
    cout << " 1      50 1 " << R*R << endl;
    cout << endl;

    edgeNum = 1;
    cout << "param : A :=" << endl;
    for(int y = 0; y<(R-1); ++y)
    {
        for(int x = 0; x<(R-1); ++x)
        {
            cout << " " << edgeNum++ << ", " << y*R+(x+1) << "    1" << endl;
            cout << " " << edgeNum++ << ", " << y*R+(x+1) << "    1" << endl;
            cout << " " << edgeNum++ << ", " << y*R+(x+1) << "    1" << endl;
        }
    }
    cout << ";" << endl;

    edgeNum = 1;
    cout << "param : B :=" << endl;
    for(int y = 0; y<(R-1); ++y)
    {
        for(int x = 0; x<(R-1); ++x)
        {
            cout << " " << edgeNum++ << ", " << y*R+(x+1)+1 << "    1" << endl;
            cout << " " << edgeNum++ << ", " << (y+1)*R+(x+1)+1 << "    1" << endl;
            cout << " " << edgeNum++ << ", " << (y+1)*R+(x+1) << "    1" << endl;
        }
    }
    cout << ";" << endl;

    edgeNum = 1;
    cout << "param : KSI :=" << endl;
    for(int y = 0; y<(R-1); ++y)
    {
        for(int x = 0; x<(R-1); ++x)
        {
            cout << " " << edgeNum++ << "      20" << endl;
            cout << " " << edgeNum++ << "      20" << endl;
            cout << " " << edgeNum++ << "      20" << endl;
        }
    }
    cout << ";" << endl;

    edgeNum = 1;
    cout << "param : c :=" << endl;
    for(int y = 0; y<(R-1); ++y)
    {
        for(int x = 0; x<(R-1); ++x)
        {
            cout << " " << edgeNum++ << "      40" << endl;
            cout << " " << edgeNum++ << "      40" << endl;
            cout << " " << edgeNum++ << "      40" << endl;
        }
    }
    cout << ";" << endl;
    cout << "end;" << endl;

    return 0;
}

