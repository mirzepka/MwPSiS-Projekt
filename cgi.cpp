#include <iostream>
#include <vector>
#include <string>

#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace cgicc;   

int main(int argc, char **argv)
{
    try {
       Cgicc formData;

       cout << HTTPHTMLHeader() << endl;

       cout << HTMLDoctype(HTMLDoctype::eStrict) << endl;

       // Print: <html lang="en" dir="LTR">
       cout << html().set("lang", "EN").set("dir", "LTR") << endl;

       // Set up the HTML document
       cout << html() << head() << title("Cgicc example") << head() << endl;
       cout << body().set("bgcolor","#cccccc").set("text","#000000").set("link","#0000ff").set("vlink","#000080") << endl;

       cout << h1("Rezultaty symulacji") << endl;

       form_iterator fvalue1 = formData.getElement("value1");
       if( !fvalue1->isEmpty() && fvalue1 != (*formData).end()) {
	  string command = "/home/mi/Desktop/mpsis/MwPSiS-Projekt/setup.sh";
	  command = command + " "  + **fvalue1;
	  system(command.c_str());
       }
       else
          cout << "No text entered for value1" << endl;

       cout << p();


       // Close the HTML document
       cout << body() << html();
    }
    catch(exception& e) {
       // handle any errors here.
       cout << "ERROR!!" << endl;
    }
    return 0;   // To avoid Apache errors.
}
      
