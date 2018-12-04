#include "FileParser.h"
#include <iomanip>

using namespace std;

string Edge::print()
{
    stringstream ss;
    ss << "{source:" << setw(4) << s <<
	   "  |destin:" << setw(4) << t <<
	   "  |cost:"   << setw(4) << ksi <<
	   "  |costPrem:"   << setw(4) << ksi_p <<
	   "  |capa:"   << setw(4) << capa <<
	   "}" << endl;
    return ss.str();
}

FileParser::FileParser(string file):
    fileName(file)
{
    cout << "Parser constructed" << endl;
}

bool FileParser::init()
{
    stringstream buffer;
    string tmpStr, tmpStr2;

    ifstream file(fileName.c_str());
    if ( file.is_open() == false)
    {
	    cout << " Could not open file" << endl;
	    return false;
    }

    string line;
    //param V
    while(getline(file, line))
    {
        if (std::string::npos != line.find("V_count"))
        {
            cout << "param V found" << endl;
            std::regex rgx("_count := ([0-9]+)");
            std::smatch match;
        
            if (std::regex_search(line.cbegin(), line.cend(), match, rgx))
            {
       	        buffer << match[1];
       	        tmpStr = buffer.str();
                buffer.str("");
                V = atoi(tmpStr.c_str());
            }
            break;
        }
    }
    //param E
    while(getline(file, line))
    {
        if (std::string::npos != line.find("E_count"))
        {
            cout << "param E found" << endl;
            std::regex rgx("_count := ([0-9]+)");
            std::smatch match;
        
            if (std::regex_search(line.cbegin(), line.cend(), match, rgx))
            {
       	        buffer << match[1];
       	        tmpStr = buffer.str();
                buffer.str("");
                E = atoi(tmpStr.c_str());
            }
            break;
        }
    }
    //param D
    while(getline(file, line))
    {
        if (std::string::npos != line.find("D_count"))
        {
            cout << "param D found" << endl;
            std::regex rgx("_count := ([0-9]+)");
            std::smatch match;
        
            if (std::regex_search(line.cbegin(), line.cend(), match, rgx))
            {
       	        buffer << match[1];
       	        tmpStr = buffer.str();
                buffer.str("");
                D = atoi(tmpStr.c_str());
            }
            break;
        }
    }
    //param demands
    while(getline(file, line))
    {
        if (std::string::npos != line.find("param : h"))
        {
            cout << "param demands found" << endl;
            std::regex rgx("      ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+)");
            while(getline(file, line))
	    {
                if (std::string::npos != line.find(";"))
        	{
        	    break;
        	}
                std::smatch match;
        
		demands.push_back(Demand());
		Demand & dem = demands.back();
                if (std::regex_search(line.cbegin(), line.cend(), match, rgx))
                {
                    buffer << match[1];
                    tmpStr = buffer.str();
                    buffer.str("");
                    dem.peop = atoi(tmpStr.c_str());
                    buffer << match[2];
                    tmpStr = buffer.str();
                    buffer.str("");
                    dem.start = atoi(tmpStr.c_str()) - 1;
                    buffer << match[3];
                    tmpStr = buffer.str();
                    buffer.str("");
                    dem.dest = atoi(tmpStr.c_str()) - 1;
                    buffer << match[4];
                    tmpStr = buffer.str();
                    buffer.str("");
                    dem.prem = atoi(tmpStr.c_str());
                }
	    }
            break;
        }
    }
    //param A
    while(getline(file, line))
    {
        if (std::string::npos != line.find("param : A"))
        {
            cout << "param A found" << endl;
            break;
        }
    }
    while(getline(file, line))
    {
        if (std::string::npos != line.find(";"))
	{
	    break;
	}
        std::regex rgx("([0-9]+), ([0-9]+)    ([0-9]+)");
        std::smatch match;
    
        if (std::regex_search(line.cbegin(), line.cend(), match, rgx))
        {
	    buffer << match[1];
	    tmpStr = buffer.str();
	    buffer.str("");
	    buffer << match[2];
	    tmpStr2 = buffer.str();
	    buffer.str("");
            edges.emplace(atoi(tmpStr.c_str()), Edge(atoi(tmpStr2.c_str()) - 1, -1, -1, -1, -1));
        }
    }
    //param B
    while(getline(file, line))
    {
        if (std::string::npos != line.find("param : B"))
        {
            cout << "param B found" << endl;
            break;
        }
    }
    while(getline(file, line))
    {
        if (std::string::npos != line.find(";"))
	{
	    break;
	}
        std::regex rgx("([0-9]+), ([0-9]+)    ([0-9]+)");
        std::smatch match;
    
        if (std::regex_search(line.cbegin(), line.cend(), match, rgx))
        {
	    buffer << match[1];
	    tmpStr = buffer.str();
	    buffer.str("");
	    buffer << match[2];
	    tmpStr2 = buffer.str();
	    buffer.str("");

	    auto elem = edges.find(atoi(tmpStr.c_str()));
	    if ( elem != edges.end() )
	    {
                elem->second.t = atoi(tmpStr2.c_str()) - 1;
	    }
	    else
	    {
                cout << "Param B: link not found for id:" + tmpStr;
	    }	
        }
    }

    //KSI
    while(getline(file, line))
    {
        if (std::string::npos != line.find("param : KSI"))
        {
            cout << "param KSI found" << endl;
            break;
        }
    }
    while(getline(file, line))
    {
        if (std::string::npos != line.find(";"))
	{
	    break;
	}
        std::regex rgx("([0-9]+)      ([0-9]+)");
        std::smatch match;
    
        if (std::regex_search(line.cbegin(), line.cend(), match, rgx))
        {
	    buffer << match[1];
	    tmpStr = buffer.str();
	    buffer.str("");
	    buffer << match[2];
	    tmpStr2 = buffer.str();
	    buffer.str("");

	    auto elem = edges.find(atoi(tmpStr.c_str()));
	    if ( elem != edges.end() )
	    {
                elem->second.ksi = atoi(tmpStr2.c_str());
	    }
	    else
	    {
                cout << "Param KSI: link not found for id:" + tmpStr;
	    }	
        }
    }
    //KSI_P
    while(getline(file, line))
    {
        if (std::string::npos != line.find("param : KSI_P"))
        {
            cout << "param KSI_P found" << endl;
            break;
        }
    }
    while(getline(file, line))
    {
        if (std::string::npos != line.find(";"))
	{
	    break;
	}
        std::regex rgx("([0-9]+)      ([0-9]+)");
        std::smatch match;
    
        if (std::regex_search(line.cbegin(), line.cend(), match, rgx))
        {
	    buffer << match[1];
	    tmpStr = buffer.str();
	    buffer.str("");
	    buffer << match[2];
	    tmpStr2 = buffer.str();
	    buffer.str("");

	    auto elem = edges.find(atoi(tmpStr.c_str()));
	    if ( elem != edges.end() )
	    {
                elem->second.ksi_p = atoi(tmpStr2.c_str());
	    }
	    else
	    {
                cout << "Param KSI_P: link not found for id:" + tmpStr;
	    }	
        }
    }
    //Cost
    while(getline(file, line))
    {
        if (std::string::npos != line.find("param : c"))
        {
            cout << "param c found" << endl;
            break;
        }
    }
    while(getline(file, line))
    {
        if (std::string::npos != line.find(";"))
	{
	    break;
	}
        std::regex rgx("([0-9]+)      ([0-9]+)");
        std::smatch match;
    
        if (std::regex_search(line.cbegin(), line.cend(), match, rgx))
        {
	    buffer << match[1];
	    tmpStr = buffer.str();
	    buffer.str("");
	    buffer << match[2];
	    tmpStr2 = buffer.str();
	    buffer.str("");

	    auto elem = edges.find(atoi(tmpStr.c_str()));
	    if ( elem != edges.end() )
	    {
                elem->second.capa = atoi(tmpStr2.c_str());
	    }
	    else
	    {
                cout << "Param Capacity: link not found for id:" + tmpStr;
	    }	
        }
    }
    return true;
}    

