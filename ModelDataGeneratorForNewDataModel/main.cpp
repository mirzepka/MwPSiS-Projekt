#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>  

using namespace std;

int main(int argc, char** argv)
{
 srand (time(NULL));
    int R = 4;
    int U = 5;
    if(argc > 1)
        R = atoi(argv[1]);
    if(argc>2)
	U=atoi(argv[2]);
    ofstream outputFile;
	outputFile.open ("../../../prog.dat");
    int edgeNum = 1;

    outputFile << "data;" << endl << endl;
    outputFile << "param V_count := " << R << ";" << endl;
    outputFile << "param E_count := " << R*R-R << ";" << endl;
    outputFile << "param D_count := "<<U<<";" << endl;

    outputFile << "param : h  s t b := " << endl;
    for(int ind=0;ind<U;ind++){
    outputFile << " "<<ind+1<<"     "<<rand()%10+1<<" "<<rand()%(R)+1<<" "<<rand()%(R)+1<<" "<<rand()%(U/2)+1<<endl;
    }
    outputFile <<";"<< endl;

    edgeNum = 1;
    outputFile << "param : A :=" << endl;
    for(int y = 1; y<(R+1); ++y)
    {
        for(int x = 1; x<(R); ++x)
        {
            outputFile  << " " << edgeNum++ << ", " << y << "    1" << endl;
        }
    }
    outputFile << ";" << endl;

    edgeNum = 1;
    outputFile << "param : B :=" << endl;
    for(int y = 1; y<(R+1); ++y)
    {
        for(int x = 1; x<(R+1); ++x)
        {
	if(x!=y){
            outputFile << " " << edgeNum++ << ", " << x << "    1" << endl;
	}
        }
    }
    outputFile << ";" << endl;

    edgeNum = 1;
    outputFile << "param : K :=" << endl;
    for(int y = 0; y<(R); ++y)
    {
        for(int x = 0; x<(R-1); ++x)
        {
            outputFile << " " << edgeNum++ << "      "<<(rand() % 50 + 1) << endl;

        }
    }
    outputFile << ";" << endl;

    edgeNum = 1;
    outputFile << "param : KP :=" << endl;
    for(int y = 0; y<(R); ++y)
    {
        for(int x = 0; x<(R-1); ++x)
        {
            outputFile << " " << edgeNum++ << "      "<<(rand() % 50 + 1) << endl;
        }
    }
    outputFile << ";" << endl;
    edgeNum = 1;
    outputFile << "param : c :=" << endl;
    for(int y = 0; y<(R); ++y)
    {
        for(int x = 0; x<(R-1); ++x)
        {
            outputFile << " " << edgeNum++ << "      "<<(rand() % 50 + 1)  << endl;

        }
    }
    outputFile << ";" << endl;
    outputFile << "end;" << endl;
    outputFile.close();
    return 0;
}

